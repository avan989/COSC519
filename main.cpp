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

using namespace std;

void makeDir(string);
void removeDir(string);
void getStat(string);
int doesPathExist(string);

int main(int argc, const char * argv[]) {
    
    if(argc < 2){
        cout << "There are not enough arguments" << endl;
        exit(-1);
    }
    
    
    if(strcmp(argv[1], "createDir") == 0){

        makeDir(argv[2]);
        
    }
    else if(strcmp(argv[1], "deleteDir") == 0){

        removeDir(argv[2]);
    }
    else if(strcmp(argv[1], "get") == 0){

        getStat(argv[2]);
    }
    else if(strcmp(argv[1], "set") == 0){
        
       if (argv[3] == NULL){
       cout << "Need premission input";
       return 0;
       }
        
       set(argv[2], argv[3]);


    }
    else if(strcmp(argv[1], "move") == 0){
        
        //set(argv[2],argv[3]);
        
    }
    else if(strcmp(argv[1], "read") == 0){
        
        //read(argv[2]);
        
    }
    else if(strcmp(argv[1], "write") == 0){
        
        //write(argv[2]);
        
    }
    else if(strcmp(argv[1], "close") == 0){
        
        //close(argv[2]);
        
    }
    else if(strcmp(argv[1], "open") == 0){
        
        //open(argv[2]);
        
    }
    else if(strcmp(argv[1], "deleteFile") == 0){
        
        //deleteFile(argv[2]);
        
    }
    else if(strcmp(argv[1], "createFile") == 0){
        
        //createFile(argv[2]);
        
    }else {
	cout << "incorrect command enter: " << argv[1] << endl;
	}
    
    return 0;
}

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




