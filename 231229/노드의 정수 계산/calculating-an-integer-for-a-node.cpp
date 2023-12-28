#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    vector<int> children;
}nodes[100001];

void propagateValue(int node) {
    for (int child : nodes[node].children) {
        propagateValue(child);
        if (nodes[child].data > 0) {
            nodes[node].data += nodes[child].data;
        }
    }
}

int main() {
    int n, t, a, p;
    cin >> n;

    for (int i = 2; i <= n; i++) {
        cin >> t >> a >> p;
        nodes[i].data = (t == 1) ? a : -a;
        nodes[p].children.push_back(i);
    }

    propagateValue(1);
    cout << nodes[1].data << endl;

    return 0;
}