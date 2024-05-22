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
// const int N = ;
void solve() {
	int n;
	std :: cin >> n;
	std :: string str;
	std :: cin >> str;
	int num = 0;
	for(int i = 0; i < n; ++ i) {
		num += str[i] == '1';
	}
	if(num == 2) {
		for(int i = 0; i < n - 1; ++ i) {
			if(str[i] == '1' && str[i+1] == '1') {
				std :: cout << "NO\n";
				return ;
			}
		}
	}
	std :: cout << ((num & 1) ? "NO\n" : "YES\n");
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