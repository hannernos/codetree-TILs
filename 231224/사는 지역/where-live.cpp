#include <iostream>
#include<string>
using namespace std;

int max_idx;
string max_name = "aaaaaaaaaa";

class Node{
    private:
//elements 
    string name;
    string code; //번지수
    string region; //지역
    public:
//function
    void init(int idx){
        cin>>name>>code>>region;
        if(name>max_name){
            max_name = name;
            max_idx = idx;
        }

    }
    void print(){
        cout<<"name "<<name<<endl;
        cout<<"addr "<<code<<endl;
        cout<<"city "<<region<<endl;
    }


//constructor
    Node(){}
    Node(string name, string code, string region):name(name),code(code),region(region){}

}pool[11];

void init();


int main() {
    // 여기에 코드를 작성해주세요.
    init();
    return 0;
}

void init(){
    
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        pool[i].init(i);
        //사전순으로 이름이 가장 느린 사람의 자료를 출력
    }

    pool[max_idx].print();
}