#include<iostream>
#include<cstring>
#include<string>
#include<sys/types.h>
#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>	
using namespace std;

int read( string);
void write( string );
void copy(string,string);
void listdir();
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

if(strcmp(argv[1],"listdir")==0)
{
listdir();
}
return 0;
}
int read(string path){
FILE *fp;
char *buffer;
long numbytes;

fp =fopen(path.c_str(), "r");
if (fp == NULL){
printf("nothing to read file not found \n");
return 1;
}
fseek(fp,0L, SEEK_END);
numbytes =ftell(fp);
fseek(fp, 0L,SEEK_SET);
buffer =(char*)calloc(numbytes ,sizeof(char));
 if(buffer == NULL)
return 1;

fread(buffer,sizeof(char),numbytes,fp);
fclose(fp);
printf("number of char: %d\n",numbytes);
printf("%s\n",buffer);
free(buffer);
}

void write(string path){
FILE *fp;
string line;
fp=fopen(path.c_str(),"a+");
if(fp){
while(true){
cin>>line;
if (strcmp(line.c_str() , "quit!!!" )== 0)
	break;
fputs(line.c_str(),fp);
fputs("\n",fp);
}
}
 fclose(fp);
}
void copy(string paths,string pathd){
FILE *fs;
FILE *fd;
char buf;
fs =fopen(paths.c_str(),"r");
if(fs== NULL){
printf("file not found");
}
fd= fopen(pathd.c_str(),"a+");
while(fread(&buf,1,1,fs)==1){
fwrite(&buf,1,1,fd);
}
fclose(fs);
fclose(fd);

}


void listdir(){
DIR *d;
struct dirent *dir;
d= opendir(".");
if(d)
{
while ((dir =readdir(d))!= NULL)
{
printf("%s\n", dir->d_name);
}
closedir(d);
}

}


