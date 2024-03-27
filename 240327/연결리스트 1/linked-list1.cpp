#include <iostream>

using namespace std;

class Node {
public:
	string data;
	Node* nxt;
	Node* prev;

	//
	string getData() {
		return data;
	}

	void setData(const string& data) {
		this->data = data;

	}

	Node() {
		this->data = "init";
		this->nxt = nullptr;
		this->prev = nullptr;
	}
	Node(const string& data) : data(data), nxt(nullptr),prev(nullptr) {}
	Node(const string& data, Node* nxt) : data(data), nxt(nxt),prev(nullptr) {}
	~Node() {}

}nodes [5000];

int nodecnt;

class LinkedList {
public:
	Node* root;
	Node* tail; //쓸모X
	Node* cur;

	LinkedList() :root(nullptr), tail(nullptr),cur(nullptr){}


	void prepend(string data) {
		Node* tem = &nodes[nodecnt++];
		tem->setData(data);
		//이전 노드가 있을때
		if (cur->prev != nullptr) {
			
			tem->prev = cur->prev;
			cur->prev = tem;
		}
		else {
		//이전 노드가 없을 때
			cur->prev = tem;
			root = tem;
		
		}
		
		
		

	}

	void append(string data) {
		Node* tem = &nodes[nodecnt++];
		tem->setData(data);
		//다음 노드 있을 때
		if (cur->nxt != nullptr) {
			tem->nxt = cur->nxt;
			cur->nxt = tem;
		}
		else {
			//다음 노드 없을 때
			cur->nxt = tem;
			tail = tem;
		}


	}

	void oper() {
		int operNum;
		string S_value;

		cin >> operNum;
		switch (operNum) {
		case 1:
			cin >> S_value;
			this->prepend(S_value);
			break;
		case 2:
			cin >> S_value;
			this->append(S_value);
			break;
		case 3:
			cur = cur->prev;
			break;
		case 4:
			cur = cur->nxt;
			break;

		default:
			break;
		}
	}

	void print() {
		Node* temNode;
		string temstr;
		temNode = cur->prev;

		if (temNode != nullptr) {
			temstr = temNode->data;
		}
		else {
			temstr = "(Null)";
		}
		cout << temstr << " ";
	//mid
		temNode = cur;

		if (temNode != nullptr) {
			temstr = temNode->data;
		}
		else {
			temstr = "(Null)";
		}
		cout << temstr << " ";

		//end
		temNode = cur->nxt;

		if (temNode != nullptr) {
			temstr = temNode->data;
		}
		else {
			temstr = "(Null)";
		}
		cout << temstr << "\n";

	}

};



//func
void init();

//main
int main() {
	string S_init;
	int N;

	cin >> S_init;
	cin >> N;

	LinkedList* ml = new LinkedList();
	ml->root = new Node(S_init);
	ml->tail = ml->root;
	ml->cur = ml->root;


	for (int i = 0; i < N; i++) {
		ml->oper();
		ml->print();
	}


	return 0;
}


//func
void init() {
	nodecnt = 0;
}