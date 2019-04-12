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
#include<stdio.h>
using namespace std;

void read( string);
void write( string );
void copy(string,string);
int main (int argc , char *argv[]){
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
if(strcmp(argv[1],"copy")==0)
{
copy(argv[2],argv[3]);
}
return 0;
}

 

void read( string path){

char buf[1024];
size_t nbytes;
ssize_t bytes_read;
int fd;
nbytes =sizeof(buf);
fd=open(path.c_str(),O_RDONLY);
if(fd==-1){
cout<<"ERROR IN OPENING FILE ,FILE DOESNOT EXISTS"<<endl;
exit(-1);
}
else{
bytes_read = read(fd, buf , nbytes);
cout << buf <<endl;
close(fd);
}

}
 void write(string path){
int i;
int fd;
//char buf[1024];
string line;
ssize_t bytes_written;
size_t nbytes;
nbytes =sizeof (line);
fd= open(path.c_str(),O_WRONLY | O_CREAT |O_APPEND |O_TRUNC|S_IRUSR|S_IWUSR);
if(fd == -1){
cout<<"permission denied...cannot open a file"<<endl;
}
else
{

cout << "Start Writing\n";

while(true){


	cin>>line;
  	if(strcmp(line.c_str(), "quit!!!") ==true)break;
	nbytes = sizeof(line.c_str());
	write(fd,line.c_str(),nbytes);
        
}

close(fd);
}


}
 void copy(string paths,string pathd){
int fdi,fdo,openflags;
mode_t fileper;
char buf[1024];
size_t nbytes;
ssize_t readnum;
nbytes= sizeof(buf);
 fdi=open(paths.c_str(),O_RDONLY);
if(fdi==-1){
cout<<"error in opening file"<<endl;
}
openflags = O_CREAT|O_WRONLY|O_TRUNC;
fileper = S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH;
fdo =open (pathd.c_str(),openflags,fileper);
if(fdo==-1){
cout<<"error in opening file"<<endl;
}
while((readnum = read(fdi,buf,nbytes)>0)){
   write(fdo,buf,nbytes);
}
close(fdi);
close(fdo);
}
