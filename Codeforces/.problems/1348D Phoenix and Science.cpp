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
std :: mt19937 rd(114514);
void solve() {
	int n;
	std :: cin >> n;
	std :: vector <int> v;
	std :: map <int, int> mp;
	int res = 1;
	while(1) {
		if(n > res) {
			n -= res;
			v.push_back(res);
		} else {
			v.push_back(n);
			break;
		}
		res <<= 1;
	}
	std :: sort(v.begin(), v.end());
	std :: cout << (int) v.size() - 1 << '\n';
	for(int i = 1; i < (int) v.size(); ++ i) {
		std :: cout << v[i] - v[i-1] << ' ';
	}
	std :: cout << '\n';
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