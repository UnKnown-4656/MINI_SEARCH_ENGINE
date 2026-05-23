#include "includes/header.h"

//using namespace std;
//namespace fs=filesystem;

int main()
{
    fs::path MyPath ="D:\\Downloads";
    //string Target=input("Enter Target File Name :");
    //string file_type=input("Enter File Type :"); i think i dont need it
    unordered_multimap <string ,string> files;
    //for(const auto& entry : fs::directory_iterator(MyPath)){
        //cout <<entry.path() <<endl;
    //}
    //ScanFiles(MyPath,files);
    //SerchFunction(files,Target);
    if(fs::exists("index.txt")){
        LoadIndex(files,"index.txt");
    }
    else{
        ScanFiles(MyPath,files);
        SaveIndex(files,"index.txt");
    }
    bool running = true;
    while(running==true){
        int user_choice;
        cout << "1. Search for a file" << endl;
        cout << "2. Rescan files" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin>> user_choice;
        if(user_choice==2){
            files.clear();
            ScanFiles(MyPath,files);
            SaveIndex(files,"index.txt");
            cout << "Files Rescanned Successfully" << endl;
            continue;
        }
        else if(user_choice==3){
            running=false;
            break; 
        }
        else if(user_choice==1){
            string Target=input("Enter Target File Name :");
            SerchFunction(files,Target);
        }
        else{
            cout << "Invalid Choice" << endl;
            //break;
        }
    }

    return 0;
}
