#include <iostream>
#include <cmath>

using namespace std;


struct Math{
    void fromBinToDec(char dana[]){
        int pozycja = -1;
        int res = 0;
        float res2 = 0;

        for(int i = 0; i <= sizeof(dana); i++){
            char get = dana[i];
            if((int)get == 44 | (int)get == 46){
               pozycja = i;
            }
        }

        int tmp = pozycja-1;
        for(int i = 0; i < sizeof(dana); i++){
            int get = ((int)dana[i] - 48);
            if(i < pozycja){
                res += (pow(2,tmp)*get);
                tmp -= 1;

            }else if(pozycja < i){
                res2 += (pow(2,tmp)*get);
                tmp -= 1;
            }

        }
        cout<<res+res2<<endl;
    }
};


int main()
{
    Math m;
    char dana[10];
    cin>>dana;
    m.fromBinToDec(dana);
    return 0;
}
