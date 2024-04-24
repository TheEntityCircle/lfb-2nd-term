#include <iostream>
#include <fstream>
#include <unistd.h>
#include <fcntl.h> 
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
    std::cout << "firstly, we are here: " << getpid() << std::endl;
    int ret = mkfifo("pipe.txt", 0666);

    pid_t pid = fork(); 

    if (pid) // мы в родительском процессе
    {
        int fd = open("pipe.txt", O_WRONLY);
        for (int i = 0; i < 5; i++)
        {
            printf("Process %d: Write %d.\n", getpid(), i);
            ret = write(fd, &i, sizeof(i));
            sleep(0.1);
        }
        close(fd);
    }
    else    // мы в дочернем процесса
    {
        int fd = open("pipe.txt", O_RDONLY);
        for (int i = 0; i < 5; i++)
        {
            int msg;
            ret = read(fd, &msg, sizeof(msg));
            printf("Process %d: Received value %d from the parent process.\n", getpid(), msg);
            sleep(0.1);
        }
        close(fd);
    }

    return 0;
}
