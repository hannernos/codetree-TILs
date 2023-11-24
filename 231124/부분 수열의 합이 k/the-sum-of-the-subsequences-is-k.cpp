#include <iostream>
#include <vector>

#define ll long long
using namespace std;


//var
int n, k;

long long arr[1001] = { 0 }; //다 더해도 1억 안됨 - > long long 으로 그냥 ㄱ
vector<vector<long long>> mv;
int ans_cnt;
//func
void run() {
    //길이 제한 없이 모든 연속된 구간의 합 중에서 합이 k

    long long tem_sum;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            tem_sum = arr[i] - arr[j];
            if (tem_sum == k) {//계속 증가하는 오름차순이 아니라서 가지치기X
                ans_cnt++;
            }
        }
    }

}
void init() {
    int tem;
    cin >> n >> k;
    //mv.resize(n + 1);

    //mv.push_back(0);
    ans_cnt = 0;
    for (int i = 1; i <= n; i++) {
        cin >> tem;
        arr[i] = arr[i - 1] + tem;
        //mv[i].push_back(mv[i].back()+tem);
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    init();
    run();
    cout << ans_cnt;
    return 0;
}