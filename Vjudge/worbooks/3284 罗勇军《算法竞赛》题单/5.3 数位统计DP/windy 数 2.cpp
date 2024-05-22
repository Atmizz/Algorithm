#include <bits/stdc++.h>
#define ls k << 1
#define rs k << 1 | 1
#define gc getchar()
typedef long long ll;
inline int read() {
	int s = 0, f = 1; char ch = gc;
	for(; ch < '0' || ch > '9'; ch = gc) if(ch == '-') f = -1;
	for(; ch >= '0' && ch <= '9'; ch = gc)
		s = (s << 1) + (s << 3) + (ch ^ 48);
	return s * f;
}
inline int abs(int a) {return a < 0 ? -a : a;}
inline int min(int a, int b) {return a < b ? a : b;}
inline int max(int a, int b) {return a > b ? a : b;}
const int MaxN = 30;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int a[MaxN], dp[MaxN][MaxN], len;
int dfs(int pos, int pre, bool lead, bool limit) {
	if(pos > len) return 1;
	if(!limit && dp[pos][pre] != -1) return dp[pos][pre];
	int sum = 0, res = limit ? a[len-pos+1] : 9;
	for(int i = 0; i <= res; ++ i) {
		if(abs(i-pre) < 2) continue;
		if(lead && i == 0) sum += dfs(pos + 1, -2, 1, limit && i == res);
		else sum += dfs(pos + 1, i, 0, limit && i == res);
	}
	if(!limit && !lead) return dp[pos][pre] = sum;
	return sum;
}
int calc(int x) {
	len = 0; memset(dp, -1, sizeof dp);
	while(x) a[++len] = x % 10, x /= 10;
	return dfs(1, -2, 1, 1);
}
void solve() {
	int l = read(), r = read();
	std :: cout << calc(r) - calc(l-1);
}
int main() {
  solve();
	return 0;
}
