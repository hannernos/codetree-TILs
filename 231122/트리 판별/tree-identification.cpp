/*
들어오는 간선이 하나도 없는 루트노드 1개 존재 
루트노드를 제외한 모든 노드는 반드시 하나의 들어오는 간선이 존재
루트노드에서 간선을 사용해서 자신을 제외한 모든 노드에 도달가능하며 유일한 경로
*/

#include <iostream>
#include <vector>
#include <set>

using namespace std;

//var
int m; // 1000
       // 노드 번호 1 ~ 10000

vector<int> mv[1001];
bool arr[1001];
bool condition1;
bool condition2;
bool condition3;

set<int> ms;

int node_cnt;
//func

void init(){
    int a,b;
    
    condition1 = false;
    condition2 = false;
    condition3 = false;
    
    cin>>m;

    for(int i=0;i<m;i++){
        arr[i]=false;
    }

    for(int i=0;i<m;i++){
        //a -> b
        cin>>a>>b;

        //들어오는 간선 갯수 조건 확인
        ms.insert(a);
        //condition 1 확인
        if(arr[b]){ //이미 부모가 있으면
            condition1 = true;
        }
        arr[b]=true;

        mv[a].push_back(b);
    }


}

void run2(int r_n){//3번 조건
    bool ret = true; //갯수 일치하면 ( 조건 통과하면 false )
    node_cnt++;
    for(auto a : mv[r_n]){
        run2(a);
    }
    return;
}

int run(){
//트리일 경우 1 아닐 경우 0
/*
들어오는 간선이 하나도 없는 루트노드 1개 존재 
루트노드를 제외한 모든 노드는 반드시 하나의 들어오는 간선이 존재
루트노드에서 간선을 사용해서 자신을 제외한 모든 노드에 도달가능하며 유일한 경로
*/
//condition 2
    if(condition1){
        return 0;
    }
//condition 1
    //condition 2, 이름 바꿈 그냥 귀찮아서 바꿔서 진행
    int orphan_cnt=0;
    int orphan_n=0;
    for(auto a : ms){
        if(!arr[a]){//부모가 없으면
            orphan_cnt++;
            orphan_n = a;
        }
    }
    if(orphan_cnt!=1){
        return 0;
    }
//condition 3 
//루트노드에서 간선을 사용해서 자신을 제외한 모든 노드에 도달가능하며 유일한 경로

    //순회 , 카운트로 확인
    node_cnt = 0;
    run2(orphan_n);
    if(node_cnt==(ms.size())){
        return 0;
    }
    return 1;
}   


int main() {
    // 여기에 코드를 작성해주세요.
    init();
    cout<<run();
    return 0;
}