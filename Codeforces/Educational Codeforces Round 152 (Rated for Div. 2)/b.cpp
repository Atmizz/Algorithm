#include <bits/stdc++.h>
#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define pi std :: pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
using i64 = long long;
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
const int Mod = 1e9 + 7;

const int N = 3e5 + 20;

struct Node {
	int h, id;
	friend bool operator < (Node a, Node b) {
		return a.h == b.h ? a.id < b.id : a.h > b.h;
	}
};

void solve() {
	int n, k;
	std :: cin >> n >> k;
	std :: vector < Node > q;
	std :: vector <int> ans;
	for(int i = 1; i <= n; ++ i) {
		int x;
		std :: cin >> x;
		x %= k;
		if(x == 0) ans.push_back(i);
		else q.push_back({x % k, i});
	}
	std :: sort(ans.begin(), ans.end());
	std :: sort(q.begin(), q.end());
	for(auto x : ans) std :: cout << x << ' ';
	for(auto x : q)
		std :: cout << x.id << ' ';
	std :: cout << endl;
}

int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	std :: ios :: sync_with_stdio(false);
	std :: cin.tie(0);
	std :: cout.tie(0);
	int T = 1;
	std :: cin >> T; 
	while(T --) solve();
	return 0;
}