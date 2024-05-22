#include <bits/stdc++.h>
#define ls k << 1
#define rs k << 1 | 1
#define gc getchar()
typedef long long ll;
inline int read() {
	int s = 0, f = 1; char ch = gc;
	for(; ch < '0' || ch > '9'; ch = gc) if(ch == '-') f = -1;
	for(; ch >= '0' && ch <= '9'; ch = gc)
		s = (s << 1) + (s << 3) + (ch ^ 48);
	return s * f;
}
inline int abs(int a) {return a < 0 ? -a : a;}
inline int min(int a, int b) {return a < b ? a : b;}
inline int max(int a, int b) {return a > b ? a : b;}
const int MaxN = 1e6 + 200;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
ll Pow(ll a, ll b) {
	ll sum = 1;
	while(b) {
		if(b & 1ll) sum = sum * a % Mod;
		a = a * a % Mod; b >>= 1;
	}
	return sum % Mod;
}
void solve() {
	std :: cout << Pow(1, Mod-2) % Mod;
}
int main() {
	int T = 1;
	std :: cin >> T;
	while (T--) solve();
	return 0;
}
