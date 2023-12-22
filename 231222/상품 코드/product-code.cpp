#include <iostream>

using namespace std;

class Node{
    private:
        string name;
        int age;


    public:
        void print(){
            cout<<"product "<<age<<" is "<<name<<endl;
        }

        Node(){}
        Node(string name,int age):name(name),age(age){}
};


void init();

int main() {
    // 여기에 코드를 작성해주세요.
    init();

    return 0;
}

void init(){
    int age;
    string name;
    cin>>name>>age;

    Node a = Node(name,age);
    Node b = Node("codetree",50);

    b.print();
    a.print();

}