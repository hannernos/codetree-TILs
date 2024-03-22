#include<iostream>
#include<queue>

using namespace std;

void init();
void run();
void print();

//var

int n, m;
int arr[213][213];
bool visited[213][213];
bool ans;

int dir_x[4] = { 0,0,-1,1};
int dir_y[4] = {-1,1,0,0};


int main() {

	init();
	run();
	print();

	return 0;
}

void init() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
}

void run() {
	int dx, dy;
	int y, x;
	queue <pair<int, int>> mq;

	mq.push({ 0, 0 });

	while (!mq.empty()) {

		x = mq.front().second;
		y = mq.front().first;
		mq.pop();

		if (y == n - 1 && x == m - 1) {
			ans = true;
			break;
		}


		for (int i = 0; i < 4; i++) {
			dy = y + dir_y[i];
			dx = x + dir_x[i];

			if (arr[dy][dx]==0||dy < 0 || dx < 0 || dy >= n || dx >= m||visited[dy][dx]==true) {
				continue;
			}
			visited[dy][dx] = true;
			mq.push({ dy,dx });


		}

	}
}

void print() {
	cout << visited[n - 1][m - 1];
}