#include <bits/stdc++.h>
#define ls k << 1
#define rs k << 1 | 1
#define gc getchar()
#define int long long
typedef long long ll;
inline int read() {
	int s = 0, f = 1; char ch = gc;
	for(; ch < '0' || ch > '9'; ch = gc) if(ch == '-') f = -1;
	for(; ch >= '0' && ch <= '9'; ch = gc)
		s = (s << 1) + (s << 3) + (ch ^ 48);
	return s * f;
}
inline int min(int a, int b) {return a < b ? a : b;}
inline int max(int a, int b) {return a > b ? a : b;}
const int MaxN = 1e6 + 200;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int n, ans;
struct Node {
	int val, id;
	friend bool operator < (Node a, Node b) {
		return a.val == b.val ? a.id < b.id : a.val < b.val;
	}
}a[MaxN], b[MaxN];
void init() {
	n = read();
	for(int i = 1; i <= n; ++ i) a[i].val = read(), a[i].id = i;
	for(int i = 1; i <= n; ++ i) b[i].val = read(), a[i].id = i;
}
void solve() {
	std :: sort(a + 1, a + 1 + n);
	std :: sort(b + 1, b + 1 + n);
	bool flag = 1;
	for(int i = 1; i <= n; ++ i)
		if(a[i].id != i || b[i].id != i) {
			flag = 0; break;
		}
	if(flag == 1) {
		int pos = 0, minn = INF;
		for(int i = 1; i < n; ++ i)
			if(minn > std :: abs(a[i].val - b[i+1].val) + std :: abs(a[i+1].val - b[i].val))
				minn = std :: abs(a[i].val - b[i+1].val) + std :: abs(a[i+1].val - b[i].val), pos = i;
		for(int i = 1; i <= n; ++ i)
			if(i != pos || i != pos + 1) ans += std :: abs(a[i].val-b[i].val);
		std :: cout << ans + pos;
		return ;
	}
	for(int i = 1; i <= n; ++ i) ans += std :: abs(a[i].val - b[i].val);
	std :: cout << ans;
}
signed main() {
	init(); solve();
	return 0;
}
