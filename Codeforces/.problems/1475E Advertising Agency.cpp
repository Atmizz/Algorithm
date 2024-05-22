#include <bits/stdc++.h>
//#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define pi std :: pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
#define DEB std :: cout << "ok" << endl;
using i64 = long long;
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 1010;
int n, a[N], k;
i64 ans;
bool cmp(int a, int b) {
	return a > b;
}
i64 quickMi(i64 a, i64 b) {
	i64 sum = 1;
	while(b) {
		if(b & 1) sum = sum * a % Mod;
		a = a * a % Mod; b >>= 1;
	} return sum % Mod;
}
i64 C(i64 a, i64 b) {
	i64 sum = 1;
	for(i64 i = a - b + 1; i <= a; ++ i)
		sum = sum * i % Mod;
	for(i64 i = 1; i <= b; ++ i)
		sum = sum * quickMi(i, Mod - 2) % Mod;
	return sum;
}
void solve() {
	std :: cin >> n >> k;
	for(int i = 1; i <= n; ++ i)
		std :: cin >> a[i];
	std :: sort(a + 1, a + 1 + n, cmp);
	for(int i = 1; i <= n; ++ i) {
		int cnt = 0, j;
		for(j = i; j <= n; ++ j)
			if(a[i] == a[j]) cnt ++;
			else break;
		if(cnt <= k) {
			k -= cnt;
			i = j - 1;
		}
		else {
			std :: cout << C(cnt, k) << endl;
			return ;
		}
	}
	std :: cout << 1 << endl;
}
int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	std :: ios :: sync_with_stdio(false);
	std :: cin.tie(0);
	std :: cout.tie(0);
	int T = 1;
	std :: cin >> T; 
	while(T --) solve();
	return 0;
}