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
        try {
            std::filesystem::rename("from.txt", "to.txt");
        } catch (std::filesystem::filesystem_error& e) {
            std::cout << e.what() << '\n';
        }
        
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
        
        /*
        int nsize = 10;
        char *somedata;
        ifstream myfile;
        myfile.open("<path to file>");
        myfile.read(somedata,nsize);
        myfile.close();
         */
        
    }
    else if(strcmp(argv[1], "deleteFile") == 0){
        
        //deleteFile(argv[2]);
        int status;
        char file_name[25];
        
        cout << "Enter name of a file you wish to delete\n";
        gets(file_name);
        
        status = remove(file_name);
        
        if (status == 0)
            cout << "%s file deleted successfully.\n", file_name;
        else
        {
            cout << "Unable to delete the file\n";
            perror("Following error occurred");
        }
        
        
        return 0;
        
    }
    else if(strcmp(argv[1], "createFile") == 0){
        
        //createFile(argv[2]);
        /*Create file*/
        int filename;
        cout << "Enter file name"; cin >> filename;
        
        ofstream myfile;
        myfile.open ("filename.txt");
        myfile << "Writing this to a file.\n";
        myfile << "000" << filename;
        myfile.close();
        
    }
    
    return 0;
}
