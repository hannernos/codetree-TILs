#include <iostream>
#include<unordered_map>
using namespace std;

void init();
void run();
//var

int n;
unordered_map<string,int> mm;
int main() {
    // 여기에 코드를 작성해주세요.
    init();
    run();
    return 0;
}

void init(){
    string tem;
    int cnt,max_cnt;
    max_cnt = -1;

    cin>>n;
    for(int i=0;i<n;i++){
        cin>>tem;
        if(mm.find(tem)!=mm.end()){
            cnt = mm[tem] + 1;
        }else{
            cnt = 1;
        }

        mm[tem] = cnt;
        if(cnt>max_cnt){
            max_cnt = cnt;
        }
    }

    cout<<max_cnt;

}

void run(){


}