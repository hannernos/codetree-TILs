#include <iostream>
#include <map>
using namespace std;


//var

int N;
int t;
char dir;
int mv;

bool f_flag;

int y,x;

map<char,pair<int,int>> mm={
{'E',{0,1}},
{'W',{0,-1}},
{'S',{1,0}},
{'N',{-1,0}}
};
//func


void run(){
//다시 시작점으로 되돌아오는 데 걸리는 시간을 출력합니다, 만약 N번 이동했는데 시작점으로 돌아오지 못했다면 -1을 출력합니다
    //dir로 b만큼 이동
    for(int i=0;i<mv;i++){
        t++;
        y = y+mm[dir].first;
        x = x+mm[dir].second;
    
        if(x==0&&y==0){
            f_flag = true;
            break;
        }
    
    }

}


void init(){
    t=0;
    y=0;x=0;
    f_flag = false;
    cin>>N;
    char a;//EWSN
    int b;
    for(int i=0;i<N;i++){
        cin>>a>>b;
        if(f_flag){
            continue;
        }

        dir = a;
        mv = b;
        run();
        // if(f_flag){
            
        //     continue;
        // }
    }
}


int main() {
    // 여기에 코드를 작성해주세요.
    init();

    if(y!=0||x!=x){
        t = -1;
    }
    cout<<t;
    return 0;
}