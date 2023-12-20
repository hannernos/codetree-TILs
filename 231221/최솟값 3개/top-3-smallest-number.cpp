#include <iostream>
#include <queue>
#define ll long long
using namespace std;
//func
ll run();
void init();

//var
priority_queue<int> pq;

int main() {
    // 여기에 코드를 작성해주세요.
    init();
    return 0;
}

ll tem_mul;

ll run(int n,int tem){
    int a,b,c;
    if(n<3){
        tem_mul = tem_mul*tem;

        pq.push(tem);
        return -1;
    }else if(n==3){
        tem_mul = tem_mul*tem;
        pq.push(tem);
        return tem_mul;
    }

    if(pq.top()>tem){
        tem_mul = (tem_mul*tem)/(pq.top());

        pq.pop();
        pq.push(tem);
    }
    return tem_mul;
}
void init(){
    int n;
    int tem;
    tem_mul = 1;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>tem;

        cout<<run(i,tem)<<endl;

    }
}