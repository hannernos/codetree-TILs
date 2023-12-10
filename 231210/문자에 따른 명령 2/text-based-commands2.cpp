#include <iostream>
#include <cstring>

using namespace std;

int y,x;
int dir_num;
int dy[4] = { 0,-1, 0, 1};
int dx[4] = { 1, 0,-1, 0};

char input_buffer[100001];
int n;
//func

void forward(){
    switch (dir_num){
        case 0:
            x++;
            break;
        case 1:
            y++;
            break;
        case 2:
            x--;
            break;
        case 3:
            y--;
            break;
        default:
            break;
    }
}

void rotate(){
    
    char tem;
    for(int i=0;i<n;i++){
        tem = input_buffer[i];
        if (tem == 'L'){
            dir_num = (dir_num - 1 + 4) % 4;
        }else if(tem =='R'){
            dir_num = (dir_num + 1) % 4;
        }else if(tem == 'F'){
            y = y + dy[dir_num];
            x = x + dx[dir_num];
            //forward();
        }else{

        }

    }

    cout<<x<< ' '<<y;
    return ;
}


void init(){
    //string tem;
    //char tem[100001];
    dir_num = 3;
    y=0;
    x=0;

    cin>>input_buffer; // L R F 
    n = strlen(input_buffer);
    return ;
}


int main() {
    // 여기에 코드를 작성해주세요.
    init();
    rotate();

    return 0;
}