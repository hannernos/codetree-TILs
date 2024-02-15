#include <iostream>

using namespace std;

void init();
void run(int x, int y);
bool check(int x,int y);

//var
bool arr[102][102];

int main() {
    // 여기에 코드를 작성해주세요.
    init();
    return 0;
}

void init(){
    int N;
    int M;
    int r,c;

    for(int i=0;i<102;i++){
        for(int j=0;j<102;j++){
            arr[i][j]=false;
        }
    }

    cin>>N>>M;
    for(int i=0;i<M;i++){
        cin>>r>>c;
        run(r,c);
    }

}

void run(int x,int y){
    //색칠
    arr[y][x] = true;
    if(check(x,y)){
        cout<<1;
    }else{
        cout<<0;
    }
    cout<<"\n";
}

bool check(int x,int y){
    int count = 0;
    if(arr[y+1][x])
        count++;
    if(arr[y][x+1])
        count++;
    if(arr[y-1][x])
        count++;
    if(arr[y][x-1])
        count++;

    if(count == 3){
        return true;
    }
    return false;
}