#include <bits/stdc++.h>
//#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define pi std :: pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
using i64 = long long;
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 0;
void solve() {
	int n; i64 ans = 0;
	std :: cin >> n;
	std :: priority_queue <int, std :: vector <int>, std :: greater<int> > q;
	for(int i = 1; i <= n; ++ i) {
		int x; std :: cin >> x;
		q.push(x);
	}
	while(q.size() > 1) {
		int temp = q.top(); q.pop();
		temp += q.top(); q.pop();
		ans += temp; q.push(temp);
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