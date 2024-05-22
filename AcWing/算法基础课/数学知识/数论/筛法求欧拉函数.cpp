#include <bits/stdc++.h>
#define ls k << 1
#define rs k << 1 | 1
#define pr pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
using i64 = long long;

const int N = 1e6 + 200;
const int INF = 0x3f3f3f3f;
const int Mod = 1e9 + 7;

int prime[N], isNotPrime[N], phi[N], cnt;

void get_eulers(int n) {
	phi[1] = 1;
	for(int i = 2; i <= n; ++ i) {
		if(!isNotPrime[i]) prime[++cnt] = i, phi[i] = i - 1;
		for(int j = 1; j <= cnt && prime[j] * i <= n; ++ j) {
			isNotPrime[i*prime[j]] = 1;
			if(i % prime[j] == 0) {
				phi[i*prime[j]] = phi[i] * prime[j];
				break;
			}
			phi[i*prime[j]] = phi[i] * (prime[j] - 1);
		}
	}
}

void solve() {
	int n;
	std :: cin >> n; get_eulers(n);
	i64 sum = 0;
	for(int i = 1; i <= n; ++ i) sum += phi[i];
	std :: cout << sum;
}

int main() {
	std :: ios :: sync_with_stdio(false);
	std :: cin.tie(0);
	std :: cout.tie(0);
	int T = 1;
	//std :: cin >> T;
	while(T --) solve();
	return 0;
}