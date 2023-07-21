#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>
#include<sys/stat.h>
#include<dirent.h>


int main(int argc, char *argv[])
{

	char name[20];
	char DirName[20];
	DIR *dp = NULL;
	struct dirent *entry = NULL;
	struct stat sobj;

	printf("Enter name of diretory\n");
	scanf("%s", DirName);

	dp = opendir(DirName);

	if(NULL == dp)
	{
		printf("Unable to open directory\n");
		return -1;
	}

    while((entry = readdir(dp)) != NULL)
    {

       	stat(entry->d_name,&sobj);

    	if(S_ISREG(sobj.st_mode))
    	{
    		printf("File name : %s its Regular file \n", entry->d_name);
    	}
    	else if(S_ISDIR(sobj.st_mode))
    	{
    		printf("File name : %s its directory file\n", entry->d_name);
    	}
    	else if(S_ISLNK(sobj.st_mode))
    	{
    		printf("File name : %s its sysbolic link file\n", entry->d_name);
    	}

    }

    printf("-----------------------------------------------------------\n");

    closedir(dp);

	return 0;
}