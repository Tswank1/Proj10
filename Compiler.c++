#include <string>
#include <iostream>
#include <fstream>
#include "Tokenizer.hpp"
#include "CodeWriter.hpp"
using namespace std;

ofstream tokenizerOut;
ofstream tempfile;
ifstream originalFile;
ifstream tempReadFile;

int main(int argc, char const *argv[]){
    string originalName, tempfileName;

    originalName = string(argv[1]);
    originalFile.open(originalName);
    if(!originalFile.is_open() || argc < 2){
        return -1;
    }

    tempfileName = originalName.substr(0, originalName.find_last_of('.')) + ".txt";
    tempfile.open(tempfileName);
    if(!tempfile.is_open()){
        return -1;
    }

    Tokenizer tokenizer;
    tokenizer.removeComments();
    tempfile.close();
    tempReadFile.open(tempfileName);
    if(!tempReadFile.is_open()){
        return -1;
    }
    
    tempfileName = originalName.substr(0, originalName.find_last_of('.')) + "tokens.txt";
    tokenizerOut.open(tempfileName);
    if(!tokenizerOut.is_open()){
        return -1;
    }
    

    tokenizer.tokenize();
    //CodeWriter codeWrite;
    //codeWrite.writeKeyword();

    tokenizerOut.close();
    tempReadFile.close();
    originalFile.close();

    return 0;
}