#include <unistd.h>
#include <fcntl.h>
int     main(int argc, char *argv[])
{
        int fd;
        char buf[2147483647];
        char *str;
        char *num;
        int i;
        if (argc == 2)
        {
                num = argv[1];
                fd = open("numbers.dict", O_RDONLY);
                if(fd == -1)
                {
                        write(1, "Dict Error\n", 11);
                        return (0);
                }
                read(fd, buf, sizeof(buf));
                close(fd);
        }
        else if (argc == 3)
        {
                str = argv[1];
                num = argv[2];
                fd = open(str, O_RDONLY);
                if (fd == -1)
                {
                        write(1, "Dict Error\n", 6);
                        return (0);
                }
                read(fd, buf, sizeof(buf));
                close(fd);
        }
        else
        {
                write(1, "Error\n", 6);
                return (0);
        }
        i = 0;
        while (num[i] != '\0')
        {
                if (!(num[i] >= '0' && num[i] <='9'))
                {
                        write (1, "Error\n", 6);
                        return (0);
                }
                i++;
        }
        return (1);
}
