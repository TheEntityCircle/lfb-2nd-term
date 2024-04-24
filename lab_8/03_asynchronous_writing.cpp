#include <iostream>
#include <fstream>
#include <unistd.h>

int main()
{
    std::ofstream os("1.txt", std::ios::app);
    auto pid = getpid();
 
    for (int i = 0; i < 1000000; i++);

    for (int i = 0; i < 10; i++)
        os << pid << " " << i << std::endl;

    return 0;
}
