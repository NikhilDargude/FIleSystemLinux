#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<dirent.h>
#include<sys/dir.h>
#include<sys/stat.h>


int main(int argc, char *argv[])
{
    DIR *dp = NULL;
    struct dirent *entry = NULL;
    struct stat sobj;

    char name[30];

    dp = opendir(argv[1]);
    if(dp == NULL)
    {
        printf("Unable to open directory\n");
        return -1;
    }

    while((entry = readdir(dp)) != NULL)
    {
        strcpy(name, entry->d_name);
        stat(entry->d_name,&sobj);
        
        if(S_ISREG(sobj.st_mode))
        {
            if(sobj.st_size == 0)
            {
                remove(name);
                printf("File %s is Successfully deleted\n",name);
            }
        }

    }

    closedir(dp);
    return 0;
}