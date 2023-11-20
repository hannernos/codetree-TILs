/*
*/

#include <iostream>
#include <vector>

using namespace std;


int n;//1 ~ 100
int a[101];
vector<int> mv;

int abs(int a){
    if(a<0){
        a=-a;
    }
    return a;
}

int run(){
    int min_val=9000;
    int tem_val;
    int j=0;
    vector<int>::iterator it;

    for(int i=0;i<n;i++){
        tem_val=0;
        j=1;
        for(it=mv.begin();it!=mv.end();it++){
            j++;
            tem_val=tem_val+(*it)*abs(n-j);
        }

        if(tem_val<min_val){
            min_val = tem_val;
        }
    }
    return  min_val;
}

void init(){
    cin>>n;
    int tem;
    for(int i=0;i<n;i++){
        cin>>tem;
        mv.push_back(tem);
    }

}


int main() {
    // 여기에 코드를 작성해주세요.
    init();
    cout<<run();
    return 0;
}