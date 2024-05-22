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
const int N = 1e6 + 20;
std :: string str[N], opStr[N];
int trie[N][27], sum[N];
i64 ans = 0;
int n, tot;
void calc() {
	int p;
	for(int i = 1; i <= n; ++ i) {
		p = 0;
		for(int j = 0; j < opStr[i].length(); ++ j) {
			int x = opStr[i][j] - 'a' + 1;
			if(!trie[p][x]) trie[p][x] = ++ tot;
			sum[trie[p][x]] ++;
			p = trie[p][x];
		}
	}
	for(int i = 1; i <= n; ++ i) {
		p = 0;
		for(int j = 0; j < str[i].length(); ++ j) {
			int x = str[i][j] - 'a' + 1;
			if(!trie[p][x]) break;
			// deb(i); deb(j); deb(sum[trie[p][x]])
			ans = ans - sum[trie[p][x]] * (j + 1) * 2 + sum[trie[p][x]] * j * 2;
			// deb(sum[trie[p][x]] * (j + 1) - sum[trie[p][x]] * j)
			p = trie[p][x];
		}
		// deb(ans);
	}
}
void solve() {
	std :: cin >> n;
	for(int i = 1; i <= n; ++ i)
		std :: cin >> str[i];
	for(int i = 1; i <= n; ++ i) {
		opStr[i] = str[i];
		std :: reverse(opStr[i].begin(), opStr[i].end());
	}
	calc();
	for(int i = 1; i <= n; ++ i)
		ans += str[i].length() * n * 2;
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
