/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: obsidiam
 *
 * Created on October 21, 2017, 7:31 PM
 */


#include <cmath>
#include <cstdlib>
#include <iostream>

float sqrt(float x){
    float a = x, b = 1, result = x, epsilon = 0.0000001f;
    
    while(true){
        result = (result + b)/2;
        b = a/result;
        if((result - b) < epsilon) break;
    }
    return b;
}

float cubrt(float x){
    float a = x, b = 1, c = 1, result = x;
    
    while(true){
        result =  (result + b + c)/3;
        b = result;
        c = (a - b)/ result ;
        if((b - c) < 0.00000001f) break;
    }
    
    return c;
}

float field(float a, float b,float deltares){
    return ((a + b)/2) * deltares;
}

float function2(float x){
    return (-pow(x,2) + 4);
}

float function(float x){
    return (pow(x,2) - 4);
}

float delta(float x1, float x2, float n){
    if(x1 > x2) return 0;
    
    return (x2 - x1)/n;
}

int main(int argc, char** argv) {
    float x1,x2,n,a = 0,b = 0;
    std::cin>>x1;
    std::cin>>x2;
    std::cin>>n;
    
    float deltares = delta(x1,x2,n);
    std::cout<<deltares<<std::endl;
    float result = 0;
    
    for(float i = x1; i < x2; i += deltares){
        a = function2(i)  - function(i);
        b = function2(i + deltares) - function(i + deltares);
        result += field(a,b,deltares);
    }
    std::cout<<result<<std::endl;
/*
    float num;
    std::cin>>num;
    std::cout<<cubrt(num)<<std::endl;
*/
    return 0;
}

