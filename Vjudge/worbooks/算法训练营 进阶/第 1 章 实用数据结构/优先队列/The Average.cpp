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
const int N = 5e6 + 20;
typedef long long ll;
void solve() {
	ll n1, n2, n;
	while(1) {
		scanf("%lld %lld %lld", &n1, &n2, &n);
		if(n == 0) return ;
		std :: priority_queue <ll, std :: vector <ll>, std :: less <ll> > q;
		std :: priority_queue <ll, std :: vector <ll>, std :: greater <ll> > p;
		ll ans = 0;
		for(int i = 1; i <= n; ++i) {
			ll x; scanf("%lld", &x); ans += x;
			q.push(x); p.push(x);
			if(q.size() > n2) q.pop();
			if(p.size() > n1) p.pop();
		}
		for(int i = 1; i <= n2; ++ i)
			ans -= q.top(), q.pop();
		for(int i = 1; i <= n1; ++ i)
			ans -= p.top(), p.pop();
		printf("%.6lf\n", ans * 1.00 / (n - n1 - n2));
	}
}
int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	int T = 1;
	//std :: cin >> T; 
	while(T --) solve();
	return 0;
}