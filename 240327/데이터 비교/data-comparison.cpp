#include <iostream>
#include <unordered_set>
using namespace std;

void init();

//var
unordered_set<int> ms;

int main() {
    // 여기에 코드를 작성해주세요.
    init();
    return 0;
}

void init(){
    int n;
    int a;
    int m;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a;
        ms.insert(a);
    }
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>a;
        if(ms.find(a)!=ms.end()){
            cout<<1;

        }else{
            cout<<0;
        }cout<<" ";
    }

}