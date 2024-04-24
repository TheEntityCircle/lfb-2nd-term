#include <iostream>
#include <fstream>
#include <unistd.h>


int main()
{
    std::cout << "firstly, we are here: " << getpid() << std::endl;

    // Здесь ваш процесс разделится на два.
    // Это немного выносит мозг, но после форка
    // один и тот же набор инструкций будет выполняться 
    // разными процессами.
    // Обратно в родительский процесс форк вернет pid дочернего.
    // В дочерний вернется 0.
    pid_t pid = fork(); 

    if (pid) // мы в родительском процессе
    {
        int a;
        std::cout << "we are in " << getpid() << " and fork returned " << pid << std::endl;
        std::cin >> a;
    }
    else    // мы в дочернем процесса
    {
        int a;
        std::cout << "we are in " << getpid() << " and fork returned " << pid << std::endl;
        std::cin >> a;
    }

    return 0;
}
