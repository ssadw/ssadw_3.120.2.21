#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int fd;
	size_t size;
	//Создаем символьный массив, где будет храниться имя файла FIFO
	char name[] = "fifo.fifo";
	//после первого запуска программы необходимо закомментировать процесс создания файла FIFO
/*	if (mknod(name, S_IFIFO | 0666, 0) < 0)
	{
		printf("Не удалось создать файл FIFO\n");
		exit(-1);
	}
*/
	//Процесс-родитель пишет информацию в FIFO
		if((fd = open(name, O_WRONLY)) < 0)
		{
			printf("Не удалось открыть файл на запись\n");
			exit(-1);
		}
		size = write(fd, "Hello, all!", 11);
		if (size != 11)
		{
			printf("Не получилось записать 11 байт в FIFO\n");
			exit(-1);
		}
		if (close(fd) < 0)
		{
			printf("Не получилось закрыть FIFO\n");
			exit(-1);
		}
		printf("Процесс-родитель записал информацию в FIFO и завершил работу\n");

	return 0;
}
