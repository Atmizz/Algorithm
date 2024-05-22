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
const int N = 31623;
const int M = 1e5 + 20;
bool isNotPrime[N];
int prime[N], cnt, a[M];
void prepare() {
	for(int i = 2; i < N; ++ i) {
		if(!isNotPrime[i]) {
			prime[++cnt] = i;
		}
		for(int j = 1; j <= cnt && prime[j] * i < N; ++ j) {
			isNotPrime[prime[j]*i] = 1;
			if(i % prime[j] == 0) {
				break;
			}
		}
	}
}
void solve() {
	int n;
	std :: cin >> n;
	for(int i = 1; i <= n; ++ i) {
		std :: cin >> a[i];
	}
	std :: map <int, int> m;
	for(int i = 1; i <= n; ++ i) {
		for(int j = 1; j <= cnt && a[i] >= prime[j]; ++ j) {
			if(a[i] % prime[j] == 0) {
				if(m[prime[j]] > 0) {
					std :: cout << "YES\n";
					return ;
				}
				m[prime[j]] ++;
				while(a[i] % prime[j] == 0) {
					a[i] /= prime[j];
				}
			}
		}
		if(a[i] > 1) {
			if(m[a[i]] > 0) {
				std :: cout << "YES\n";
				return ;
			}
			m[a[i]] ++;
		}
	}
	std :: cout << "NO\n";
}
int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	std :: ios :: sync_with_stdio(false);
	std :: cin.tie(0);
	std :: cout.tie(0);
	prepare();
	int T = 1;
	std :: cin >> T; 
	while(T --) solve();
	return 0;
}