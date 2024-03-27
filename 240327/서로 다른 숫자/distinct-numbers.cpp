#include <iostream>
#include<unordered_set>

using namespace std;

void init();
void run();

//var


int main() {
    // 여기에 코드를 작성해주세요.
    init();
    run();
    return 0;
}

void init(){
    unordered_set<int> ms;
    int n;
    int a;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a;
        ms.insert(a);
    }

    cout<<ms.size();
}
void run(){

}