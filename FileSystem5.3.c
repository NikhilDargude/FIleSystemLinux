#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<sys/stat.h>
#include<dirent.h>


int main(int argc, char *argv[])
{
	char fname[50];
	DIR * dp = NULL;
	struct stat sobj;
	struct dirent * entry = NULL;

	if(argc != 2)
	{
		printf("Insufficient Argument \n");
		return -1;
	}

	dp = opendir(argv[1]);

	if(NULL == dp)
	{
		printf("Unable to open directory \n");
		return -1;
	}

	while((entry = readdir(dp)) != NULL)
	{
		strcpy(fname, entry->d_name);
		stat(fname,&sobj);

		if(S_ISREG(sobj.st_mode))
		{
			printf("is Reguler file : %s \n", fname);
			printf("Size of file is : %ld \n", sobj.st_size);

		}
	}

	closedir(dp);

	return 0;
}