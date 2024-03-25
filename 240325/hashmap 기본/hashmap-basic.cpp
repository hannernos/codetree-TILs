#include<iostream>
#include<unordered_map>
#include<cstring>
using namespace std;


void init();
void run();
void add(int a, int b);
void remove(int a);
void find(int a);


int n;
unordered_map<int, int> mm;

int main() {
	init();
	run();

	return 0;
}

void init() {
	cin >> n;

}

void run() {
	char oper[10];
	int a, b;

	for (int i = 0; i < n; i++) {
		cin >> oper;
		if (!strcmp(oper, "add")) {
			cin >> a >> b;
			add(a, b);
		}else if (!strcmp(oper, "remove")) {
			cin >> a;
			remove(a);
		}else if (!strcmp(oper, "find")) {
			cin >> a;
			find(a);
		}else {
			cout << "unexpected";
		}
	}
}

void add(int a, int b) {
	//mm.insert({ a, b });
	mm[a] = b;
}
void remove(int a) {
	mm.erase(a);
}
void find(int a) {
	if (mm.find(a)!=mm.end()) {
		cout << mm[a] << endl;
	}
	else {
		cout << "None\n";
	}
}