#include <iostream>
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
const int N = 1010 * 1010;
int n, m, c;
long long a[N];
struct Node {
	int x, y;
}q[N];
bool cmp(Node a, Node b) {
	return a.x == b.x ? a.y < b.y : a.x < b.x;
}
inline int lowbit(int x) {
	return x & -x;
}
inline void add(int k, int x) {
	for(; k <= m; k += lowbit(k))
		a[k] += x;
}
long long query(int k) {
	long long sum = 0;
	for(; k; k -= lowbit(k))
		sum += a[k];
	return sum;
}
int t = 0;
void solve() {
	scanf("%d %d %d", &n, &m, &c);
	long long ans = 0;
	for(int i = 1; i <= m; ++ i)
		a[i] = 0;
	for(int i = 1; i <= c; ++ i)
		scanf("%d %d", &q[i].x, &q[i].y);
	std :: sort(q + 1, q + 1 + c, cmp);
	for(int i = 1; i <= c; ++ i) {
		add(q[i].y, 1);
		ans = ans + i - query(q[i].y);
	}
	printf("Test case %d: %lld\n", ++t, ans);
}
int main() {
	//freopen("1.in", "r", stdin);
	//freopen("1.out", "w", stdout);
	int T = 1;
	scanf("%d", &T);
	while(T --) solve();
	return 0;
}