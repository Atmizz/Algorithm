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
	int n;
	std :: cin >> n;
	std :: string s;
	std :: cin >> s;
	if(n & 1) {
		std :: cout << "NO\n";
		return ;
	}
	// DEB
	std :: map <char, int> mp;
	for(auto &c : s) {
		if(c == 'N') {
			if(mp['S'] > 0) {
				mp['S'] --;
			} else {
				mp[c] ++;
			}
		} else if(c == 'S') {
			if(mp['N'] > 0) {
				mp['N'] --;
			} else {
				mp[c] ++;
			}
		} else if(c == 'E') {
			if(mp['W'] > 0) {
				mp['W'] --;
			} else {
				mp[c] ++;
			}
		} else {
			if(mp['E'] > 0) {
				mp['E'] --;
			} else {
				mp[c] ++;
			}
		}
	}
	for(auto &[c, v] : mp) {
		if(v & 1) {
			std :: cout << "NO\n";
			return ;
		}
	}
	std :: vector <int> pos[4];
	std :: map <char, int> op;
	op['N'] = 0;
	op['S'] = 1;
	op['E'] = 2;
	op['W'] = 3;
	int cnt = 0;
	for(int i = 0; i < n; ++ i) {
		char c = s[i];
		if(mp[c] > 0) {
			if(mp[c] & 1) {
				s[i] = 'R';
				cnt ++;
			} else {
				s[i] = 'H';
				cnt ++;
			}
			mp[c] --;
		} else {
			pos[op[c]].pb(i);
		}
	}
	if(sz(pos[0]) + sz(pos[2]) + cnt == 1) {
		std :: cout << "NO\n";
		return ;
	}
	cnt = 0;
	for(int i = 0; i < sz(pos[0]); ++ i) {
		if(cnt == 0) {
			s[pos[0][i]] = s[pos[1][i]] = 'R';
		} else {
			s[pos[0][i]] = s[pos[1][i]] = 'H';
		}
		cnt ^= 1;
	}
	for(int i = 0; i < sz(pos[2]); ++ i) {
		if(cnt == 0) {
			s[pos[2][i]] = s[pos[3][i]] = 'R';
		} else {
			s[pos[2][i]] = s[pos[3][i]] = 'H';
		}
		cnt ^= 1;
	}
	std :: cout << s << nl;
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