/*
/2 -> 부모 노드
*2 -> 왼
*2+1-> 우

루트노드는 1

*/
#include <iostream>
#include<unordered_map>

using namespace std;
 

//var
int n;// 1 ~ 100,000
int arr[222000]={};
unordered_map<int,int> mm;


//func
void print(){//한 줄에 하나씩 각 노드의 부모노드 번호 출력
    //for(int i=) 부모노드를 출력해라 ? 그냥 map에 담으라는건가
    //진짜 tree를 구현하라는건가
    for(int i=2;i<=n;i++){
        cout<<mm[i]<<"\n";
    }
}

void run(){

}

void init(){
    int a,b;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a>>b; //연결된 두 정점 왼이 우의 부모

        if(arr[a*2]==0){//없다면
            arr[a*2]=b;
        }else{
            arr[a*2+1]=b;
        }
        mm[b]=a;

    }


}

int main() {
    // 여기에 코드를 작성해주세요.
    init();
    run();
    print();
    return 0;
}