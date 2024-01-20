#include <iostream>

using namespace std;

//var
int N;
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
int temx;
int temy;

void move(char tem,int item){
    switch (tem){
        case 'N':
                temy+=item;
            break;
        case 'E':
                temx+=item;
            break;
        case 'S':
                temy-=item;
            break;
        case 'W':
                temx-=item;
            break;
    }
}
void init(){
    temx =0;
    temy =0;

    cin>>N;
    int tem;
    char ctem;
    for(int i=0;i<N;i++){
        cin>>ctem>>tem;
        move(ctem,tem);
    }

    cout<<temx<<" "<<temy;
}
int main() {
    // 여기에 코드를 작성해주세요.
    init();
    return 0;
}