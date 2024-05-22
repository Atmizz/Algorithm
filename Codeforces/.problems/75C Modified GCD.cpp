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
// const int N = ;
void solve() {
	int a, b; std :: cin >> a >> b;
	int gcd = std :: __gcd(a, b);
	std :: vector <int> div;
	for(int i = 1; i <= sqrt(gcd); ++ i)
		if(gcd % i == 0) {
			div.push_back(i);
			if(i * i != gcd) div.push_back(gcd / i);
		}
	div.push_back(0);
	div.push_back(Range + 1);
	std :: sort(div.begin(), div.end());
	int n; std :: cin >> n;
	while(n --) {
		int l, r; std :: cin >> l >> r;
		int x = std :: upper_bound(div.begin(), div.end(), r) - div.begin();
		if(div[x-1] < l) std :: cout << -1 << '\n';
		else std :: cout << div[x-1] << '\n';
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