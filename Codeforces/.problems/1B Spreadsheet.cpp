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
std :: string str;
int n;
void modify1() {
	int i = 1, r = 0, c = 0;
	while(str[i] != 'C')
		r = r * 10 + str[i] - 48, ++ i;
	++ i;
	while(str[i] >= '0' && str[i] <= '9')
		c = c * 10 + str[i] - 48, ++ i;
	std :: string ans = "";
	int t = 0;
	while(c)
		ans = ((c % 26 == 0) ? ('Z') : char(c % 26 + 'A' - 1)) + ans, t = (c % 26 == 0), c /= 26, c -= t;
	std :: cout << ans << r << endl;
}
void modify2() {
	int c = 0, r = 0, i = 0;
	while(str[i] >= 'A' && str[i] <= 'Z')
		c = c * 26 + (str[i] - 'A' + 1), ++ i;
	std :: cout << "R";
	 for(int j = i; j < n; ++ j) std :: cout << str[j];
	std :: cout << "C" << c << endl;
}	
void solve() {
	std :: cin >> str;
	n = str.size();
	int flag = 0;
	for(int i = 0; i < n; ++ i)
		if(str[i] >= '0' && str[i] <= '9') {
			if(flag == 2) {
				modify1();
				break;
			} flag = 1;
		} else {
			if(flag == 1) flag = 2;
		}
	if(flag != 2) modify2();
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