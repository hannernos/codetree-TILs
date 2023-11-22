#include <iostream>

using namespace std;
//var
//상하좌우
int dy[4] = {-1,1,0,0};//N S W E
int dx[4]= {0,0,-1,1};
int N;
int x=0;int y=0;
//func
void move(char a,int b){
    switch (a){
        case 'W':
            x+=b*dx[2];
            y+=b*dy[2];
            break;
        case 'E':
            x+=b*dx[3];
            y+=b*dy[3];
            break;
        case 'N':
            x+=b*dx[0];
            y+=b*dy[0];
            break;
        case 'S':
            x+=b*dx[1];
            y+=b*dy[1];
            break;

    }


}

void init(){ //0 0 start
    cin>>N;
    char a;
    int b;
    for(int i=0;i<N;i++){
        cin>>a>>b;
        move(a,b);
    }

}
int main() {
    // 여기에 코드를 작성해주세요.
    init();
    cout<<x<<" "<<-y;
    return 0;
}