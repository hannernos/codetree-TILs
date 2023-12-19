#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>

#define ll long long
using namespace std;

// var
int N, K;
vector<int> arr;
vector<ll> prefixSum;

void run() {
    double maxAvg = 0.0;
    for (int k = 1; k <= N - 2; k++) {
        ll totalSum = prefixSum[N] - prefixSum[k];
        int minValue = *min_element(arr.begin() + k + 1, arr.end()); 
        double currentAvg = (double)(totalSum - minValue) / (N - k - 1);
        maxAvg = max(maxAvg, currentAvg);
    }
    cout << fixed << setprecision(2) << maxAvg << endl;
}

void init() {
    cin >> N;
    arr.resize(N + 1);
    prefixSum.resize(N + 1);

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        prefixSum[i] = prefixSum[i - 1] + arr[i];
    }
}

int main() {
    init();
    run();
    return 0;
}