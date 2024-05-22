#include <iostream>
#include <cstdio>
#include <algorithm>
//#pragma GCC optimize(2)
#define ls k << 1
#define rs k << 1 | 1
#define pi std :: pair<int, int>
#define endl "\n"
#define deb(x) std :: cout << #x << " = " << x << '\n';
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
const int Mod = 1e9 + 7;
const int N = 4e4 + 29;
int n, b[N], num[N];
inline int lowbit(int x) {
	return x & -x;
}
void add(int k, int x) {
	for(; k <= N; k += lowbit(k))
		b[k] += x;
}
int query(int k) {
	int sum = 0;
	for(; k; k -= lowbit(k))
		sum += b[k];
	return sum;
}
void solve() {
	std :: cin >> n;
	for(int i = 1; i <= n; ++ i) {
		int x, y;
		std :: cin >> x >> y;
		x ++;
		num[query(x)] ++;
		add(x, 1);
	}
	for(int i = 0; i < n; ++ i)
		std :: cout << num[i] << endl;
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