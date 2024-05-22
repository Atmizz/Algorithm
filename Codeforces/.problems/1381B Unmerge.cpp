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
const int N = 5000;
std :: mt19937 rd(114514);
int n, p[N];
void solve() {
	std :: cin >> n;
	std :: vector <int> block;
	int res = 0, lst = 0;
	for(int i = 1; i <= n << 1; ++ i) {
		std :: cin >> p[i];
		if(p[i] > lst) {
			block.push_back(1);
			res ++;
			lst = p[i];
		} else {
			block[res-1] ++;
		}
	}
	std :: bitset <N> B;
	B[0] = 1;
	for(auto x : block) {
		B |= B << x;
	}
	std :: cout << (B[n] ? "YES\n" : "NO\n");
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