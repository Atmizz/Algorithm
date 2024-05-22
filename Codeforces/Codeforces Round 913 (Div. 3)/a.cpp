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
// const int N = ;
void solve() {
	char col[8] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
	std :: string str;
	std :: cin >> str;
	for(int i = 1; i <= 8; ++ i)
		if(i != (str[1] - 48)) {
			std :: cout << str[0] << i << '\n';
		}
	for(int i = 0; i < 8; ++ i)
		if(col[i] != str[0])
			std :: cout << col[i] << str[1] << '\n';
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