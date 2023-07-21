#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<dirent.h>
#include<string.h>
#include<sys/stat.h>

int main(int argc, char *argv[20])
{
	char name[30];
	char findfile[30];

	DIR *dp = NULL;
	struct dirent *entry = NULL;

	int isPre = 0;

	if(argc != 3)
	{
		printf("Insufficient arguent\n");
		return -1;
	}

	strcpy(name, argv[2]);

	dp = opendir(argv[1]);

	if(NULL == dp)
	{
		printf("Unable to open directory \n");
		return 0;
	}

	while((entry = readdir(dp)) != NULL)
	{
		if(strcmp(name,entry->d_name) == 0)
		{
			isPre = 1;

			printf("File is Present in directory :  %s\n",name);
			break;
		}
	}

	if(isPre == 0)
	{
		printf("File is not present in that directory\n");
	}

	return 0;
}