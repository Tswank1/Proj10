#include "Tokenizer.hpp"

Tokenizer::Tokenizer(){

}
void Tokenizer::removeComments(){
    bool inCommentBlock = false;
    string line;

    while(getline(originalFile, line)){
        int startComm = line.find("/*");
        int endComm = line.find("*/");
        int singleComm = line.find("//");

        while(startComm != -1){
            if(endComm != -1){
                line.erase(startComm, endComm - startComm + 2);
                startComm = line.find("/*");  
                endComm = line.find("*/");      
            }
            else{
                inCommentBlock = true;
                line.erase(startComm);
                break;
            }
        }
        
        if(inCommentBlock){
            endComm = line.find("*/");
            if(endComm != -1){
                line.erase(0, endComm + 2);
                inCommentBlock = false;
            }
            else{
                line.clear();
            }
        }

        if(singleComm != -1){
            line = line.substr(0, singleComm);
        }

        if(!line.empty()){
            tempfile << line << '\n';
        }
    }

}

void Tokenizer::tokenize(){
    string line;
    while(getline(tempReadFile, line)){ 
        istringstream iss(line);
        string tokenString;
        while(iss >> tokenString){       
            smatch currMatch;
            while(!tokenString.empty()){

                //if(line.substr(0,1) == " "){
                //    line.erase(line.begin());
                //}
                //if(regex_search(line, currMatch, whitespacePattern)){
                //    line = line.substr(currMatch.position() + currMatch.length());
                //}

                if(tokenString.empty()){
                    break;
                }

                if(regex_search(tokenString, currMatch, keywordPattern)){
                    tokens.push_back({keyword, currMatch[0]});
                    tokenString.erase(tokenString.begin()+currMatch.position(), tokenString.begin()+currMatch.position()+currMatch.length());

                }
                else if(tokenString.find("\"") == -1 && regex_search(tokenString, currMatch, identifierPattern)){
                    tokens.push_back({identifier, currMatch[0]});
                    tokenString.erase(tokenString.begin()+currMatch.position(), tokenString.begin()+currMatch.position()+currMatch.length());
                }
                else if(regex_search(tokenString, currMatch, symbolPattern)){
                    tokens.push_back({symbol, currMatch[0]});
                    tokenString.erase(tokenString.begin()+currMatch.position(), tokenString.begin()+currMatch.position()+currMatch.length());
                }
                else if(regex_search(tokenString, currMatch, intConstPattern)){
                    tokens.push_back({intConst, currMatch[0]});
                    tokenString.erase(tokenString.begin()+currMatch.position(), tokenString.begin()+currMatch.position()+currMatch.length());
                }
                else if(regex_search(tokenString, currMatch, stringConstPattern)){
                    tokens.push_back({stringConst, currMatch[0]});
                    tokenString.erase(tokenString.begin()+currMatch.position(), tokenString.begin()+currMatch.position()+currMatch.length());
                }
                else{
                    string temp = tokenString;
                    iss >> tokenString;
                    tokenString = temp + " " + tokenString;
                }
                cout << tokenString << endl;
            }
        }        
    }
    tokenizerOut << "<tokens>" << endl;
    for(int i = 0; i < tokens.size(); i++){
        if(tokens[i].tokenType == 0){
            tokenizerOut << "<keyword> "<< tokens[i].val << " </keyword>\n";
        }
        if(tokens[i].tokenType == 1){
            tokenizerOut << "<symbol> "<< tokens[i].val << " </symbol>\n";
        }
        if(tokens[i].tokenType == 2){
            tokenizerOut << "<integerConstant> "<< tokens[i].val << " </integerConstant>\n";
        }
        if(tokens[i].tokenType == 3){
            tokenizerOut << "<stringConstant> "<< tokens[i].val << " </stringConstant>\n";
        }
        if(tokens[i].tokenType == 4){
            tokenizerOut << "<identifier> "<< tokens[i].val << " </identifier>\n";
        }
        
    }
}

bool Tokenizer::hasMoreTokens(){
    return false;
}
