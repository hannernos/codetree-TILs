/*dat*/
#include <iostream>
#include <unordered_map>

using namespace std;

//var
int n,m;

unordered_map<long long,long long> mm;
//func
void init(){
    int tem;
    cin>>n>>m;

    for(int i=0;i<n;i++){
        cin>>tem;
        if(mm.count(tem)>0){
            mm[tem]++;
        }else{
            mm[tem]=1;
        }
        
        }
    for(int j=0;j<m;j++){
        cin>>tem;
        cout<<mm[tem]<<" ";

    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    init();
    return 0;
}