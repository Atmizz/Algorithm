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
struct Node {
	int val, id;
	friend bool operator < (Node a, Node b) {
		return a.val == b.val ? a.id < b.id : a.val < b.val;
	}
}b[23];
void solve() {
	int n;
	std :: cin >> n;
	std :: vector <int> a(n), c[n];
	std :: vector <pi> ans1, ans2;
	for(int i = 0; i < n; ++ i) {
		std :: cin >> a[i]; c[i] = a[i];
		b[i].val = a[i]; b[i].id = i;
	}
	std :: sort(b, b + n);
	bool flag = 1;
	for(int i = 1; i < n; ++ i)
		if(a[i] < a[i-1]) {
			flag = 0;
			break;
		}
	if(flag == 1) {
		std :: cout << 0 << endl;
		return ;
	}
	for(int i = 1; i < n; ++ i) {
		if(a[i] >= a[i-1]) continue;
		int diff = a[i] - a[i-1];
		int pos = std :: lower_bound(b, b + n, {})
	}
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