/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: obsidiam
 *
 * Created on September 23, 2017, 4:52 PM
 */

#include <cstdlib>
#include <iostream>
#include <cmath>


/*
 * 
 */

float F(double x){
    return pow(x,2) - x - 3;
}

double calculate (double p, double q, int n){
    double dl = (q - p)/n, s = 0;
    for(int i = 1; i < n; i++){
        s += abs(F(p + i * dl));
    }
    return dl/2 * (abs(F(p))) + abs(F(q) + 2*s);
}


int main(int argc, char** argv) {
    int in;
    std::cin>>in;
    switch(in){
        case 1:{
            float a,b = 1.f,result = 0;
            std::cout<<"Podaj liczbę do pierwiastkowania: "<<std::endl;
            std::cin>>a;
            result = a;
            while(true){
                result = (result + b)/2;
                b = a/result; 

                if((result - b) < 0.00001f) break;
            }
            std::cout<<"Wynik: "<<b;
        }
        break;
        case 2:{
            double p,q;
            int n;
            std::cin>>p;
            std::cin>>q;
            std::cin>>n;
            std::cout<<calculate(p,q,n);
            break;
        }
    }
    return 0;
}





