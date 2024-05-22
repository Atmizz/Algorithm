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
const int N = 3e5 + 20;
char s[N];
int n, m, ans;
void solve() {
	scanf("%d %d", &n, &m);
	scanf("%s", s + 1);
	for(int i = 1; i < n; ++ i) {
		if(s[i] == '.' && s[i+1] == '.') {
			ans ++;
		}
	}
	while(m --) {
		int x; char ch;
		scanf("%d %c", &x, &ch);
		if((s[x] == '.') != (ch == '.')) {
			if(ch == '.') {
				ans += ((s[x-1] == '.') + (s[x+1] == '.'));
			} else {
				ans -= ((s[x-1] == '.') + (s[x+1] == '.'));
			}
		}
		std :: cout << ans << '\n';
		s[x] = ch;
	}
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