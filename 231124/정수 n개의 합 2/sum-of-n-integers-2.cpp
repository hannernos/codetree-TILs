#include <iostream>
#include<vector>
using namespace std;


//var
int n;//100000
int k;
vector<int> mv;
int top;

int max_i = 0;
int tem_i = 0;

//int arr[]
//func
void run() {
    //k만큼 보기

    for (int i = k; i <= n; i++) {
        tem_i = mv[i] - mv[i-k];
        if (max_i < tem_i) {
            max_i = tem_i;
        }
    }

}
// idx 전부 1부터 시작
void init() {
    cin >> n >> k;
    int tem;
    mv.push_back(0);
    for (int i = 1; i <= n; i++) {
        cin >> tem;     
        mv.push_back(mv.back() + tem);

    }

}


int main() {
    // 여기에 코드를 작성해주세요.
    init();
    run();
    cout << max_i;
    return 0;
}