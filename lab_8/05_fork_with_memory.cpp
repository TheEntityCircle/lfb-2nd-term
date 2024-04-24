#include <iostream>
#include <fstream>
#include <unistd.h>


long int array[200000000] = {0};

int main()
{
    for (unsigned long int i = 0; i < 200000000; i++)
        array[i] = i;

    std::cout << "firstly, we are here: " << getpid() << std::endl;

    // Вначале проверьте, сколько памяти отъедает один процесс.
    // Потом верните раздвоение и снова проверьте.
    pid_t pid = 0;
    // pid_t pid = fork(); 

    if (pid) // мы в родительском процессе
    {
        int a;
        std::cout << "we are in " << getpid() << " and fork returned " << pid << std::endl;

        // (1/2)
        // Блок для проверки того, что у в разных процессах и правда независимые массивы.
        // for (unsigned long int i = 0; i < 200000000; i++)
        //    array[i] = 2*i;

        std::cin >> a;
    }
    else    // мы в дочернем процесса
    {
        int a;
        std::cout << "we are in " << getpid() << " and fork returned " << pid << std::endl;
        std::cin >> a;

        // (2/2)
        // Вторая часть блока проверки - вывод.
        // std::cout << getpid() << " i " << a << " " << array[a] << std::endl;
    }

    return 0;
}
