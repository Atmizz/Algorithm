#include <bits/stdc++.h>
//#pragma GCC optimize ("O3")
#define nl '\n'
#define ls k << 1
#define rs k << 1 | 1
#define pb push_back
#define sz(x) (int)x.size()
#define mk std :: make_pair
#define PII std :: pair <int, int>
#define PIL std :: pair <int, i64>
#define PLL std :: pair <i64, i64>
#define DEB std :: cout << "ok" << '\n';
#define deb(x) std :: cout << #x << " = " << x << '\n';
using i64 = long long;
typedef unsigned long long ull;
template <class T>
T max(T a, T b) {
	return a > b ? a : b;
}
template <class T>
T min(T a, T b) {
	return a < b ? a : b;
}
template <class T>
T abs(T a) {
	return a < 0 ? -a : a;
}
std :: mt19937 rd(114514);
const int INF = 0x3f3f3f3f;
const i64 LLINF = 0x3f3f3f3f3f3f3f3f;
const int Range = 1e9;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 1e7 + 20;
struct Mathematic {
	template <class T>
	auto EulerSieve(std :: vector <T> &v) {
		T n = v.size() - 1, cnt = 0;
		std :: vector <T> prime;
		for(T i = 2; i <= n; ++ i) {
			if(!v[i]) {
				prime.push_back(i);
				cnt ++;
			}
			for(T j = 0; j < cnt && 1LL * i * prime[j] <= n; ++ j) {
				v[i*prime[j]] = 1;
				if(i % prime[j] == 0) {
					break;
				}
			}
		}
		return prime;
	}
}Math;
int sum[N];
void solve() {
	int l, r;
	std :: cin >> l >> r;
	std :: cout << sum[r] - sum[l-1] << nl;
}
void pre() {
	std :: vector <int> a(N);
	auto v = Math.EulerSieve(a);
	// deb(sz(v));
	for(auto &x : v) {
		sum[x] ++;
	}
	for(int i = 1; i <= N - 20; ++ i) {
		sum[i] += sum[i-1];
	}
}
int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	std :: ios :: sync_with_stdio(false);
	std :: cin.tie(0);
	std :: cout.tie(0);
	int _ = 1; pre();
	std :: cin >> _; 
	while(_ --) solve();
	return 0;
}