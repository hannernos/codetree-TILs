/*
문제 해결 전략
제일 오른쪽부터 1씩 증가하면서 N이 되면 그 전을 1씩 증가하면서 제일 왼쪽이 N이 되면 끝
*/
#include <iostream>

using namespace std;

//func
void init();
void run(int lev);
void check();
void print();

//var
int K, N;
int cnt;
int arr[10];

int a, b, c;

int main() {
    init();
    run(N);

    return 0;
}


void init(){
    //input
    cin >> K >> N;

    //init;
    for (int i = 0; i <= N; i++) {
        arr[i] = 1;
    }
    cnt = 0;

    }

void run(int lev) {

    print();
    arr[lev] = arr[lev] + 1;
    check();
    if (arr[0] == 2) {
        return;
    }

    run(lev);
    

}
void check(){
    for (int i = N; i >= 1; i--) {
        if (arr[i] > K) {
            arr[i] = 1;
            arr[i - 1] = arr[i - 1] + 1;
        }
    }

}

void print() {
    for (int i = 1; i <= N; i++) {
        cout << arr[i] << " ";
    }cout << "\n";
}