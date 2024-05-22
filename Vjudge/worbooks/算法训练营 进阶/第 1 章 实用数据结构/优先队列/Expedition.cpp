#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
//#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define pi std :: pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 1e4 + 20;
struct Node {
	int val, pos;
	friend bool operator < (Node a, Node b) {
		return a.pos < b.pos;
	}
}a[N];
int val[N], pos[N], p, l;
void solve() {
	int n;
	std :: cin >> n;
	for(int i = 1; i <= n; ++ i)
		std :: cin >> a[i].pos >> a[i].val;
	std :: cin >> p >> l;
	for(int i = 1; i <= n; ++ i)
		a[i].pos = p - a[i].pos;
	std :: sort(a + 1, a + 1 + n);
	a[n+1].pos = p; a[n+1].val = 0;
	int j = 1, cnt = 0;
	std :: priority_queue <int> q;
	for(int i = 0; i <= n; ++ i) {
		// deb(l);
		if(l < a[i].pos) {
			std :: cout << -1;
			return ;
		}
		if(i > 0) q.push(a[i].val);
		while(l < a[i+1].pos && q.size()) l += q.top(), q.pop(), cnt ++;
	}
	std :: cout << cnt;
}
int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	std :: ios :: sync_with_stdio(false);
	std :: cin.tie(0);
	std :: cout.tie(0);
	int T = 1;
	//std :: cin >> T; 
	while(T --) solve();
	return 0;
}