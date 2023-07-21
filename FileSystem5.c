#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>


int main(int argc, char * argv[])
{
	int fd = 0;
	int numbyt = 0;
	int iRet = 0;
	char buffe[1024];


	if(argc != 2)
	{
		printf("Insufficient Argument\n");
		return -1;
	}

	printf("Enter Number of byte you wont to read\n");
	scanf("%d",&numbyt);

	fd = open(argv[1], O_RDONLY);

	if(fd == -1)
	{
		printf("File is not open \n");
		return -1;
	}

	iRet = read(fd, &buffe, numbyt);

	if(iRet == -1)
	{
		printf("Unable to Read File\n");
		return -1;
	}

	printf("Reding Byet of %s: \n", buffe);



	return 0;
}
