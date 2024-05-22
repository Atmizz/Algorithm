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
const int N = 1e5 + 20;
int n, k, coin[20], pc[N], sum[N], dp[N];
// 定义 dp[i] 为使用状态为 i 时的最大购买个数
void solve() {
	// 输入
	std :: cin >> k >> n;
	for(int i = 0; i < k; ++ i) {
		std :: cin >> coin[i];
	}
	// 预处理前缀和，以便二分
	for(int i = 1; i <= n; ++ i) {
		std :: cin >> pc[i];
		sum[i] = sum[i-1] + pc[i];
	}
	int ans = -1;
	// 枚举当前金币所用状态，1 表示用，0 表示没有
	for(int _ = 1; _ < 1 << k; ++ _) {
		// 枚举哪一个金币是当前用的，减去它就是上一个状态
		for(int i = 0; i < k; ++ i) {
			if(!(_ >> i & 1)) {
				continue;
			}
			// 当用了该金币后能购买的最多商品个数
			int pos = std :: upper_bound(sum + 1, sum + 1 + n, sum[dp[_-(1<<i)]] + coin[i]) - sum - 1;
			dp[_] = std :: max(dp[_], pos);
		}
		int res = 0;
		if(dp[_] >= n) {
			for(int i = 0; i < k; ++ i) {
				if(!(_ >> i & 1)) {
					res += coin[i];
				}
			}
			ans = std :: max(ans, res);
		}
	}
	std :: cout << (ans == -1 ? -1 : ans);
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