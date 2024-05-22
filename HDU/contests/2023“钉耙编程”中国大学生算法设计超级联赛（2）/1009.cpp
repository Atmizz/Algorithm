#include <bits/stdc++.h>
#define ls k << 1
#define rs k << 1 | 1
#define pr pair<int, int>
#define deb(x) std :: cout << #x << " = " << x << '\n';
using i64 = long long;

const int N = 1e6 + 200;
const int INF = 0x3f3f3f3f;
const int Mod = 1e9 + 7;

void solve() {
	int ans = 0;
	std :: string str;
	std :: cin >> str;
	int len = str.length();
	std :: vector <int> f(len);
	f[0] = 1;
	for(int i = 1; i < len; ++ i)
		if(str[i] == str[i-1]) f[i] = f[i-1] + 1;
		else {
			f[i] = 1;
			if(f[i-1] > 1) ans += f[i-1] - 1;
		}
	if(str[len-1] == str[len-2]) ans += f[len-1] - 1;
	std :: cout << ans << '\n';
}

int main() {
	std :: ios :: sync_with_stdio(false);
	std :: cin.tie(0);
	std :: cout.tie(0);
	int T = 1;
	std :: cin >> T;
	while(T --) solve();
	return 0;
}