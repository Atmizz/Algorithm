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
const int N = 1e5 + 20;
void solve() {
	int n; std :: cin >> n;
	std :: vector <int> a(n + 1);
	for(int i = 1; i <= n; ++ i)
		std :: cin >> a[i];
	if(n <= 2) {
		std :: cout << "Yes\n";
		return ;
	}
	std :: map <int, int> cnt;
	int num = 0;
	for(int i = 1; i <= n; ++ i) {
		if(cnt[a[i]] == 0) num ++;
		cnt[a[i]] ++;
	}
	int maxx = 0, minn = INF;
	for(int i = 1; i <= n; ++ i) {
		maxx = std :: max(maxx, cnt[a[i]]);
		minn = std :: min(minn, cnt[a[i]]);
	}
	// deb(maxx); deb(minn);
	if(num <= 2 && maxx - minn <= 1) std :: cout << "Yes\n";
	else std :: cout << "No\n"; 
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