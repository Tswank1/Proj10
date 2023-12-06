#ifndef TOKENIZER_HPP
#define TOKENIZER_HPP
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <regex>
#include <sstream>
using namespace std;

extern ifstream originalFile;
extern ifstream tempReadFile;
extern ofstream tempfile;
extern ofstream tokenizerOut; 

class Tokenizer{
    private:
        regex keywordPattern = regex("\\b(method|function|constructor|int|class|boolean|char|void|var|static|field|let|do|if|else|while|return|true|false|null|this)\\b");
        regex symbolPattern = regex("[{}\\[\\].,;+\\\\\\-*/&|<>=~()]");
        regex intConstPattern = regex("\\b\\d+\\b");
        regex stringConstPattern = regex("\"([^\"]*)\"");
        regex identifierPattern = regex("[a-zA-Z]+");
        regex whitespacePattern = regex("\\s+");

        int keyword = 0;
        int symbol = 1;
        int intConst = 2;
        int stringConst = 3;
        int identifier = 4;

        struct Token{
            int tokenType;
            string val;
        };

        
        vector<string> keywords;
        vector<Token> tokens;

    public:
        friend class CodeWriter;
        Tokenizer();
        void removeComments();
        void tokenize();
        bool hasMoreTokens();
};
#endif