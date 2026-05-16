#include "header.h"
#include <iostream>
//using namespace std;
//namespace fs=filesystem;


//void count_down(int n){
  //  if(n==0) return;
   // cout << n <<endl;
   // count_down(n-1);
//}
string ToLower(string str){
    for(int i=0;i<str.length();i++){
        str[i]=tolower(str[i]);
    }
    return str;
}
void ScanFiles(fs::path Path ,unordered_map<string ,string >& files){
    for(const auto& entry :fs::directory_iterator(Path)){
        if(entry.is_directory()){
            ScanFiles(entry.path(),files);
        }
        if(entry.is_regular_file()){
            //cout <<entry.path()<<endl;
            files[entry.path().filename().string()]=entry.path().string();
        }
    }
}
void SerchFunction(unordered_map<string ,string >& files,string Target){
    for(const auto& entry:files){
        if(ToLower(entry.first).find(ToLower(Target))!=string::npos){
            cout <<entry.first<< " : " <<entry.second<<endl;
        }
    }
}
