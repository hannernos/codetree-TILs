#include <iostream>

using namespace std;

class Dong {
private:
	string input;
	char input2;
	int input3;

public:

	Dong() {}

	void init() {

		cin >> input >> input2 >> input3;

	}
	void run() {
		cout << "secret code : " << input << endl;
		cout << "meeting point : " << input2 << endl;
		cout << "time : " << input3 << endl;
	}

	void print() {

	}



};

int main() {
	Dong dong;
	dong.init();
	dong.run();

	return 0;
}