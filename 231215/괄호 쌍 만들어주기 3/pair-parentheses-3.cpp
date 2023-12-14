#include <iostream>
#include <cstring>

using namespace std;

//var
char arr[101];
int cnt_arr[101]; // 이 뒤에 )가 몇개 있는지
int length;
int cnt;
int tem_cnt;
//func

void run(){

    int j;
    for(int i=0;i<length;i++){
        j = length - (i+1); 
        if(arr[j]==')'){
            tem_cnt++;
        }
        cnt_arr[j] = tem_cnt;
        //cout<<tem_cnt<<endl;
    }



    for(int i=0;i<length;i++){
        if(arr[i]=='('){
            cnt+=cnt_arr[i];
        }
        else{
            
        }
    }
    cout<<cnt;
}

void init(){

    cin>>arr;
    length = strlen(arr);
    cnt = 0;
    tem_cnt = 0;
}

int main() {
    // 여기에 코드를 작성해주세요.
    init();
    run();
    return 0;
}