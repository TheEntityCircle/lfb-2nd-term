#include <iostream>
#include <thread>
#include <utility>

int *p = nullptr;
 
void f1()
{
    for (int i = 0; i < 10; i++)
    {
        p[i] += 1;
    }
}
 
void f2(int x)
{
    for (int i = 0; i < 10; i++)
    {
        p[i] += x;
    }
}
 
int main()
{
    p = new int[10];
    for (int i = 0; i < 10; i++)
    {
        p[i] = 0;
    }

    std::thread t1(f1);
    std::thread t2(f2, 3); 

    t1.join();
    t2.join();

    // Убеждаемся, что все потоки работали с одним и тем же массивом в куче.
    for (int i = 0; i < 10; i++)
        std::cout << p[i] << ' ';
    std::cout << std::endl;

    delete[] p;
    return 0;
}
