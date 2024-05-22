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
const int N = 110;
std :: string Unity(std :: string s, int x) {
	std :: string s1 = "";
	std :: string s2 = "";
	int len = s.length();
	for(int i = 0; i <= x; ++ i)
		s1 += s[i];
	for(int i = x + 1; i < len; ++ i)
		s2 += s[i];
	 // std :: cout << s1 + "01" + s2 << endl;
	return s1 + "01" + s2;
}
void solve() {
	int n; std :: cin >> n;
	std :: string str; std :: cin >> str;
	if(n % 2) {
		std :: cout << -1 << endl;
		return ;
	}
	bool initFlag = 0;
	for(int i = 1; i <= n >> 1; ++ i)
		if(str[i-1] == str[n-i]) {
			initFlag = 1;
			break;
		}
	if(initFlag == 0) {
		std :: cout << "0\n\n";
		return ;
	}
	int cnt0 = 0, cnt1 = 0;
	for(int i = 0; i < n; ++ i)
		if(str[i] == '0') cnt0 ++;
		else cnt1 ++;
	if(cnt0 != cnt1) {
		std :: cout << "-1\n";
		return ;
	}
	std :: vector <int> ans;
	int i = 0, j = n - 1;
	while(i < j) {
		// std :: cout << i << ' ' << j << endl;
		if(ans.size() > 300) {
			std :: cout << -1 << endl;
			return ;
		}
		if(str[i] != str[j]) {
			i ++, j --;
			continue;
		}
		if(str[i] == '0') {
			ans.push_back(j);
			str = Unity(str, j);
			i ++; j ++;
		} else {
			ans.push_back(i-1);
			str = Unity(str, i-1);
			i ++; j ++;
		}
	}
	std :: cout << ans.size() << endl;
	for(auto x : ans)
		std :: cout << x + 1 << ' ';
	std :: cout << endl;
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
