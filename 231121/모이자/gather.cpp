#include<iostream>

using namespace std;

//struct

//var
int n;
int arr[101];
//func
int abs(int a){
    if(a<0){
        a=-a;
    }
    return a;
}
int run(){
    int a,b;
    a=200000000;
    for(int i=1;i<=n;i++){
        b=0;
        for(int j=1;j<=n;j++){
            b+=arr[j]*abs(i-j);

        }
        if(b<a){
            a=b;
        }
    }
    return a;
}
void init(){
    cin>>n;
    int tem;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
}

int main(){

    init();
    cout<<run();



    return 0;
}