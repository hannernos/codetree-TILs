#include <iostream>

using namespace std;

class MC{
    private:
        string a;
        char b;
        int c;
    public:
        void print(){
            cout<<"code : "<<a<<endl;
            cout<<"color : "<<b<<endl;
            cout<<"second : "<<c<<endl;                                                                                                                                                      

        }

    MC(){}
    MC(string a,char b,int c):a(a),b(b),c(c){}
};

string a;
char b;
int c;

void run(){

    cin>>a>>b>>c;
    MC han = MC(a,b,c);
    han.print();
}
int main() {
    // 여기에 코드를 작성해주세요.
    run();
    return 0;
}