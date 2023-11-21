/*
문제 분석
독립시행이 아니다!
각각의 선택이 영향을 미친다
인줄알았는데
전체줄이 한 케이스가 아니라 각각임
n*n
*/
#include <iostream>
#include <cstring>
#include <stack>

using namespace std;

//struct

//var

char a,b;
char buffer[101];
//func

int init(){
    int buffer_len;
    int count=0;
    char a,b;
    cin>>buffer;
    buffer_len = strlen(buffer);

    for(int i=0;i<buffer_len;i++){
        a = buffer[i];
        if(a==')')continue;
        for(int j=i;j<buffer_len;j++){
            b = buffer[j];
            if(b==')')count++;

        }
    }
    return count;
}


int main(){

    cout<<init();



    return 0;
}