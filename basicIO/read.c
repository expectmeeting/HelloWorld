#include<stdio.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(){
    const char *filename = "test";
    int bufsize = 1024*1024;
    int fd = open(filename, O_RDWR|O_SYNC|O_CREAT|O_TRUNC);
    char buf[1024] = {'h','e','a','d'};
    if(write(fd,buf,1024)<0){
        printf("ERROR: write function\n");
        getchar();
        return -1;
    }
    //close(fd);
    //fd = open(filename, O_RDWR|O_SYNC|O_CREAT);
    int n = lseek(fd,4,SEEK_CUR);
    if(write(fd,buf,1024)<0){
        printf("ERROR: write function\n");
        getchar();
        return -1;
    }
    char recvbuf[2048];
    int nbyte = 1025;
    int y=read(fd,recvbuf,nbyte);
    recvbuf[nbyte]='\0';
    printf("%s\n",recvbuf);
    printf("read return value:%d\n",y);
    return 1;
}
