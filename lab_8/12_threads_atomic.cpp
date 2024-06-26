#include <iostream>
#include <thread>
#include <atomic>
#include <utility>

// Это теперь не просто int! Это int со встроенной синхронизацией.
std::atomic<int> n(0);
 
void f1()
{
    for (int i = 0; i < 5; ++i)
    {
        std::cout << "Thread 1 executing\n";

        // Сделать просто n += 1 на обычном int-е недостаточно!
        // Так можно, только если переменная является atomic-ом.
        // Почему? Потому что второй поток может вмешаться между чтением старого n и записью нового n.
        // Это будет как в прошлом примере, только временное окно очень маленькое.
        // Поэтому словить проблему очень маловероятно. Но возможно.
        // Тем сложнее отлаживать, когда оно случается один раз на миллион запусков.
        // И тем страшнее будут последствия, когда это однажды внезапно случится где-нибудь в проде.
        // n += 1;

        n += 1;
    }
}
 
void f2(int x)
{
    for (int i = 0; i < 5; ++i)
    {
        std::cout << "Thread 2 executing\n";
        n += x;
    }
}
 
int main()
{
    // Отделяется первый тред и выполняет переданную ему функцию.
    std::thread t1(f1);
    // Отделяется второй тред и выполняет переданную ему функцию, передав в неё аргумент.
    std::thread t2(f2, 3); 

    // А это синхронизация.
    // Ждём, пока тред t1 не закончит работу.
    t1.join();
    // Ждём, пока тред t2 не закончит работу.
    t2.join();

    // Вот теперь будет хорошо.
    std::cout << "Final value of n is " << n << '\n';
    return 0;
}

