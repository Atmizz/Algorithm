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
const int N = 5e5 + 20;
const int M = 1e7 + 20;
int a[N], b[N], c[N], n;
int prime[M], isNotPrime[M], cnt;
void solve() {
	std :: cin >> n;
	for(int i = 1; i <= n; ++ i) {
		std :: cin >> c[i];
		a[i] = -1; b[i] = -1;
		if(c[i] % 2 == 0) {
			while(c[i] % 2 == 0) {
				c[i] /= 2;
			}
			if(c[i] != 1) {
				a[i] = 2;
				b[i] = c[i];
			}
		} else {
			if(!isNotPrime[c[i]]) {
				continue;
			}
			for(int k = 1; k <= cnt && prime[k] <= sqrt(c[i]); ++ k) {
				int j = prime[k];
				// if(j > a[i)
				if(c[i] % j == 0) {
					int r1 = j, r2 = c[i] / j;
					while(r2 % r1 == 0) {
						r2 /= r1;
					}
					if(r2 == 1) {
						continue;
					}
					// deb(r1);
					// deb(r2);
					a[i] = r1;
					b[i] = r2;
					break;
				}
			}
		}
	}
	for(int i = 1; i <= n; ++ i) {
		std :: cout << a[i] << ' ';
	}
	std :: cout << '\n';
	for(int j = 1; j <= n; ++ j) {
		std :: cout << b[j] << ' ';
	}
}
void prepare() {
	for(int i = 2; i < M; ++ i) {
		if(!isNotPrime[i]) {
			prime[++cnt] = i;
		}
		for(int j = 1; j <= cnt && 1LL * i * prime[j] < 1LL * M; ++ j) {
			isNotPrime[i*prime[j]] = 1;
			if(i % prime[j] == 0) {
				break;
			}
		}
	}
}
int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	std :: ios :: sync_with_stdio(false);
	std :: cin.tie(0);
	std :: cout.tie(0);
	prepare();
	int T = 1;
	//std :: cin >> T; 
	while(T --) solve();
	return 0;
}