#include <iostream>

using namespace std;

class Dong{
private : 
    string id;
    int lev;

public:
    Dong(){}

    void init(){
        cin>>id>>lev;
    }
    void run(){
        cout<<"user codetree lv 10\n";
        cout<<"user "<<id<<" lv "<<lev<<endl;
    }


};


int main(){
    Dong dong;
    dong.init();
    dong.run();
    return 0;
}