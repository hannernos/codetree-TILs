#include <iostream>
#include<unordered_map>
using namespace std;

class Node {
public:
    int data;
    Node* nxt;
    Node* prev;

    Node() {}
    Node(int data):data(data),nxt(nullptr),prev(nullptr) {}
    ~Node() {}


}nodes[100001];
int nodeCnt;

class MyList {
public:
    Node* root;

    void connect(Node* a, Node* b) {
        a->nxt = b;
        b->prev = a;
    }

    void disconnect(Node* a, Node* b) {
        a->nxt = nullptr;
        b->prev = nullptr;
    }

    void oper1(int i) {
        //i번노드를 그 노드가 속해 있던 연결리스트에서 뽑아서 단일노드가 되게 함
        //1. 111 앞뒤가 다 있을 때-> 이어줘야 함
        //2. 110 앞만 있을 때 -> 
        //3. 011 뒤만 있을 때 -> 
        bool a = (nodes[i].prev != nullptr);
        bool b = (nodes[i].nxt != nullptr);
        Node* preNode = nodes[i].prev;
        Node* nxtNode = nodes[i].nxt;
        if (a&&b) {
            disconnect(preNode, &nodes[i]);
            disconnect(&nodes[i], nxtNode);

            connect(preNode, nxtNode);
        }
        else if (a) {
            disconnect(preNode, &nodes[i]);
            //nodes[i].prev->nxt = nullptr;
            //nodes[i].prev = nullptr;
        }
        else if (b) {
            disconnect(&nodes[i], nxtNode);
            //nodes[i].nxt->prev = nullptr;
            //nodes[i].nxt = nullptr;
        }
        else {
        //이상한 입력값
            //cout << "unexpected oper1 input\n";
        }
        
    }
    void oper2(int i, int j) {
        //단일 노드인 j번 노드를 i번 노드 앞에 삽입
        //i번 노드 앞에 이미 있다면
        if (nodes[i].prev != nullptr) {
            Node* preNode = nodes[i].prev;
            disconnect(preNode, &nodes[i]);

            connect(preNode, &nodes[j]);
            connect(&nodes[j], &nodes[i]);
        }
        else {
        //i번 노드 앞에 없다면
            nodes[j].nxt = &nodes[i];
            nodes[i].prev = &nodes[j];

            root = &nodes[j];
        }

        


    }
    void oper3(int i, int j) {
        //단일 노드인 j번 노드를 i번 노드 뒤에 삽입
        if (nodes[i].nxt != nullptr) {
            Node* nxtNode = nodes[i].nxt;
            disconnect(&nodes[i], nxtNode);

            connect(&nodes[i], &nodes[j]);
            connect(&nodes[j], nxtNode);
        }
        else {
            //i번노드 뒤에 없다면
            //connect(&nodes[i], &nodes[j]);
        
            nodes[i].nxt = &nodes[j];
            nodes[j].prev = &nodes[i];

        }
    }
    void oper4(int i) {
        //i번 노드의 이전 노드와 다음 노드의 번호를 출력 (존재하지 않으면 0 출력)
        if (nodes[i].prev != nullptr) {
            cout << nodes[i].prev->data;
        }
        else {
            cout << "0";
        }cout << " ";

        if (nodes[i].nxt != nullptr) {
            cout << nodes[i].nxt->data;
        }
        else {
            cout << "0";
        }cout << "\n";
    }
    //for debug
    void print() {
        cout << "print: ";
        Node* tem;
        tem = root;
        while (tem != nullptr) {
            cout << tem->data<<" ";
            tem = tem->nxt;
        }

        cout << endl;
    }

};

MyList ml;

void init();
void getOperator();
int main() {
    // 여기에 코드를 작성해주세요.
    init();
    getOperator();
    return 0;
}

void init() {
    int N;
    int Q;
    cin >> N >> Q;

    for (int i = 0; i <= N; i++) {
        nodes[i].data = i;
    }


    //run
    for (int i = 0; i < Q; i++) {
        getOperator();
        //ml.print(); // for debug
    }
    nodeCnt = 0;
    //연산을 마친 후 1번부터 n번까지 각 노드의 다음 노드의 번호를 차례대로 한줄에 출력 (존재하지 않으면 0 출력)
    for (int i = 1; i <= N; i++) {
        if (nodes[i].nxt != nullptr) {
            cout << nodes[i].nxt->data;
        }
        else {
            cout << 0;
        }
        cout << " ";
    
    }

}

void getOperator() {
    int operNum;
    int i, j;
    cin >> operNum;
    switch (operNum) {
    case 1:
        cin >> i;
        ml.oper1(i);
        break;

    case 2:
        cin >> i >> j;
        ml.oper2(i,j);
        break;

    case 3:
        cin >> i >> j;
        ml.oper3(i, j);
        break;

    case 4:
        cin >> i;
        ml.oper4(i);
        break;

    default:
        break;
    }

}