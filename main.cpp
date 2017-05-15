#include <iostream>

using namespace std;

struct Math{


    int pow(int val, int st){
        int tmp = 1;
        for(int i = 0; i < st; i++){
            tmp = tmp * val;
        }
        return tmp;
    }

    int from28ToDec(char buf[], int system){
        int res = 0;
        int index = -1;
        int int_buf[8] = {0};

        for(int i = 0; i < sizeof(buf); i++){
            int get = (int)(buf[i]);
            //cout<<get<<endl;
            if(get <= 56 & get >= 48){
                index++;
                int_buf[i] = get;
                //cout<<get<<endl;
            }

        }

        for(int it = 0; it < sizeof(buf); it++){
            int get2 = (int)(int_buf[it]-48);

            if(get2 < system & get2 >= 0){
                //cout<<pow(system,index)*get2<<"\t:\t"<<index<<"\t:\t"<<get2<<endl;
                res+= pow(system,index)*get2;
                index--;
            }
        }
        return res;
    }

    int fromDecTo29(int conv,int system){
        int div_res = 0 ,rest = 0;
        int tmp[10] = {0};
        int index = 0;

        while(conv != 0){
            div_res = conv/system;
            rest = conv-(div_res*system);
            conv = div_res;
            tmp[index] = rest;
            index++;
        }

        for(int i = sizeof(tmp)/5; i >= 0; i--){
            if(tmp[i] > 0){
                cout<<tmp[i];
            }
        }
    }

    void fromDecToHex(int conv){
        char buf[100] = {};
        int rest = 0,i = 0,div_res = 0;

        while(conv != 0){

            div_res = conv/16;
            rest = conv-(div_res*16);
            conv = div_res;
            if(rest >= 0&rest <= 9){
                char tmp = (char)(rest+48);
                buf[i] = tmp;
            }else if(rest <=15 & rest >= 10){
                char tmp = (char)(rest+(55));
                buf[i] = tmp;
            }
            i++;
        }

        for(int i = sizeof(buf)/5; i >= 0; i--){
            cout<<buf[i];
        }
    }
};

int main()
{
    Math m;
    char b[8];

    int ex_choice;

    while(true){
        cout<<"Podaj nr. zadania: "<<endl;
        cin>>ex_choice;
        switch(ex_choice){
            case 1:
                int system,conv;
                    cout<<"Podaj system: "<<endl;
                    cin>>system;
                    cout<<"Podaj wartosci:"<<endl;
                    cin>>conv;
                if(system <= 9 & system >= 2){
                    m.fromDecTo29(conv,system);
                }else{
                    cout<<"W tym zadaniu zakres systemow jest od 2-9."<<endl;
                }
            break;
            case 2:
                int conv2;
                cout<<"Podaj wartosc do konwersji: "<<endl;
                cin>>conv2;
                m.fromDecToHex(conv2);
                cout<<endl;
                break;
            case 3:
                char buf[8];
                int system2;
                cin>>buf;
                cin>>system2;
                cout<<m.from28ToDec(buf,system2)<<endl;
                break;
        }
    }
    return 0;
}
