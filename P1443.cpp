#include<iostream>
#include<queue>
using namespace std;
int ans[400][400];
int n, m, x, y;
int dx[8] = {-2, -2, -1, 1, 2, 2, -1, 1};
int dy[8] = {-1, 1, 2, 2, -1, 1, -2, -2};
struct Node {
	int x_, y_;
	int step;
};
void BFS() {
	ans[x][y] = 0;
	Node starNode = {x, y, 0};
	queue<Node> q;
	q.push(starNode);
	while (!q.empty()) {
		Node tmp = q.front();
		q.pop();
		for (int k = 0; k < 8; k++) {
			int nx = tmp.x_ + dx[k];
			int ny = tmp.y_ + dy[k];
			if (
			    nx >= 0 && nx < n &&
			    ny >= 0 && ny < m &&
			    ans[nx][ny] == -1
			) {
				ans[nx][ny] = tmp.step+1;
				Node newNode = {nx, ny, tmp.step + 1};
				q.push(newNode);
			}
		}
	}
}
int main() {
	cin >> n >> m >> x >> y;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			ans[i][j] = -1;
		}
	}
	x--;
	y--;
	BFS();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}

