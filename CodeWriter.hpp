#ifndef CODEWRITER_HPP
#define CODEWRITER_HPP
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;



class CodeWriter{
    private:
        int indent;
    public:
        CodeWriter();
        void writeKeyword();
        void writeSymbol();
        void writeIdentifier();
        void writeInteger();
        void writeString();
};
#endif