#include <iostream>
#include <vector>
using namespace std;

//var
int n, m;
int maxRes = 0;

vector<int> mv; // 정수 리스트
vector<bool> visited;

vector<int> temres; // 현재 결과값
//func

void run(int depth) {
    if (depth == m) {
        int tem_sum = 0;
        for (int i = 0; i < m; i++) {
            tem_sum ^= temres[i]; 
        }

        maxRes = max(maxRes, tem_sum);
        return;
    }

    for (int i = 0; i < n; i++) {
        if (visited[i]) {
            continue;
        }

        visited[i] = true;
        temres.push_back(mv[i]);
        run(depth + 1);
        temres.pop_back();
        visited[i] = false;
    }
}

void init() {
    cin >> n >> m;
    mv.resize(n);
    visited.resize(n, false);
    
    for (int i = 0; i < n; i++) {
        cin >> mv[i];
    }
}

int main() {
    init();
    run(0);
    cout << maxRes;
    return 0;
}