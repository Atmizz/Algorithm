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
const int N = 2e5 + 20;
const int M = 1e5;
int n;
std :: map <int, std :: map <int, i64> > s;
inline int lowbit(int x) {
	return x & -x;
}
void add(int y) {
	int x = y % 3;
	for(; y <= N << 1; y += lowbit(y)) {
		s[x][y] ++;
	}
}
i64 query(int y) {
	i64 sum = 0;
	int x = y % 3;
	for(; y; y -= lowbit(y)) {
		sum += s[x][y];
	}
	return sum;
}
void solve() {
	std :: cin >> n;
	std :: string str;
	std :: cin >> str;
	// std :: map <int, int> m;
	// m[0] = 1;
	s.clear();
	add(N);
	i64 ans = 0;
	int cnt1 = 0, cnt2 = 0, c = 0, cnt = 0;
	for(int i = 0; i < n; ++ i) {
		if(str[i] == '+') {
			cnt1 ++;
			cnt = 0;
		} else {
			cnt2 ++;
			cnt ++;
			if(cnt == 2) {
				c ++;
				cnt = 0;
			}
		}
		ans += query(cnt1-cnt2+c*3+N) - query(cnt1-cnt2-3+N);
		add(cnt1-cnt2+N);
	}
	std :: cout << ans << '\n';
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