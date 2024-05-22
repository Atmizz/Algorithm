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
	int n, m;
	std :: cin >> n >> m;
	// 设 k 为所求的答案，则 n ^ x = k，其中 x 不应该是 0 ~ m 的任何一个数
	// 又有一个重要性质： n ^ x = k <-> n ^ k = x
	// 则题目就转化为 n ^ k = x 不应该是 0 ~ m 中的任何一个数
	// 又因为 x 肯定为非负数，所以 x > m ，即 n ^ k > m ，即 n ^ k >= m + 1
	// 构造 k 即可，并且是最小的 k 。
	// 考虑从小的位开始，遇到第一个可以变为
	// if n[i] == 0 and (m+1)[i] == 0 : k[i] = 0
	// if n[i] == 0 and (m+1)[i] == 1 : k[i] = 1
	// if n[i] == 1 and (m+1)[i] == 0 : k[i] = 1; break; 
	// if n[i] == 1 and (m+1)[i] == 1 : k[i] = 0
	int ans = 0; m ++;
	for(int i = 30; i >= 0; -- i) {
		if(!(n >> i & 1) && (m >> i & 1)) ans |= 1 << i;
		if((n >> i & 1) && !(m >> i & 1)) break;
	}
	std :: cout << ans << '\n';
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