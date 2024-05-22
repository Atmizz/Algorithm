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
const int N = 2e5 + 20;
int n, c[N];
i64 sum1[N], sum2[N], ans = LLINF;
std :: string str;
void solve() {
	std :: cin >> n;
	std :: cin >> str;
	str = "0" + str;
	for(int i = 1; i <= n; ++ i) {
		std :: cin >> c[i];
	}
	// 1 : 010101010101
	// 2 : 101010101010
	for(int i = 1; i <= n; ++ i) {
		sum1[i] = sum1[i-1];
		sum2[i] = sum2[i-1];
		if(i & 1) {
			if(str[i] != '0') {
				sum1[i] += c[i];
			} else {
				sum2[i] += c[i];
			}
		} else {
			if(str[i] != '0') {
				sum2[i] += c[i];
			} else {
				sum1[i] += c[i];
			}
		}
	}
	for(int i = 1; i < n; ++ i) {
		ans = std :: min(ans, std :: min(sum1[i] + sum2[n] - sum2[i], sum2[i] + sum1[n] - sum1[i]));
	}
	std :: cout << ans;
}
int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	std :: ios :: sync_with_stdio(false);
	std :: cin.tie(0);
	std :: cout.tie(0);
	int T = 1;
	//std :: cin >> T; 
	while(T --) solve();
	return 0;
}