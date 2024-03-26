#include <iostream>
#include <unordered_map>
#include<vector>
#include<string>

using namespace std;

void init();
void run();

//var
int n;
int m;
unordered_map<string, int> mm;
vector<string> mv;

int main() {
    // 여기에 코드를 작성해주세요.
    init();
    return 0;
}

void init() {
    //local var
    string temstr;
    int temint = 0;
    //
    mv.push_back("init");

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> temstr;
        mm[temstr] = i;
        mv.push_back(temstr);
    }

    for (int i = 1; i <= m; i++) {
        //문자열이나 번호
        cin >> temstr;
        if (mm.find(temstr) != mm.end()) {
            cout << mm[temstr] << endl;
        }
        else {
            temint = stoi(temstr);
            cout << mv[temint] << endl;
        }
    }

}

void run() {


}