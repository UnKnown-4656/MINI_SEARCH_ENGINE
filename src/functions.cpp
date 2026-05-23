#include "header.h"
#include <iostream>
// using namespace std;
// namespace fs=filesystem;

// void count_down(int n){
//   if(n==0) return;
//  cout << n <<endl;
//  count_down(n-1);
//}

vector<string> Tokenize(string &str){
    vector<string> tokens;
    string current;
    for (char c :str){
        c=tolower(c);
        if(c=='_' || c=='.' || c=='-' || c==' '){
            if(!current.empty()){
                tokens.push_back(current);
                current.clear();
            }
        }
        else{
            current+=c;
        }
    }
    if(!current.empty()){
        tokens.push_back(current);
    }
    return tokens;
}
string ToLower(string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        str[i] = tolower(str[i]);
    }
    return str;
}
void ScanFiles(fs::path Path, unordered_multimap<string, string> &files)
{
    try
    {
        for (const auto &entry : fs::directory_iterator(Path))
        {
            if (entry.is_directory())
            {
                ScanFiles(entry.path(), files);
            }
            if (entry.is_regular_file())
            {
                string filename = entry.path().filename().string();
                //string LowerFilename = ToLower(filename);
                string path = entry.path().string();
                vector<string> tokenized_filename = Tokenize(filename);
            // cout <<entry.path()<<endl;
                for(const auto &token : tokenized_filename){
                    files.insert({token, path});
                }
                //files.insert({ToLower(entry.path().filename().string()), entry.path().string()});
            }
        }
    }
    catch (exception &e)
    {
        cout << "Error : " << e.what() << endl;
        return;
    }

}
void SerchFunction(unordered_multimap<string, string> &files, string Target)
{
    bool found = false;
    //string LowerTarget = ToLower(Target);
    //string file_type = fs::path(LowerTarget).extension().string();
    vector <string> tokenized_target = Tokenize(Target);

    try
    {
        for (const auto &token : tokenized_target)
        {
            auto range = files.equal_range(token);
            for (auto it = range.first; it != range.second; ++it)
            {
                string file_path = it->second;
                string filename = fs::path(file_path).filename().string();
                cout << filename << " : " << file_path << endl;
                found = true;
            }
        }
        if (!found){
        {
            cout << "File Not Found" << endl;
        }
        }
    }

    catch (exception &e)
    {
        cout << "Error : " << e.what() << endl;
        return;
    }
}       

string input(string placeholder)
{
    string str;
    cout << placeholder;
    cin.ignore();
    getline(cin, str); //will read the whole line even if it contains spaces
    return str;
}

void SaveIndex(unordered_multimap<string, string> &files, string filename)
{
    ofstream Index(filename);
    if (!Index.is_open())
    {
        cout << "Error : Could not open file" << endl;
        return;
    }
    else{
        for (const auto &entry : files)
        {
            Index << entry.first << "|" << entry.second << endl;
        }
        cout << "Index Saved Successfully" << endl;
    }
    
}

void LoadIndex(unordered_multimap<string, string> &files, string filename)

{
    ifstream Index(filename);

    if (!Index.is_open())
    {
        cout << "Error : Could not open file" << endl;
        return;
    }
    else
    {
        string line;
        while (getline(Index, line))
        {
            size_t delimiter = line.find("|");
            if (delimiter != string::npos)
            {
                string key = line.substr(0, delimiter);
                vector<string> tokenized_key = Tokenize(key);
                string value = line.substr(delimiter + 1);
                for(const auto &token : tokenized_key){
                    files.insert({token, value});
                }
                //files.insert({key, value});
            }
        }
        cout << "Index Loaded Successfully" << endl;
    }
}


