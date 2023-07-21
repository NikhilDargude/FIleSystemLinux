#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
#include<dirent.h>
#include<sys/stat.h>


int main(int argc, char const *argv[])
{
	DIR *dp = NULL;
	struct stat sobj;
	struct dirent *entry = NULL;

	char fname[30];

	if(argc != 2)
	{
		printf("Isufficient argument\n");
		return -1;
	}

	dp = opendir(argv[1]);

	if(dp == NULL)
	{
		printf("Unable to open directory\n");
		return-1;
	}

	while((entry = readdir(dp)) != NULL)
	{
		strcpy(fname, entry->d_name);
		stat(fname,&sobj);

		if(sobj.st_size > 100)
		{
			remove(fname);
			printf("Delete file size is greter than 100 is : %s\n",fname);
		}
	}

	return 0;
}