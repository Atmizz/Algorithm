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
const int Range = 1e9;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
// const int N = ;
void solve() {
	int n, k, cnt = 0;
	std :: string s;
	std :: cin >> n >> k >> s;
	std :: vector <int> sum(n + 1);

	for(int i = 0; i < n; ++ i)
		if(s[i] == 'B') sum[i+1] = sum[i] + 1;
		else sum[i+1] = sum[i];

	for(int i = 0; i < n; ++ i)
		if(s[i] == 'B') cnt ++;

	if(cnt == k) {
		std :: cout << 0 << '\n';
		return ;
	}

	std :: cout << 1 << endl;

	if(cnt < k) {
		for(int i = 1; i <= n; ++ i)
			if(i + sum[n] - sum[i] == k) {
				std :: cout << i << ' ' << "B\n";
				return ;
			}
	}

	for(int i = 1; i <= n; ++ i)
		if(sum[n] - sum[i] == k) {
			std :: cout << i << ' ' << "A\n";
			return ;
		}
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