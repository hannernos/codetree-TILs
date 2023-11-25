#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct VillageCounter {
    vector<vector<int>> grid;
    int n;

    int dfs(int x, int y) {
        if (x < 0 || y < 0 || x >= n || y >= n || grid[x][y] != 1) {
            return 0;
        }

        grid[x][y] = -1;
        int count = 1;

        count += dfs(x + 1, y);
        count += dfs(x - 1, y);
        count += dfs(x, y + 1);
        count += dfs(x, y - 1);

        return count;
    }

    void init(int size, const vector<vector<int>>& matrix) {
        n = size;
        grid = matrix;
    }

    void run() {
        vector<int> villageCounts;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    villageCounts.push_back(dfs(i, j));
                }
            }
        }

        sort(villageCounts.begin(), villageCounts.end());

        cout << villageCounts.size() << endl;
        for (int count : villageCounts) {
            cout << count << endl;
        }
    }
};

int main() {
    int n;
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }

    VillageCounter counter;
    counter.init(n, matrix);
    counter.run();
    return 0;
}