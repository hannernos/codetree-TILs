#include <iostream>

using namespace std;

class Student{
private:
    char name;
    int score;

public:

    Student(){}
    Student(char name = 'a',char score = 0):name(name),score(score){}

    void print(){
        cout<<this->name<<" "<<this->score<<endl;
    }


};

void run();
int main() {
    // 여기에 코드를 작성해주세요.
    run();
    return 0;
}


void run(){
    int max_score=1e9;
    char max_name='a';

    char name;
    int score;
    for(int i=0;i<5;i++){
        cin>>name>>score;

        if(max_score>score){
            max_score = score;
            max_name = name;
        }

    }
    cout<<max_name<< " " << max_score;
}