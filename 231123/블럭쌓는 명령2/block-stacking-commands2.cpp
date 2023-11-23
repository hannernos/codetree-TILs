#include <iostream>

using namespace std;

//var
int n;
int k;

int arr[101];
//func
void print(){
    int maxi=1;
    for(int i=1;i<=k;i++){
        if (arr[i]>maxi){
            maxi = arr[i];
        }
    }
    cout<<maxi;
}
void run(int a,int b){
//첫 번째 줄에 각 칸에 있는 블럭의 수 중 최댓값을 출력합니다.
    for(int i=a;i<=b;i++){
        arr[i]+=1;
    }
}

void init(){
    int a,b;
    cin>>n>>k;
    for(int i=1;i<=k;i++){
        cin>>a>>b;
        run(a,b);

    }   
}

int main() {
    // 여기에 코드를 작성해주세요.
    init();

    print();
    return 0;
}