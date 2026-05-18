#include "header.h"

//using namespace std;
//namespace fs=filesystem;

int main()
{
    fs::path MyPath ="D:\\Downloads";
    string Target=input("Enter Target File Name :");
    //string file_type=input("Enter File Type :"); i think i dont need it
    unordered_map <string ,string> files;
    //for(const auto& entry : fs::directory_iterator(MyPath)){
        //cout <<entry.path() <<endl;
    //}
    ScanFiles(MyPath,files);
    SerchFunction(files,Target);
    return 0;
}
