#include <iostream>
#include <list>
using namespace std;


//var
int n;// 100000
list<int> ml;
//func
void run(){
    int tem;

    while(n>0){
        tem = n%2;
        ml.push_front(tem);
        n=n/2;
    }
}

void print(){
    while(!ml.empty()){
        cout<<ml.front();
        ml.pop_front();
    }

}
void init(){
    cin>>n;
}
int main() {
    // 여기에 코드를 작성해주세요.
    init();
    run();
    print();
    return 0;
}