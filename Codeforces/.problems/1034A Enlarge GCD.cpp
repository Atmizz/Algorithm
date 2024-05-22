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
#define DEB std :: cout << "ok" << endl;
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
const int N = 1e7 + 5e6;
int mp[N+1], ct[N+1], G, cnt, prime[N/10];
int gcd(int a, int b) {
	return !b ? a : gcd(b, a % b);
}
void solve() {
	for(int i = 2; i <= N; ++ i) {
		if(!mp[i]) {
			prime[++cnt] = i;
		}
		for(int j = 1; j <= cnt && prime[j] * i <= N; ++ j) {
			mp[i*prime[j]] = 1;
			if(i % prime[j] == 0) {
				break;
			}
		}
	}
	int n;
	std :: cin >> n;
	std :: vector <int> a(n);
	for(auto &x : a) {
		std :: cin >> x;
	}
	std :: sort(a.begin(), a.end());
	G = 0;
	for(int &x : a) {
		G = gcd(G, x);
	}
	for(int &x : a) {
		x /= G;
		ct[x] ++;
	}
	int ans = INT_MAX;
	for(int i = 1; i <= cnt && prime[i] <= a.back(); ++ i) {
		int sum = 0;
		for(int j = 1; j * prime[i] <= a.back(); ++ j) {
			sum += ct[j*prime[i]];
		}
		if(sum > 0) {
			ans = std :: min(ans, n - sum);
		}
	}
	std :: cout << (ans == INT_MAX ? -1 : ans);
}
int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	std :: ios :: sync_with_stdio(false);
	std :: cin.tie(0);
	std :: cout.tie(0);
	int _ = 1;
	//std :: cin >> _; 
	while(_ --) solve();
	return 0;
}