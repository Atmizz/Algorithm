#include <bits/stdc++.h>
#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define pi pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
using i64 = long long;
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
const int Mod = 1e9 + 7;

struct Node {
	int x, y;
	friend bool operator < (Node a, Node b){
		return a.x == b.x ? a.y < b.y : a.x < b.x;
	}
	friend bool operator == (Node a, Node b) {
		return a.x == b.x && a.y == b.y;
	}
};

void solve() {
	int n;
	std :: cin >> n;
	std :: vector <Node> a(n*2);
	for(int i = 0; i < n * 2; ++ i) std :: cin >> a[i].x >> a[i].y;
	std :: sort(a.begin(), a.end());
	std :: vector <Node> ans(2);
	ans[0].x = a[0].x - a[n].x;
	ans[0].y = a[0].y - a[n].y;
	ans[1].x = a[n].x - a[0].x;
	ans[1].y = a[n].y - a[0].y;
	std :: sort(ans.begin(), ans.end());
	if(ans[0] == ans[1]) {
		std :: cout << 1 << endl;
		std :: cout << ans[0].x << ' ' << ans[0].y;
		return ;
	}
	std :: cout << 2 << endl;
	for(auto x : ans)
		std :: cout << x.x << ' ' << x.y << '\n';
}

int main() {
	std :: ios :: sync_with_stdio(false);
	std :: cin.tie(0);
	std :: cout.tie(0);
	int T = 1;
	std :: cin >> T; 
	while(T --) solve();
	return 0;
}