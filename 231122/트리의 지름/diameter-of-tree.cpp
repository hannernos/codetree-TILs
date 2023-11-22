#include <iostream>
#include <vector>
using namespace std;

//var
int v;
vector<vector<pair<int,int>>> tree;
vector<bool> visited;

int maxDistance;
int maxNode;

void run(int node, int distance){
    visited[node] = true;

    if(distance > maxDistance){
        maxDistance = distance;
        maxNode = node;
    }

    for(auto a: tree[node]){
        if(!visited[a.first]){
            run(a.first,distance+(a.second));
        }
    }
}

//func
void init(){
    int a,b,c;
    cin>>v;

    tree.resize(v+1);
    visited.resize(v+1,false);

    for(int i=1;i<v;i++){
        cin>>a>>b>>c;
        tree[a].push_back(make_pair(b,c));
        tree[b].push_back(make_pair(a,c));
    }
    run(1,0);
    fill(visited.begin(),visited.end(),false);
    maxDistance = 0;
    run(maxNode,0);
    cout<<maxDistance<<endl;
}

int main() {
    // 여기에 코드를 작성해주세요
    init();
    return 0;
}