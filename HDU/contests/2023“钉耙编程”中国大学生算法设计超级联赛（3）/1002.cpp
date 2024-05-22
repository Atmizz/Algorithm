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

/*
w 速度
g 防御攻击的次数
i 释放的ice的力量
f 释放的火的力量
l 释放的雷的力量

*/
struct Node {
	int w, g, i, f, l, val;
	friend bool operator >= (Node a, Node b) {
		return a.w >= b.w && a.g >= b.g && a.i >= b.i && a.f >= b.f && a.l >= b.l;
	}
	friend bool operator < (Node a, Node b) {
		return a.w < b.w && a.g < b.g && a.i < b.i && a.f < b.f && a.l < b.l;
	}
};

void solve() {
	int n;
	std :: vector <Node> a(n), q(n+1);
	for(int i = 0; i < n; ++ i)
		std :: cin >> a[i].w >> a[i].g >> a[i].i >> a[i].f >> a[i].l;
	int ans = 0, len = 0;
	q.push_back({a[1].w, a[1].g, a[1].i, a[1].f, a[1].l, a[1].val});
	for(int i = 0; i < n; ++ i) {
		int l = 0, r = len; ans = a[i].val;
		deb(l); deb(r);
		while(l < r) {
			int mid = (l + r + 1) >> 1;
			if(q[mid] < a[i]) l = mid;
			else r = mid - 1;
		}
		len = std :: max(len, r + 1);
		if(a[i] >= a[r]) ans += a[r].val;
		q[r+1] = a[i];
		std :: cout << ans << endl;
	}
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