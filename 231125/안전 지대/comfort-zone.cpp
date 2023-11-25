#include<iostream>

using namespace std;

//var
int N,M;
int max_h;
int ans;
int ans_h;
int arr[51][51];
bool visited[51][51]={false};

int dir_y[4] = {-1,0,1,0};
int dir_x[4] = {0,1,0,-1};
//func



int tem_idx;


bool cango(int y,int x,int k){
    if(y<1||y>N||x<1||x>M)return false;
    if(arr[y][x]<=k) return false;
    return !visited[y][x];
}


void run2(int y,int x,int k){

    int dx,dy;

    for(int i=0;i<4;i++){
        dy = y + dir_y[i];
        dx = x + dir_x[i];

        if(!cango(dy,dx,k))continue;

        visited[dy][dx]=true;
        run2(dy,dx,k);
        //visited[dy][dx]=false;

    }

}

void run(){
    ans =0;
    int tem_ans=0;
    int myzone = 0;
    ans_h = 0;


    for(int i=1;i<=max_h;i++){
        fill(&visited[0][0], &visited[0][0] + 51*51, false);
        myzone = 0;
        for(int j=1;j<=N;j++){
            for(int k=1;k<=M;k++){
                if(cango(j,k,i)){
                    run2(j,k,i);
                    myzone++;
                }
            }
        }
        
        if(ans<=myzone){
            ans = myzone;
            ans_h = i;
        }
    }

}

void init(){
    int tem;
    max_h=0;
    cin>>N>>M;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            cin>>tem;
            if(tem>max_h)max_h = tem;
            arr[i][j]=tem;//각 집의 높이
        }
    }
}
int main(){
    init();
    run();
    cout<<ans_h<<" "<<ans;

    return 0;
}