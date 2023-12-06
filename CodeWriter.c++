#include "CodeWriter.hpp"
#include "Tokenizer.hpp"

Tokenizer tvect;
CodeWriter::CodeWriter(){

}

void CodeWriter::writeKeyword(){
  //  cout << tvect.tokens[0].val;
}
void CodeWriter::writeSymbol(){

}
void CodeWriter::writeIdentifier(){

}
void CodeWriter::writeInteger(){

}
void CodeWriter::writeString(){

}

    //for(int i = 0; i < tokens.size(); i++){
    //    if(tokens[i].tokenType == 0){
    //        tokenizerOut << "<keyword> "<< tokens[i].val << " </keyword>\n";
    //    }
    //    if(tokens[i].tokenType == 1){
    //        tokenizerOut << "<symbol> "<< tokens[i].val << " </symbol>\n";
    //    }
    //    if(tokens[i].tokenType == 2){
    //        tokenizerOut << "<integerConstant> "<< tokens[i].val << " </integerConstant>\n";
    //    }
    //    if(tokens[i].tokenType == 3){
    //        tokenizerOut << "<stringConstant> "<< tokens[i].val << " </stringConstant>\n";
    //    }
    //    if(tokens[i].tokenType == 4){
    //        tokenizerOut << "<identifier> "<< tokens[i].val << " </identifier>\n";
    //    }
    //    
    //}