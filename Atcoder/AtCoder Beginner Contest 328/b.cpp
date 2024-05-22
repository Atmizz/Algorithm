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
const int N = 110;
int n, a[N], ans;
bool check(int i, int j) {
	int cnt1[15] = {0}, cnt2[15] = {0};
	while(i) cnt1[i%10] ++, i /= 10;
	while(j) cnt2[j%10] ++, j /= 10;
	int cnt = 0;
	for(int k = 0; k < 10; ++ k) {
		if(cnt1[k] > 0 && cnt2[k] > 0) cnt ++;
		else if(cnt1[k] > 0) cnt ++;
		else if(cnt2[k] > 0) cnt ++;
	}
	if(cnt > 1) return false;
	return true;
}
void solve() {
	std :: cin >> n;
	for(int i = 1; i <= n; ++ i)
		std :: cin >> a[i];
	for(int i = 1; i <= n; ++ i)
		for(int j = 1; j <= a[i]; ++ j)
			if(check(i, j)) ans ++;
	std :: cout << ans;
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