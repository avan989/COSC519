#include<iostream>
#include<cstring>
#include<string>
#include<sys/types.h>
#include<unistd.h>
#include<cstdlib>
#include<fcntl.h>
#include<time.h>
#include<sstream>
#include<sys/stat.h>
using namespace std;

void read( char *path);
void write( char *path);
void close( char *path);
void copy(char *paths , char *pathd);
int main (int argc ,char *argv[]){
  if (argc <2){
cout << "there are no enough arguments" << endl;
exit(-1);
}
if (strcmp(argv[1],"read")== 0)
{
read(argv[2]);
}
if (strcmp(argv[1],"write")== 0)
{
write(argv[2]);


}
if (strcmp(argv[1],"close")==0)
{
close(argv[2]);
}
if(strcmp(argv[1],"copy")==0)
{
	copy (argv[2],argv[3]);
}
return 0;
} 

 void read(char *path){

char buf[1024];
size_t nbytes;
ssize_t bytes_read;
int fd;
nbytes =sizeof (buf);

fd= open(path,O_RDONLY);

if (fd == -1){
cout<<"ERROR IN OPENING FILE ,FILE DOESNOT EXISTS"<<endl;
}
else
{
cout<<"file exist...ready to file " <<endl;

bytes_read = read(fd, buf , nbytes);
cout << buf <<endl;
close(fd);
}

}
 void write( char *path){
int i;
int fd;
char c;
char buf[1024];
ssize_t bytes_written;
size_t nbytes;
nbytes =sizeof (buf);
fd= open(path,O_WRONLY | O_CREAT |O_APPEND |O_TRUNC ,S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP |
 S_IROTH | S_IWOTH );
if(fd == -1){
cout<<"permission denied...cannot open a file"<<endl;
}
else
{
cout << "start writing"<<endl;
cin>>c>>buf;
bytes_written = write(fd ,buf ,nbytes);	
close(fd);
}
 }
void copy(char *paths,char *pathd){
int inputFd, outputFd, openFlags;
 mode_t filePerms;
 ssize_t numRead;
 char buf[1024];

 inputFd = open(paths, O_RDONLY);
 if (inputFd == -1)
 {
	 cout<<"error in opening file"<<endl;
 }	 
 openFlags = O_CREAT | O_WRONLY | O_TRUNC;
 filePerms = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP |
 S_IROTH | S_IWOTH;
 outputFd = open(argv[2], openFlags, filePerms);
 if (outputFd == -1){
	 cout<<"error in opening file ...."<<endl;
 }
 while ((numRead = read(inputFd, buf, BUF_SIZE)) > 0){
 write(outputFd, buf, numRead);
 }
 close(inputFd);
 close(outputFd);
}
void close( char *path){
int fd;
fd= open(path,O_RDONLY|O_WRONLY);
if(fd==-1){
	cout<<"error file not found"<<endl;
}
else{
cout<<"...closing file" <<endl;
dup(fp);
close(fp);
}
}
