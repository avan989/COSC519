//
//  main.cpp
//  COSC519_main

#include <iostream>
#include <cstring>

using namespace std;

int main(int argc, const char * argv[]) {
    
    if(argc < 2){
        cout << "There are no arguments" << endl;
        return -1;
    }
    
    
    if(strcmp(argv[1], "createDir") == 0){
        
        //createDir(argv[2]);
    }
    else if(strcmp(argv[1], "deleteDir") == 0){

        //deleteDir(argv[2]);
    }
    else if(strcmp(argv[1], "get") == 0){

        //get(argv[2]);
    }
    else if(strcmp(argv[1], "set") == 0){
        
        //set(argv[2]);

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
    else if(strcmp(argv[1], "help") == 0){
        
        //deleteDir(argv[2]);
        printf("createDir\n");
        printf("deleteDir\n");
        printf("get\n");
        printf("set\n");
        printf("move\n");
        printf("read\n");
        printf("write\n");
        printf("close\n");
        printf("help\n");
        printf("open\n");
        printf("deleteFile\n");
        printf("createFile\n");
    }
    else if(strcmp(argv[1], "open") == 0){
        
        //open(argv[2]);
        FILE *fptr;
        char file[15];
        char c;
        
        printf("Type name of file to be opened \n");
        scanf("%s", file);
        /*  open the file for reading */
        fptr = fopen(file, "r");
        if (fptr == NULL)
        {
            printf("Error: Cannot open file \n");
            exit(0);
        }
        c = fgetc(fptr);
        while (c != EOF)
        {
            printf ("%c", c);
            c = fgetc(fptr);
        }
        fclose(fptr);
        
    }
    else if(strcmp(argv[1], "deleteFile") == 0){
        
        //deleteFile(argv[2]);
        int status;
        char file[25];
        
        printf("Type name of file to be deleted\n");
        gets(file);
        
        status = remove(file_name);
        
        if (status == 0)
        printf("%s File deleted\n", file);
        else
            perror("Error");
        
        
        return 0;
        
    }
    else if(strcmp(argv[1], "createFile") == 0){
        
        //createFile(argv[2]);
        /*Create file*/
        printf("Creating file..\n");
        FILE *f = fopen("file.txt", "w");
        
    }
    
    return 0;
}
