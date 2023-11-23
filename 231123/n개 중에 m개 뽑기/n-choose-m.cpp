#include <iostream>
#include <vector>
using namespace std;

//var
int N, M;// 1 ~ 10 

vector<int>mv;
vector<bool>visited;
vector<int> ivisited;
//func


void run(int a) { // a : idx, 1부터 시작
    // 만들 수 있는 모든 조합을 구하시오 
    if (a == M) {
        //출력하고 종료
//        for (auto i : ivisited) {
//            cout << i << " ";
//        }cout << "\n";

        for (int i = 0; i < M; i++) {
            cout << ivisited[M - 1 - i] << " ";
        }cout << "\n";
        return;
    }

    for (auto i : mv) {
        //visited
        if (visited[i]) {
            return;
        }
        ivisited.push_back(i);
        visited[i] = true;
        run(a + 1);
        visited[i] = false;
        ivisited.pop_back();
    }
}

void init() {
    cin >> N >> M;
    visited.push_back(false);
    for (int i = 1; i <= N; i++) {
        mv.push_back(i);
        visited.push_back(false);
    }

}
int main() {
    // 여기에 코드를 작성해주세요.
    init();
    run(0);
    return 0;
}