#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>
#include<sys/stat.h>
#include<dirent.h>


int main(int argc, char *argv[])
{

	int maxsize = 0;
	char name[20];
	char DirName[20];
	char namecopy [30] = {'\0'};
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
    	stat(entry->d_name, &sobj);

    	if(S_ISREG(sobj.st_mode))
	    	if(maxsize < sobj.st_size)
	    	{
	    		maxsize = sobj.st_size;
	    		strcpy(namecopy, entry->d_name);
	    	}
    }

    printf("MAx File Size\n");
    printf("name of larget file : %s  File Size %d bytes \n", namecopy, maxsize);

    printf("-----------------------------------------------------------\n");

    closedir(dp);

	return 0;
}