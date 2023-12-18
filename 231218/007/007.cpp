#include <iostream>
#include<cstring>
using namespace std;


//var
class Node{
private:
    char a[11];
    char b;
    int c;
public:
    Node(char* pa,char b,char c):b(b),c(c){
        strcpy(a, pa);
    }


    void print(){
        cout<<"secret code : "<<a<<"\n";
        cout<<"meeting point : "<<b<<"\n";
        cout<<"time : "<<c<<"\n";

    }

};

//func



void init();

int main() {
    // 여기에 코드를 작성해주세요.
    init();
    return 0;
}

void init(){
    char a[11];
    char b;
    int c;
    cin>>a>>b>>c;
    Node mN(a,b,c);
    mN.print();
}