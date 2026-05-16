#include "header.h"

//using namespace std;
//namespace fs=filesystem;

int main()
{
    fs::path MyPath ="D:\\Downloads";
    string Target="ilovepdf_merged";
    unordered_map <string ,string> files;
    //for(const auto& entry : fs::directory_iterator(MyPath)){
        //cout <<entry.path() <<endl;
    //}
    ScanFiles(MyPath,files);
    SerchFunction(files,Target);
    return 0;
}
