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

using namespace std;

void makeDir(string);
void removeDir(string);
void getStat(string);
int doesPathExist(string);
void read( string);
void write( string );
void copy(string,string);
void set(string,string);

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
        
       if (argv[3] == NULL){
       cout << "Need premission input";
       return 0;
       }
        
       set(argv[2], argv[3]);


    }
    else if(strcmp(argv[1], "move") == 0){				//move
        
        //set(argv[2],argv[3]);
	//Rasheed
	
        try {
            rename(argv[2].c_str(), argv[3].c_str());
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
        char file_name[25];
        
        cout << "Enter name of a file you wish to delete\n";
        gets(file_name);
        
        status = remove(file_name);
        
        if (status == 0)
            cout << file_name <<  " deleted successfully. ";
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

void set(string path, string argv){
    
    if(strcmp(argv.c_str(), "S_IRUSRt")){
        chmod(path.c_str(), S_IRUSR);
    }else if(strcmp(argv.c_str(), "S_IRWXU")){
        chmod(path.c_str(), S_IRWXU);
    }else if(strcmp(argv.c_str(), "S_IWUSR")){
        chmod(path.c_str(), S_IWUSR);
    }else if(strcmp(argv.c_str(), "S_IXUSR")){
        chmod(path.c_str(), S_IXUSR);
    }else if(strcmp(argv.c_str(), "S_IRGRP")){
        chmod(path.c_str(), S_IRGRP);
    }else if(strcmp(argv.c_str(), "S_IRWXG")){
        chmod(path.c_str(), S_IRWXG);
    }else if(strcmp(argv.c_str(), "S_IWGRP")){
        chmod(path.c_str(), S_IWGRP);
    }else if(strcmp(argv.c_str(), "S_IXGRP")){
        chmod(path.c_str(), S_IXGRP);
    }else if(strcmp(argv.c_str(), "S_IROTH")){
        chmod(path.c_str(), S_IROTH);
    }else if(strcmp(argv.c_str(), "S_IRWXO")){
        chmod(path.c_str(), S_IRWXO);
    }else if(strcmp(argv.c_str(), "S_IWOTH")){
        chmod(path.c_str(), S_IWOTH);
    }else if(strcmp(argv.c_str(), "S_IXOTH")){
        chmod(path.c_str(), S_IXOTH);
    }else{
        cout << "Error, incorrect arguments";
        exit(-1);
    }

}

//Timiriz
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
  	if(strcmp(line.c_str(), "quit!!!") == 0)break;
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





