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
const int N = 1e5 + 20;
int n;
std :: string str[N];
void solve() {
	std :: cin >> n;
	for(int i = 1; i <= n; ++ i) {
		std :: cin >> str[i];
	}
	std :: map <std :: string, bool> mp2, mp3, mp4;
	for(int i = 1; i <= n; ++ i) {
		int len = str[i].length();
		std :: string r = str[i];
		std :: reverse(r.begin(), r.end());
		if(r.size() == 1) {
			std :: cout << "YES\n";
			return ;
		}
		if(r.size() == 2) {
			if(r[0] == r[1] || mp2[r] || mp3[r]) {
				std :: cout << "YES\n";
				return ;
			}
			mp2[str[i]] = 1;
		} else {
			if(mp4[r] || r[0] == r[2]) {
				std :: cout << "YES\n";
				return ;
			}
			mp4[str[i]] = 1;
			r = r.substr(0, 2);
			// deb(r);
			if(mp2[r]) {
				std :: cout << "YES\n";
				return ;
			}
			mp3[str[i].substr(0, 2)] = 1;
		}
	}
	std :: cout << "NO\n";
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