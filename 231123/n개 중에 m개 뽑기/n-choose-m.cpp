#include <iostream>
#include <vector>
using namespace std;

//var
int N, M; // 1 ~ 10 

vector<int> ivisited;

//func
void run(int a, int start) { // a: depth, start: 시작 인덱스
    if (a == M) {
        for (int i = 0; i < M; i++) {
            cout << ivisited[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = start; i <= N; i++) {
        ivisited.push_back(i);
        run(a + 1, i + 1); // 다음 숫자는 현재 선택한 숫자 다음부터
        ivisited.pop_back();
    }
}

void init() {
    cin >> N >> M;
}

int main() {
    init();
    run(0, 1); // 초기 시작 인덱스는 1
    return 0;
}