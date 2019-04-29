//
//  main.cpp
//  COSC519_main

#include <iostream>
#include <cstring>
#include <string>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include <cstdlib>
#include <stdio.h>
#include <fstream>
#include <fcntl.h>
#include<dirent.h>

using namespace std;

void makeDir(string);
void removeDir(string);
void getStat(string);
int doesPathExist(string);
void read( string);
void write( string );
void copy(string,string);
void set(string);
void listdir();


int main(int argc, const char * argv[]) {
    
    if(argc < 2){
        cout << "There are not enough arguments" << endl;
        exit(-1);
    }
    
    if(strcmp(argv[1], "createDir") == 0){				//createDir

        makeDir(argv[2]);
        
    }
    else if(strcmp(argv[1], "deleteDir") == 0){				//deleteDir

        removeDir(argv[2]);
    }
    else if(strcmp(argv[1], "get") == 0){				//get

        getStat(argv[2]);
    }
    else if(strcmp(argv[1], "set") == 0){				//set
        
       set(argv[2]);

    }
    else if(strcmp(argv[1], "move") == 0){				//move
        
        //set(argv[2],argv[3]);
	//Rasheed
	
        try {
            rename(argv[2], argv[3]);
        } catch (int e) {
            cout << "ERROR : " << e << endl;
        }
        
    }
    else if(strcmp(argv[1], "read") == 0){				//read
        
        read(argv[2]);
        
    }
    else if(strcmp(argv[1], "write") == 0){                             //write
        write(argv[2]);
        
    }
   else if(strcmp(argv[1], "listdir") == 0){                             //write
        listdir();
	   
	}
    else if(strcmp(argv[1], "copy") == 0){				//copy
        
        copy(argv[2],argv[3]);
        
    }
    else if(strcmp(argv[1], "open") == 0){                             //open
        
        //open(argv[2]);
	//Rasheed
	FILE *fptr;
        char file[15];
        char c;
        
	cout << "Type name of file to be opened: \n";
        scanf("%s", file);
        /*  open the file for reading */
        fptr = fopen(file, "r");
        if (fptr == NULL)
        {
            cout << "Error cannot open file";
            exit(0);
        }
        c = fgetc(fptr);
        while (c != EOF)
        {
            cout << c << endl;
            c = fgetc(fptr);
        }
        fclose(fptr);
        
    }
    else if(strcmp(argv[1], "deleteFile") == 0){                                 //deleteFile
        
        //deleteFile(argv[2]);
	//Rasheed
	int status;
        //char file_name[25]
        //cout << "Enter name of a file you wish to delete\n";
        //gets(file_name);
        
        status = remove(argv[2]);
        
        if (status == 0)
            cout << argv[2] <<  " deleted successfully. ";
        else
        {
            cout << "Unable to delete the file\n";
            perror("Following error occurred");
        }
        
    }
    else if(strcmp(argv[1], "createFile") == 0){                             //createFile
        
        //createFile(argv[2]);
	//Rasheed
	int filename;
        cout << "Enter file name"; cin >> filename;
        ofstream myfile;
	
        myfile.open ("filename.txt");
        myfile << "Writing this to a file.\n";
        myfile << "000" << filename;
        myfile.close();
        
    } else if(strcmp(argv[1], "help") == 0){                               //help
        
        //deleteDir(argv[2]);
        cout << "createDir\n";
        cout << "deleteDir\n";
        cout << "get\n";
        cout << "set\n";
        cout << "move\n";
        cout << "read\n";
        cout << "write\n";
        cout << "close\n";
        cout << "help\n";
        cout << "open\n";
        cout << "deleteFile\n";
        cout << "createFile\n";
	    
    }else {
	cout << "incorrect command enter: " << argv[1] << endl;
	}
    
    return 0;
}

//Function

int doesPathExist(string path, struct stat &b){
    
    return stat(path.c_str(), &b);
}

//make directory
void makeDir(string path){
    
    int status;
    struct stat b;
    
    //check to see if path exists.
    status = doesPathExist(path, b);
    
    if(status == 0){
        cout << "Directory already exist\n";
        exit (-1);
    }
    
    //user has read,write, exec access while group and other only has read access.
    status = mkdir(path.c_str(), S_IRUSR | S_IWUSR | S_IXUSR | S_IRGRP | S_IROTH);
    
    if(status == 0)
        cout << "Directory was created \n";
    else{
        cout << "Error in creating directory, check if path exist.\n";
        exit(-1);
    }
}

//remove directory
void removeDir(string path){
    
    int status;
    struct stat b;
    
    //check to see if path exist.
    status = doesPathExist(path, b);
    
    if(status < 0){
        cout << "Error, path does not exist \n";
        exit(-1);
    }
    
    //remove directory
    status = rmdir(path.c_str());
    
    if(status == 0)
        cout << "Directory successfully removed \n";
    else{
        cout << "Error in removing Directory, check to see if Directory is empty \n";
        exit(-1);
    }
}

//get attribute
void getStat(string path){
    
    int status;
    struct stat b;
    
    status = doesPathExist(path, b);
    
    if(status < 0){
        
        cout << "Error, path does not exist \n";
        exit(-1);
        
    }else{
        
        cout << "ID of Device:              " << b.st_dev << endl;
        cout << "Inode number:              " << b.st_ino << endl;
        cout << "Protection:                " << b.st_mode << endl;
        cout << "Number of Hard Link:       " << b.st_nlink <<endl;
        cout << "User ID:                   " << b.st_uid << endl;
        cout << "group ID:                  " << b.st_gid << endl;
        cout << "Total size:                " << b.st_size << endl;
        cout << "Time of Last Access:       " << asctime(localtime(&b.st_atime));
        cout << "Time of last Modification: " << asctime(localtime(&b.st_mtime));
        cout << "Time of last status:       " << asctime(localtime(&b.st_ctime));
        
    }
    
}

void set(string path){
    
    int i;
    string mode; 
    cout << "Enter mode: " << endl;
    cin >> mode;

    i=strtol(mode.c_str(),0,8);

    chmod(path.c_str(),i);

}

//Timiriz
void read(string path){
FILE *fp;
char *buffer;
long numbytes;

fp =fopen(path.c_str(), "r");
    
if (fp == NULL){
printf("nothing to read file not found \n");
exit (-1);
}
    
fseek(fp,0L, SEEK_END);
numbytes =ftell(fp);
fseek(fp, 0L,SEEK_SET);
buffer =(char*)calloc(numbytes ,sizeof(char));
if(buffer == NULL)
    exit (-1);

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
