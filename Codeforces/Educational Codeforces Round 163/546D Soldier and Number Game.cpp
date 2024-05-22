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
const int N = 5e6 + 20;
int sum[N], prime[N], isNotPrime[N], cnt;
void prepare() {
	for(int i = 2; i <= N - 20; ++ i) {
		if(!isNotPrime[i]) {
			prime[++cnt] = i;
		}
		for(int j = 1; j <= cnt && i * prime[j] <= N - 20; ++ j) {
			isNotPrime[prime[j]*i] = 1;
			if(i % prime[j] == 0) {
				break;
			}
		}
	}
	for(int i = 2; i <= N - 20; ++ i) {
		if(!isNotPrime[i]) {
			sum[i] = 1;
		}
		for(int j = 1; j <= cnt && i * prime[j] <= N - 20; ++ j) {
			sum[i*prime[j]] = sum[i] + 1;
			if(i % prime[j] == 0) {
				break;
			}
		}
	}
	for(int i = 2; i <= N - 20; ++ i) {
		sum[i] += sum[i-1];
	}
}
void solve() {
	int l, r;
	std :: cin >> r >> l;
	std :: cout << sum[r] - sum[l] << '\n';
}
int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	std :: ios :: sync_with_stdio(false);
	std :: cin.tie(0);
	std :: cout.tie(0);
	int T = 1;
	prepare();
	std :: cin >> T; 
	while(T --) solve();
	return 0;
}