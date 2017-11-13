/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Pilandrom.cpp
 * Author: obsidiam
 *
 * Created on November 13, 2017, 4:59 PM
 */
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <fstream>
#include <stdint.h>

using namespace std;

/*
 * 
 */

char toLowerCase(char c){
        if(c >= 65 && c <= 90)
            c += 32;
  
    return c;
}

string removeSpace(string s){
    string result = "";
    for(int i = 0; i < s.size(); i++){
        char c = s.at(i);
        if(c != ' '){
            result += c;
        }
    }
    return result;
}

bool isPilandrom(string s1){
    string st1 = "", st2 = "";

    s1 = removeSpace(s1);
    //cout<<s1<<endl;
    
    bool isOk = true;
    for(int i = 1; i <= (s1.size()/2); i++){
        st1 = s1.at(i - 1);
        st1 = toLowerCase(st1[0]);
        st2 = s1.at(s1.size() - i);
        st2 = toLowerCase(st2[0]);
        
        if(st1 != st2){
            isOk = false;
            break;
        }
    }

    return isOk;
}

int main(int argc, char** argv) {
    ifstream inputFile("dane1.txt");
    ofstream outputFile("pilandromy.txt");
    
    std::string str; 
    string result;

    
    while (!inputFile.eof())
    {
        inputFile>>str;
        if(isPilandrom(str)){
            outputFile<<str+"\n";
        }
    }

    outputFile.close();
    return 0;
}

