#include <bits/stdc++.h>
//#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define pi std :: pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
#define DEB std :: cout << "ok" << endl;
using i64 = long long;
const int INF = 0x3f3f3f3f;
const int Range = 1e9;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 2e5 + 20;
i64 n, c;
struct Node {
	i64 val, id;
	friend bool operator < (Node a, Node b) {
		return c * a.id - a.val < c * b.id - b.val;
	}
}a[N];
void solve() {
	std :: cin >> n >> c;
	for(int i = 1; i <= n; ++ i)
		std :: cin >> a[i].val, a[i].id = i;
	std :: sort(a + 2, a + 1 + n);
	i64 s = a[1].val;
	for(int i = 2; i <= n; ++ i) {
		if(s + a[i].val >= a[i].id * c) s += a[i].val;
		else {
			std :: cout << "No\n";
			return ;
		}
	}
	std :: cout << "Yes\n";
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