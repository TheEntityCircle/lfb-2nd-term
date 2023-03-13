#include <iostream>
#include "../01_gk/general.hpp"
#include "../01_gk/kenobi.hpp"

int main()
{
    for (int i = 0; i < 100; i++)
    {
        std::cout << "Hello there." << std::endl;
        general();
        kenobi();
    }
    return 0;
}
