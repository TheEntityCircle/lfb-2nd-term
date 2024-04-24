#include <iostream>
#include <thread>
#include <chrono>
#include <utility>
#include <atomic>

std::atomic<int> n(0);
 
void f1()
{
    for (int i = 0; i < 50; ++i)
    {
        std::cout << "Thread 1 executing\n";
        n += 1;
    }
}
 
void f2(int x)
{
    for (int i = 0; i < 50; ++i)
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

    // Смотрим, что получилось в глобальной переменной.
    std::cout << "Final value of n is " << n << '\n';
    return 0;
}

