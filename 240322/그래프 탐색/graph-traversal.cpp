#include<iostream>
#include<vector>

using namespace std;

void init();
void run(int lev);
void print();

//var
int n,m;
int cnt;

int arr[1111][1111];
bool visited[1111];
int main() {

	init();
	run(1);
	print();

	return 0;
}

void init() {
    int v1,v2;

    cin>>n>>m;
    for(int i=0;i<n+1;i++){
        visited[i]=false;
    }
    for(int i=0;i<m;i++){
        cin>>v1>>v2;
        arr[v1][v2]=1;
        arr[v2][v1]=1;

    }

    visited[1] = true;
}

void run(int lev) {
    for(int cur_v=0;cur_v<n+1;cur_v++){
        if(arr[lev][cur_v]&&!visited[cur_v]){
            visited[cur_v] = true;
            cnt++;
            run(cur_v);
        }

    }
}

void print() {
    cout<<cnt;
}