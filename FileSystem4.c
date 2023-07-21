#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>


int main(int argc , char *argv[])
{
	struct stat sobj;

	if(argc != 2)
	{
		printf("Insufficient Argument\n");
		return -1;
	}

	stat(argv[1], &sobj);

	printf("File Name is %s: \n", argv[1]);
	printf("File Size of %ld : \n", sobj.st_size);
	printf("Number of links %ld: \n", sobj.st_nlink);
	printf("inode number is %ld : \n", sobj.st_ino);
	printf("File system number : %ld\n",sobj.st_dev);
    	printf("Number of blocks : %ld\n",sobj.st_blocks);


	return 0;
}
