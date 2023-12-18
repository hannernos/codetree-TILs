#include <iostream>

using namespace std;

class Code{
private:
    string id;
    int level;

public:
    Code(string id="0",int level=0):id(id),level(level){};
    
    void print(){
        cout<<"user "<<id<<" ";
        cout<<"lv "<<level<<endl;
    }
};

int main() {
    // 여기에 코드를 작성해주세요.
    string id;
    int level;

    cin>>id>>level;
    Code tem0 = Code("codetree",10);
    tem0.print();

    Code tem = Code(id,level);
    tem.print();

    return 0;
}