#include <bits/stdc++.h>
#define ls k << 1
#define rs k << 1 | 1
#define pr pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
using i64 = long long;

const int N = 1e6 + 299;
const int INF = 0x3f3f3f3f;
const int Mod = 1e9 + 7;

int prime[N], isNotPrime[N], cnt, n;

void get_primes_ai() {
	for(int i = 2; i <= n; ++ i) {
		if(!isNotPrime[i]) {
			prime[++cnt] = i;
			for(int j = 2; j * i <= n; ++ j)
				isNotPrime[i*j] = 1;
		}
	}
}
void get_primes_ou() {
	for(int i = 2; i <= n; ++ i) {
		if(!isNotPrime[i]) prime[++cnt] = i;
		for(int j = 1; j <= cnt && i * prime[j] <= n; ++ j) {
			isNotPrime[i*prime[j]] = 1;
			if(i % prime[j] == 0) break;
		}
	}
}

void solve() {
	std :: cin >> n;
	get_primes_ou();
	std :: cout << 5 << ' ' << isNotPrime[5] << endl;
	std :: cout << 6 << ' ' << isNotPrime[6] << endl;
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