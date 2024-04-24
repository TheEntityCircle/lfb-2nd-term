#include <iostream>
#include <fstream>
#include <unistd.h>

int main()
{
    std::ofstream os("1.txt", std::ios::app);

    // А теперь то же самое, но выводим сам pid.
    auto pid = getpid();
    os << pid << std::endl;

    int a;
    std::cin >> a;

    os << a << std::endl;

    return 0;
}
