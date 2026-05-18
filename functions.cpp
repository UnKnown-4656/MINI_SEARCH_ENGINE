#include "header.h"
#include <iostream>
// using namespace std;
// namespace fs=filesystem;

// void count_down(int n){
//   if(n==0) return;
//  cout << n <<endl;
//  count_down(n-1);
//}
string ToLower(string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        str[i] = tolower(str[i]);
    }
    return str;
}
void ScanFiles(fs::path Path, unordered_map<string, string> &files)
{
    for (const auto &entry : fs::directory_iterator(Path))
    {
        if (entry.is_directory())
        {
            ScanFiles(entry.path(), files);
        }
        if (entry.is_regular_file())
        {
            // cout <<entry.path()<<endl;
            files[entry.path().filename().string()] = entry.path().string();
        }
    }
}
void SerchFunction(unordered_map<string, string> &files, string Target)
{
    bool found = false;
    try
    {
        for (const auto &entry : files)
        {
            if (ToLower(entry.first).find(ToLower(Target)) != string::npos)
            {
                size_t ending = Target.find_last_of(".");
                if (ending != string::npos)
                {
                    string file_type = Target.substr(ending);
                    if (entry.first.find(file_type) != string::npos)
                    {
                        cout << entry.first << " : " << entry.second << endl;
                        found = true;
                    }
                }
                
                    else
                        cout << entry.first << " : " << entry.second << endl;
                        found = true;
            }
 
        }
        if (!found)
            {
                cout << "File Not Found" << endl;
                
            }
    }
    catch (exception &e)
    {
        cout << "Error : " << e.what() << endl;
    }
}

string input(string placeholder)
{
    string str;
    cout << placeholder;
    cin >> str;
    return str;
}