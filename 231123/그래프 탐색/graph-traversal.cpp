#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<vector<int>> graph;
vector<bool> visited;
int count = 0;

void run(int node) {
    visited[node] = true;
    for(int adj : graph[node]) {
        if(!visited[adj]) {
            if(adj != 1) count++;
            run(adj);
        }
    }
}

int main() {
    cin >> N >> M;
    graph.resize(N + 1);
    visited.resize(N + 1, false);
    
    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    run(1);
    cout << count;
    return 0;
}