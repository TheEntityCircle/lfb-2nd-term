#include <iostream>
#include <thread>
#include <chrono>
#include <utility>

// Это пример плохого кода с иллюстрацией проблемы.
// Не надо так писать.

int n = 0;
 
void f1()
{
    int res = n;

    // Делаем вид, что тред чем-то занят.
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    for (int i = 0; i < 5; ++i)
    {
        std::cout << "Thread 1 executing\n";
        res += 1;
    }
    n = res;
}
 
void f2(int x)
{
    int res = n;

    // И этот тред тоже занят, но в 10 раз меньше.
    // Можете посмотреть, что будет если поменять длины sleep-ов местами.
    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    for (int i = 0; i < 5; ++i)
    {
        std::cout << "Thread 2 executing\n";
        res += x;
    }
    n = res;
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

    // Смотрим, что получилось в глобальной переменной.
    std::cout << "Final value of n is " << n << '\n';
    return 0;
}

