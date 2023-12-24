#include <iostream>

using namespace std;

int max_idx;
string max_date="9999";

class Node{
    private:
        string date;
        string day;
        string weather;
    public:
        void init(int i){
            cin>>date>>day>>weather;

            if(date<max_date && weather =="Rain"){
                //비가오는 중 근시일
                max_idx = i;
                max_date = date;
            }

        }
        void print(){
            cout<<date<<" "<<day<<" "<<weather<<endl;
        }

        Node(){}

}nodes[101];


int main() {
    // 여기에 코드를 작성해주세요.
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        nodes[i].init(i);
    }
    nodes[max_idx].print();

    return 0;
}