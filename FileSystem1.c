#include<stdio.h>
#include<fcntl.h>
#include<string.h>

int main(int argc, char *argv[])
{
	char Fmode[10];
	char Fname[20];
	int mode = 0;
	int fd  = 0;



	printf("Enter file name : \n");
	scanf("%s", Fname);

	printf("Choose Mode Read / Write : \n");

	printf("Enter file mode to open file : \n");
	scanf("%s", Fmode);

	printf("%s", Fmode);


	if(strcmp(Fmode, "Read") == 0)
	{
		mode = O_RDONLY;
	}
	else if(strcmp(Fmode, "Write") == 0)
	{
		mode = O_WRONLY;
	}
	else
	{
		printf("Please Enter you File mode\n");
		return -1;
	}
	

	fd = open(Fname, mode);
	
	if(fd == -1)
	{
		printf("unable to open file\n");
		return -1;
	}
	else
	{
		printf("file open SuccessFuly in %s Mode \n", Fmode);
	}


	return 0;
}
