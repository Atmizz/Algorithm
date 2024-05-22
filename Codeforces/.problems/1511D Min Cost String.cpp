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
const int Range = 1e9;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
// const int N = ;
char ch[26];
void solve() {
	int n, k; std :: cin >> n >> k;
	if(k == 1) {
		for(int i = 1; i <= n; ++ i)
			std :: cout << 'a';
		return ;
	}
	for(int i = 0; i < k; ++ i)
		ch[i] = i;
	std :: string ans = "";
	for(int i = 0; i < k; ++ i) {
		ans = ans + char(ch[i] + 'a') + char(ch[i] + 'a');
		for(int j = i + 1; j < k; ++ j) {
			if(j == k - 1 && i != j - 1) {
				ans = ans + char(ch[j] + 'a');
				break;
			}
			if(j != k - 1) {
				ans = ans + char(ch[j] + 'a');
				ans = ans + char(ch[i] + 'a');
			}
		}
	}
	while(ans.length() < n) ans = ans + ans;
	for(int i = 0; i < n; ++ i)
		std :: cout << ans[i];
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