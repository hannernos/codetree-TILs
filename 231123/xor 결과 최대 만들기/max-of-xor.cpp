#include <iostream>
#include <vector>
using namespace std;

//var
int n, m;
int maxRes = 0;

vector<int> nums; 
vector<bool> visited;

void run(int depth, int start, int xorSum) {
    if (depth == m) {
        maxRes = max(maxRes, xorSum); 
        return;
    }

    for (int i = start; i < n; i++) {
        if (visited[i]) {
            continue;
        }

        visited[i] = true;
        run(depth + 1, i + 1, xorSum ^ nums[i]); 
        visited[i] = false;
    }
}

void init() {
    cin >> n >> m;
    nums.resize(n);
    visited.resize(n, false);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
}

int main() {
    init();
    run(0, 0, 0);
    cout << maxRes;
    return 0;
}