/*
문자열 A가 주어지면 괄호 쌍 가능한 숫자 구하는 프로그램 작성
how to solve?
-> 변수 2개 만들고 
*/
#include <iostream>
#include <stack>
#include<cstring>
using namespace std;

//struct

//var
//문자열의 길이 1 ~ 100
int a,b;
char buffer[101];
int buffer_len;
stack<char> ms;

int count_answer;
//func

void init(){
    a=0;
    b=0;
    count_answer=0;
    cin>>buffer;
    buffer_len = strlen(buffer);
    char ca,cb;
    for(int i=0;i<buffer_len;i++){
        // ms.insert(buffer[i]);
        ca = buffer[i];
        for(int j=i;j<buffer_len;j++){
            cb = buffer[j];
            if((ca=='(')&&(cb==')')){
                count_answer++;
            }
        }
    }
}
void run(){
    

}

int main() {
    // 여기에 코드를 작성해주세요.
    init();
    run();
    cout<<count_answer;
    
    return 0;
}