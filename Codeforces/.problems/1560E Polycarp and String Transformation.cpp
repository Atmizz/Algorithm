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
// const int N = ;
void solve() {
	std :: string s;
	std :: cin >> s;
	int n = sz(s);
	s = '0' + s;
	std :: vector sum(26, std :: vector <int> (n+1));
	std :: map <int, int> vis;
	std :: set <char> st;
	for(int i = 1; i <= n; ++ i) {
		for(int j = 0; j < 26; ++ j) {
			sum[j][i] = sum[j][i-1];
		}
		st.insert(s[i]);
		sum[s[i]-'a'][i] ++;
	}
	std :: string result = "0";
	auto dfs = [&](auto dfs, int pos, int num, std :: string res) -> void {
		if(pos == n && num == sz(st)) {
			result = res;
			return ;
		}
		if(num == sz(st)) {
			return ;
		}
		
		for(int i = 0; i < 26; ++ i) {
			if(sum[i][n] == 0 || sum[i][n] % (num + 1) || vis[i]) {
				continue ;
			}
			int p = std :: lower_bound(sum[i].begin(), sum[i].end(), sum[i][n]) - sum[i].begin();
			if(p < pos) {
				continue ;
			}
			vis[i] = 1;
			dfs(dfs, p, num + 1, res + char('a'+i));
			vis[i] = 0;
		}
		return ;
	};
	for(int i = 0; i < 26; ++ i) {
		if(sum[i][n] == 0) {
			continue ;
		}
		vis[i] = 1;
		int pos = std :: lower_bound(sum[i].begin(), sum[i].end(), sum[i][n]) - sum[i].begin();
		std :: string res = "";
		dfs(dfs, pos, 1, res + char('a'+i));
		vis[i] = 0;
	}
	if(result == "0") {
		std :: cout << -1 << nl;
		return ;
	}
	// deb(result);
	std :: string std = "", origin = "";
	int len = 0;
	for(int i = 0; i < sz(st); ++ i) {
		len += sum[result[i]-'a'][n] / (i + 1);
	}
	for(int i = 1; i <= len; ++ i) {
		origin += s[i];
	}
	for(int i = 0; i < sz(st); ++ i) {
		for(int j = 0; j < len; ++ j) {
			if(sum[origin[j]-'a'][n]) {
				std += origin[j];
			}
		}
		sum[result[i]-'a'][n] = 0;
	}
	std = "0" + std;
	if(std != s) {
		std :: cout << -1 << nl;
		return ;
	}
	std :: cout << origin << ' ' << result << nl;
	return ;
}
int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	std :: ios :: sync_with_stdio(false);
	std :: cin.tie(0);
	std :: cout.tie(0);
	int _ = 1;
	std :: cin >> _; 
	while(_ --) solve();
	return 0;
}