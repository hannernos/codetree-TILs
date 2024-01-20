#include <iostream>

using namespace std;

int n;

int dy[4] = {1,0,-1,0};
int dx[4] = {0,1,0,-1};

int arr[101][101];

void init(){
    cin>>n;
    int count =0;
    int tem;

    for(int i=0;i<=100;i++){
        for(int j=0;j<=100;j++){
            arr[i][j]=0;
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>tem;
            if(tem>0){
                for(int k=0;k<4;k++){
                    arr[i+dy[k]][j+dx[k]]+=1;
                }
            }else{

            }
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(arr[i][j]>=3){
                count++;
            }
        }
    }

    cout<<count;
}




int main() {
    // 여기에 코드를 작성해주세요.
    init();
    return 0;
}