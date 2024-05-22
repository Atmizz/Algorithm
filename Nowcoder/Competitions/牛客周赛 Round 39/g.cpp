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
const int N = 1e5 + 10;
// property1 : 好数组的所有子数组一定都是好数组 设 n 则答案就是 n * (n + 1) / 2
// property2 : 两个最大子好数组的交集要容斥
int n, a[N], tend[N];
void solve() {
	std :: cin >> n;
	if(n > 1000) {
		std :: cout << 1LL * n * (n + 1) / 2;
		return ;
	}
	for(int i = 1; i <= n; ++ i) {
		std :: cin >> a[i];
	}
	for(int i = 1; i < n; ++ i) {
		tend[i] = a[i] < a[i+1] ? 1 : -1;
	}
	int last = 0, pos = 0;
	i64 ans = 0;
	for(int i = 1; i < n; ++ i) {
		int cnt = 1;
		int minn = INF;
		int j = i;
		bool ics = false;
		while(j < n && tend[j] == 1) {
			cnt ++;
			j ++;
			ics = true;
		}
		int res = 0;
		if(ics) {
			res = a[i];
		}
		int tmp = a[j+1];
		while(j < n && tend[j] == -1 && a[j+1] > res) {
			cnt ++;
			j ++;
		}
		// deb(j);
		if(tend[j] == 1 && a[j+1] > tmp) {
			while(j < n && tend[j] == 1) {	
				cnt ++;
				j ++;
			}
		}
		ans += 1LL * (cnt + 1) * cnt / 2;
		if(pos == i) {
			ans --;
		}
		// std :: cout << i << ' ' << j << '\n';
		pos = j;
		if(i != j) {
			i = j - 1;
		}
	}
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