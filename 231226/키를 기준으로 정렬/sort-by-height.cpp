#include <iostream>
#include <algorithm>
using namespace std;





class Node{
    public:
        string name;
        int h,w;

        void init(){
            cin>>name>>h>>w;
        }

        void print(){
            cout<<name<<" "<<h<<" "<<w<<endl;
        }



        Node(){}

}nodes[11];

bool cmp(Node a,Node b){
    return a.h<b.h;
}


int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        nodes[i].init();
    }
    sort(nodes,nodes+n,cmp);
    for(int i=0;i<n;i++){
        nodes[i].print();
    }


    return 0;
}