/*
부모노드 없으면 -1이 대신 주어짐 


*/
#include <iostream>
#include<vector>

using namespace std;


//var 

int n;
int arr[51];
int target;
int cnt;
vector<int> mv[55];
//func 

void init(){
    int tem;
    cnt=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>tem;

        tem++;

        arr[i] = tem;
        mv[tem].push_back(i);
    }
    cin>>target;
}


void run(int a){
//지워진 이후 트리에서의 리프노드의 갯수 출력

    if(!mv[a].empty()){
        cnt++;
        return;
    }


    for(auto ai : mv[a]){
        if(ai == target){
            continue;
        }
        run(ai);
    }

}
int main() {
    // 여기에 코드를 작성해주세요.
    init();

    run(0);
    cout<<cnt;
    return 0;
}