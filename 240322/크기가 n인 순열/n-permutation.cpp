#include<iostream>
#include<vector>

using namespace std;

void init();
void run(int lev);
void print();

//var
int n;
vector<int> mv;

int arr[213];

int main() {

	init();
	run(0);
	print();

	return 0;
}

void init() {
	cin >> n;

	for (int i = 0; i < 213; i++) {
		arr[i] = 0;
	}
}

void run(int lev) {
	
	if (lev == n) {
		print();
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (arr[i] == 0) {
			arr[i] = 1;
			
			mv.push_back(i);
			run(lev + 1);
			mv.pop_back();

			arr[i] = 0;

		}
		
	}

}

void print() {
	for (auto a : mv) {
		cout << a << " ";
	}cout << endl;
}