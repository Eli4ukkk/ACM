#include <iostream>
#include <math.h>
using namespace std;
int ans = 0;
int n;
int a[14] = {0};
int col[14] = {0};
int k1[28] = {0};
int k2[28] = {0};
bool check(int x, int y) {
	if (col[y] == 1) return false; // 列
	if (k1[x + y] == 1) return false; // 副对角线
	if (k2[x - y + n] == 1) return false; // 主对角线
	return true;
}
void dfs(int r) {
	if (r > n) {
		ans++;
		if (ans <= 3) {
			for (int i = 1; i <= n; i++) {
				cout << a[i] << " ";
			}
			cout << endl;
		}
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (check(r, i)) {
			col[i] = 1;
			k1[r + i] = 1;
			k2[r - i + n] = 1;
			a[r] = i;
			dfs(r + 1);
			// 回溯
			a[r] = 0;
			col[i] = 0;
			k1[r + i] = 0;
			k2[r - i + n] = 0;
		}
	}
}
int main() {
	cin >> n;
	dfs(1);
	cout << ans;
	return 0;
}
