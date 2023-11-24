#include <iostream>


using namespace std;

int n, k;
int arr[501][501] = { 0 };

int max_square;
int tem_square;

void run() {
    max_square = 0;
    for (int i = k; i <= n; i++) {
        for (int j = k; j <= n; j++) {
            tem_square = arr[i][j] - arr[i - k][j - k];
            if (tem_square > max_square) {
                max_square = tem_square;
            }
        }
    }

}

//1부터 시작
void init() {
    int tem;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> tem;
            arr[i][j] = arr[i - 1][j - 1] + tem;
        }
    }
}

int main() {
    // 여기에 코드를 작성해주세요.
    init();
    run();
    cout << max_square;
    return 0;
}