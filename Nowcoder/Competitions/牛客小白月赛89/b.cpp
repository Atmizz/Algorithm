#include <bits/stdc++.h>
//#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define PII std :: pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
#define DEB std :: cout << "ok" << endl;
using i64 = long long;
const int INF = 0x3f3f3f3f;
const i64 LLINF = 0x3f3f3f3f3f3f3f3f;
const int Range = 1e9;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
// const int N = ;
void solve() {
	int n;
	std :: cin >> n;
	std :: priority_queue <int, std :: vector <int>, std :: greater <int> > q;
	for(int i = 1; i <= n; ++ i) {
		int x;
		std :: cin >> x;
		q.push(x);
	}
	i64 sum = 0, res = 0;
	while(q.size() > 2) {
		if(q.top() + res < 0) {
			res = res * 2 + q.top();
		} else {
			break;
		}
		q.pop();
	}
	// deb(res);
	while(q.size()) {
		// deb(q.top())
		sum += q.top() + res;
		q.pop();
	}
	std :: cout << sum << '\n';
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