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

void solve() {
	int n;
	std :: cin >> n;
	std :: priority_queue <int, std :: vector <int>, std :: greater <int> > q;
	i64 now = 0, ans = 0;
	for(int i = 1; i <= n; ++ i) {
		int x; std :: cin >> x;
		if(now + x >= 0) now += x, ans ++, q.push(x);
		else if(q.size() && x > q.top()) {
			now -= q.top() - x, q.pop();
			q.push(x);
		}
	}
	std :: cout << ans;
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