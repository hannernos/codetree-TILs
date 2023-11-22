/*
1~4, 연달아 K만큼 같은숫자 -> 아름다운 수
13331

다돌면서 검증은 젱리 비효율적
1 ~ 3 처음 돌리고 같은거는 depth k만큼 올리고 하드코딩으로 박으면서 카운트 세기


%주의사항 11 22 333 333 < 아름다운수 포함
*/

#include <iostream>

using namespace std;

//var
int n;// 1 ~ 10
int cnt;
int tem_length;
//func
void run(int a){
    //1 ~ n
    tem_length = tem_length+a;
    //a만큼 반복
    //만약 길이 넘어간다면 카운트 세지 말고 return
    if(tem_length>n){
        tem_length = tem_length-a;
        return;
    }
    //딱 길이만큼이라면 카운트 올리고 return
    if(tem_length==n){
        cnt++; 
        tem_length = tem_length-a;
        return; //여기서 무한루프 조심
    }
    //길이 안넘어간다면 계속 재귀
    for(int i=1;i<=4;i++){
        run(i);
    }


}

void init(){
    cin >> n;
    cnt = 0 ;

}

int main() {
    // 여기에 코드를 작성해주세요.
    init();
    for(int i=1;i<=4;i++){
        tem_length=0;
        run(i);
    }

    cout<<cnt;
    return 0;
}