#include <iostream>
#include <iomanip>
#include <algorithm>

#define ll long long
using namespace std;

// var
int N, K;
int arr[100001];
ll prefixSum[100001];
int minValues[100001];  

void run() {
    double maxAvg = 0;
    int minValue;
    double currentAvg;
    for (int k = 1; k <= N - 2; k++) {
        ll totalSum = prefixSum[N] - prefixSum[k];

        minValue = minValues[k + 1];
        currentAvg = (double)(totalSum - minValue) / (N - k - 1);
        maxAvg = max(maxAvg, currentAvg);
    }
    cout << fixed << setprecision(2) << maxAvg << endl;
}

void init() {
    int minValue = 1e9;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        prefixSum[i] = prefixSum[i - 1] + arr[i];
    }
    for (int i = N; i > 0; i--) {
        minValue = min(minValue, arr[i]);
        minValues[i] = minValue;
    }
    

}

int main() {
    init();
    run();
    return 0;
}