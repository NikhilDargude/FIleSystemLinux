#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>


int main(int argc , char *argv[])
{
	int mode = 0;

	if(argc  != 3)
	{
		printf("Insufficient argument\n");
		return -1;
	}

	if(strcmp(argv[2], "write") == 0 )
	{
		mode = R_OK;
	}
	else if(strcmp(argv[2], "read") == 0)
	{
		mode = W_OK;
	}
	else if(strcmp(argv[2], "execute"))
	{
		mode = X_OK;
	}

	if(access(argv[1], mode) < 0)
	{
		printf("Unable to access %s file in %s mode", argv[1], argv[2]);
	}
	else
	{
		printf("you can access %s file in %s mode", argv[1], argv[2]);
	}

	return 0;

}