
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

float function2(int x){
    return ((-pow(x,2)) + 4);
}

float function(int x){
    return (pow(x,2) - 4);
}

float delta(float x1, float x2, float n){
    if(x1 > x2) return 0;
    
    return (x2 - x1)/n;
}

int main(int argc, char** argv) {
    float x1,x2,n,a,b;
    std::cin>>x1;
    std::cin>>x2;
    std::cin>>n;
    
    float deltares = delta(x1,x2,n);
    std::cout<<deltares<<std::endl;
    float result = 0;
    
    for(float i = x1; i < x2; i += deltares){
        a = function2(i);// - function(i);
        b = function2(i + deltares);//- function(i + deltares);
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
