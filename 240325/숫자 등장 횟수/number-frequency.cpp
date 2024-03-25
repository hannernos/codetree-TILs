#include <iostream>
#include<unordered_map>

using namespace std;

void init();
void run();

unordered_map<int,int> mm;

int main() {
    // 여기에 코드를 작성해주세요.
    init();
    return 0;
}


void init(){

    int n,m;
    int a;
    int b;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a;
        if(mm.find(a)!=mm.end()){
            mm[a] = mm[a] + 1;
        }else{
            mm.insert({a,1});
        }
    }

    for(int j=0;j<m;j++){
        cin>>b;
        if(mm.find(b)!=mm.end()){
            cout<<mm[b]<<" ";
        }else{
            cout<<"0 ";
        }
    }

}

void run(){


}