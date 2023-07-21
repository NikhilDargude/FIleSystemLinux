#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>



int main(int argc, char *argv[])
{
	int fd = 0;
	int iRet = 0;
	char Buffer[1024] =  {'\0'};

	if(argc != 2)
	{
		printf("Insufficient Argument\n");
		return -1;
	}

	fd = open(argv[1], O_RDONLY);

	if(fd == -1)
	{
		printf("Unable to open file\n");
		return -1;
	}

	while((iRet = read(fd,&Buffer, sizeof(Buffer))) == 0)
		;

		printf("read data is: %s\n", Buffer);


	close(fd);

	return 0;
}