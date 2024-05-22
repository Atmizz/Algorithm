#include <bits/stdc++.h>
#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define pi std :: pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
using i64 = long long;
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
const int Mod = 1e9 + 7;

void solve() {
	int n;
	std :: cin >> n;
	std :: string t;
	std :: cin >> t;
	std :: string s0(n, '0'), s1(n, '1');
	auto s = t + s0 + t;
	int m = t.size();
	std :: vector <int> nxt(m+1);

	nxt[0] = -1;
	int i = 0, j = -1;
	while(i < m) {
		if(j == -1 || t[i] == t[j]) i ++, j ++, nxt[i] = j;
		else j = nxt[j];
	}

	int cnt = 0;
	i = 0, j = 0;
	while(i < n + (m << 1)) {
		if(j == -1 || s[i] == t[j]) i ++, j ++;
		else j = nxt[j];
		if(j == m) cnt ++;
	}

	if(cnt == 2) std :: cout << s0 << endl;
	else std :: cout << s1 << endl;
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