#include<iostream>
#include<vector>

using namespace std;

void init();
void run(int lev);
void print();

//var
int n;
vector<int> mv;
bool arr[213];//false -> unused

int main() {

	init();
	run(0);
	print();

	return 0;
}

void init() {
	cin >> n;

	for (int i = 0; i < 213; i++) {
		arr[i] = false;
	}
}

void run(int lev) {
	if (lev == n) {
		print();
		return;
	}

	for (int i = n; i > 0; i--) {
		if (!arr[i]) {
			//사용되지 않았다면

			arr[i] = true;
			mv.push_back(i);
			run(lev+1);
			mv.pop_back();
			arr[i] = false;

		}

	}


}

void print() {
	for (auto a : mv) {
		cout << a << " ";
	}cout << endl;
}