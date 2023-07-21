#include<stdio.h>
#include<fcntl.h>


int main(int argc , char *argv[])
{
	int fd = 0;

	fd = open(argv[1], O_RDONLY);

	if(fd == -1)
	{
		printf("unable to open file \n");
		return -1;
	}
	else
	{
		printf("File open Successfuly \n");
	}

	return 0;
}
