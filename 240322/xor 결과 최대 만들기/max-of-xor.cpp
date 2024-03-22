#include <iostream>
#include<algorithm>
#include <vector>

using namespace std;


void init();
void run(int lev, int cnt, int val);
void print();

//var
int n,m;//정수 갯수, 뽑을 수 
int arr[30];
int ans;

int main() {
    // 여기에 코드를 작성해주세요.
    init();
    run(0,0,0);
    print();

    return 0;
}

void init(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    ans = -1;
}
void run(int lev, int cnt, int val){
    if(cnt == m){
        ans = max(ans,val);
        return;
    }

    if(lev == n){
        return;
    }
    run(lev+1,cnt,val);
    run(lev+1,cnt+1,val^arr[lev]);


}
void print(){
    cout<<ans;

}