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

    stObj.Rollno = 16;  
    stObj.marks = 89.99f;
    stObj.age = 16;
    strcpy(stObj.name, "Rahul");

    printf("Eter the file name: \n");
    scanf("%s",fname);

    fd = creat(fname, 0777);

    write(fd, &stObj, sizeof(stObj));


    return 0;
}