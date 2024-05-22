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
const int N = 1e6 + 20;
void solve() {
	std :: string s; i64 n;
	std :: cin >> s >> n;
	int len = s.length();
	i64 now = len, del = 0;
	if(n <= now) {
		std :: cout << s[n-1];
		return;
	}
	std :: stack <int> st;
	std :: map <int, bool> m;
	for(int i = 0; i < len; ++ i) {
		bool flag = 0;
		while(st.size() && s[st.top()] > s[i]) {
			m[st.top()] = 1;
			st.pop(); del ++;
			now += len - del;
			if(now >= n) {
				flag = 1;
				break;
			}
		} if(flag == 1) break;
		st.push(i);
	}
	if(n <= now) {
		int j = 0;
		i64 pos = n - (now - len + del), limit = 0;
		for(int i = 0; i < len; ++ i) {
			if(m[i] == 1) continue;
			j ++;
			if(j == pos) {
				std :: cout << s[i];
				return ;
			}
		}
	}

	int d = 0;
	while(now < n) d ++, now += len - del - d;
	i64 pos = n - (now - len + del + d), j = 0;
	// deb(pos); deb(del); deb(d);
	for(int i = 0; i < len; ++ i) {
		if(m[i] == 1) continue;
		j ++;
		if(j == pos) {
			std :: cout << s[i];
			return ;
		}
	}
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