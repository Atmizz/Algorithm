#include <bits/stdc++.h>
//#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define PII std :: pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
#define DEB std :: cout << "ok" << endl;
using i64 = long long;
std :: mt19937 rd(114514);
const int INF = 0x3f3f3f3f;
const i64 LLINF = 0x3f3f3f3f3f3f3f3f;
const int Range = 1e9;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 15;
int a[N];
std :: vector dp(N, std :: vector (N, std :: vector <i64> (10)));
std :: vector <i64> dfs(int pos, int dig, bool limit, bool lead, std :: vector <i64> res) {
	if(pos == 0) {
		return res;
	}
	if(!limit && !lead && dp[pos][dig][0] != -1) {
		return dp[pos][dig];
	}

	int lim = limit ? a[pos] : 9;
	std :: vector <i64> tmp(10, 0);

	for(int i = 0; i <= lim; ++ i) {
		std :: vector <i64> b(10);
		std :: vector <i64> tp = res;
		if(lead && i == 0) {
			b = dfs(pos-1, 0, limit && i == lim, lead, tp);
		} else {
			tp[i] ++;
			b = dfs(pos-1, i, limit && i == lim, false, tp);
		}
		for(int j = 0; j < 10; ++ j) {
			tmp[j] += b[j];
		}
	}

	std :: cout << pos << ' ' << dig << '\n';
	for(int i = 0; i < 10; ++ i) {
		std :: cout << tmp[i] << ' ';
	}
	std :: cout << '\n';

	if(!limit && !lead) {	
		for(int i = 0; i < 10; ++ i) {
			dp[pos][dig][i] = tmp[i];
		}
	}
	return tmp;
}
std :: vector <i64> calc(i64 x) {
	int num = 0;
	for(int i = 0; i < N; ++ i) {
		for(int j = 0; j < N; ++ j) {
			for(int k = 0; k < 10; ++ k) {
				dp[i][j][k] = -1;
			}
		}
	}
	while(x) {
		a[++num] = x % 10;
		x /= 10;
	}
	std :: vector <i64> res(10, 0);
	return dfs(num, 0, true, true, res);
}
void solve() {
	i64 l, r;
	std :: cin >> l >> r;
	std :: vector <i64> v1 = calc(r);
	std :: vector <i64> v2 = calc(l-1);
	for(int i = 0; i < 10; ++ i) {
		std :: cout << v1[i] - v2[i] << ' ';
	}
	std :: cout << '\n';
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