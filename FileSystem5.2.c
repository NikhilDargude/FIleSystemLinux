#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>

#pragma pack(1)
struct student
{
    int Rollno;
    float marks;
    char name[20];
    int age;
};


int main(int argc, char * argv[])
{
    struct student stObj;
    char fname[20];
    int fd = 0;

    printf("Eter the file name: \n");
    scanf("%s",fname);

    fd = open(fname, O_RDONLY);

    if(fd == -1)
    {
        printf("Unable to open File \n");
        return -1;
    }

    read(fd,&stObj,sizeof(stObj));

    printf("Roll number : %d : \n",stObj.Rollno);
    printf("Name : %s : \n",stObj.name);
    printf("Marks : %f : \n",stObj.marks);
    printf("Age : %d : \n",stObj.age);

    close(fd);


    return 0;
}