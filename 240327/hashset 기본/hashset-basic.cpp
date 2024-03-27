#include <iostream>
#include<unordered_set>

using namespace std;

void init();

//var

unordered_set<int> ms;

int main() {
    // 여기에 코드를 작성해주세요.
    int T;
    cin>>T;

    for(int i=0;i<T;i++){
        init();
    }
    return 0;
}

void init(){
    string inputStr;
    int inputInt;

    cin>>inputStr;
    cin>>inputInt;
    if(inputStr=="add"){
        ms.insert(inputInt);
    }else if(inputStr == "remove"){
        ms.erase(inputInt);
    }else if(inputStr == "find"){
        if(ms.find(inputInt) == ms.end()){
            cout<<"false";
        }else{
            cout<<"true";
        }cout<<"\n";
    }else{
        cout<<"?";

    }
    

}