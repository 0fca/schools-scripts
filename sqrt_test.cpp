#include <iostream>
#include <cmath>

float sqrtf(float x){
    float a = x, b = 1, result = x, epsilon = 0.0000001f;
    do{
        result = (result + b)/2.f;
        b = a/result;
    }while((result - b) < epsilon);

    return b;
}

float function3(float x){
    return -pow((0.5f*x),2) + 4.f;
}

float function2(float x){
    float fr = 4.f - (x * x);
    std::cout<<fr<<std::endl;
    return sqrtf(fr);
}

float function1(float x){
    double fr = 4.f - (x * x);
    //std::cout<<fr<<std::endl;
    return -(sqrtf(fr));
}

float delta(float x, float x2, float n){
    if(x > x2) return 0; return (x2 - x)/n;
}

float trapeze_field(float a, float b, float h){
    return ((a + b)/2.f) * h;
}

float rect_field(float a, float b){
    return a * b;
}

int main() {
    float x, x2, n, a, b, tra_result = 0,rect = 0,deltares;
    std::cin>>x;
    std::cin>>x2;
    std::cin>>n;
    deltares = delta(x,x2,n);
    std::cout<<"Delta = "<<deltares<<std::endl;
    //std::cout<<sqrtf(1.44f)<<std::endl;

    for(float i = x; i < (x2 - deltares); i += deltares){
        float y1 = function3(i);
        float y2 = function3(i);
        //float y3 = function2(i + deltares);
        //float y4 = function1(i + deltares);
        a = y1; //- y2;
        b = y2; //- y4;
        //std::cout<<y3<<std::endl;
        tra_result += trapeze_field(a,b,deltares);
        rect += rect_field(a,deltares);
    }

    std::cout<<"Pole(trapezami) = "<<tra_result<<std::endl; std::cout<<"Pole(prostokatami) = "<<rect<<std::endl;
    return 0;
}
