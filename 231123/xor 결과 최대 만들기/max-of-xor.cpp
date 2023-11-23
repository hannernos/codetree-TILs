#include <iostream>
#include <vector>
#include<unordered_map>
using namespace std;

//var
int n;
int m;
int maxRes;

vector<int> mv; // 정수 리스트 받기 
vector<bool>visited;

vector<int> temres; // 현재 결과값
unordered_map<int, int> mm;
//func

void run(int depth) {
    //m개의 숫자를 뽑아 
    //모두 xor한 결과의 최댓값을 출력하는 코드를 작성해보세요.
    //이진법으로 변환하고 하라는 건가 ?
    if (depth == m) {
        // 길이 만족, 종료
        //최댓값 비교하고 갱신
        int tem_sum= temres[0];
        //본문에서만 m이고 for문으로 ㄱㄱ
        for (int i = 0; i < m-1;i++) {
            tem_sum = temres[i] ^ temres[i + 1];
        }

        if (tem_sum > maxRes) {
            maxRes = tem_sum;
        }
    }

    for (int i = 1; i <= n; i++) {

        if (visited[i]) {
            continue;
        }

        visited[i] = true;
        temres.push_back(i);
        run(depth + 1);
        temres.pop_back();
        visited[i] = false;
    }

}
void init() {
    int tem;
    maxRes = 0;
    cin >> n >> m;

    visited.push_back(false);
    for (int i = 1; i <= n; i++) {
        cin >> tem;
        mv.push_back(tem);
        visited.push_back(false);
        mm[i] = tem;
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    init();
    run(0);

    cout << maxRes;
    return 0;
}