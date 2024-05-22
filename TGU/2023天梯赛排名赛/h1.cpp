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
const int MaxN = 5e3 + 200;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int n, m, pa[MaxN << 1], ans, e[MaxN];
int Find(int x) {
  return x == pa[x] ? pa[x] : pa[x] = Find(pa[x]);
}
void Unity(int u,int v) {
	u = Find(u);
	v = Find(v);
	pa[u] = v;
}
int main() {
	memset(e, 0, sizeof(e));
	n = read(), m = read();
	for(int i = 1; i <= n; i ++) pa[i]=i;
	for(int i = 1; i <= m; i++) {
		char opt; int x,y;
		std :: cin >> opt;
		x = read(), y = read();
		if(opt == 'F') Unity(x,y);
		else {
			if(e[x] == 0) e[x]=y;
			if(e[y] == 0) e[y]=x;
			if(e[x] != 0) Unity(e[x],y);
			if(e[y] != 0) Unity(x,e[y]);
		}
	}
	for(int i = 1; i <= n; i ++) pa[i] = Find(i);
	std :: sort(pa + 1, pa + 1 + n); pa[0] = -1;
	for(int i = 1; i <= n; i ++)
		if(pa[i] != pa[i-1]) ans++;
	std :: cout << ans;
	return 0;
}