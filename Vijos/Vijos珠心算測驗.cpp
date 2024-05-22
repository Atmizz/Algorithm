#include <bits/stdc++.h>
#define gc getchar()
#define ll long long
inline int read() {
	int s = 0, f = 1; char ch = gc;
	for(; ch < '0' || ch > '9'; ch = gc) if(ch == '-') f = -1;
	for(; ch >= '0' && ch <= '9'; ch = gc)
		s = (s << 1) + (s << 3) + (ch ^ 48);
	return s * f;
}
const int MaxN = 5e5 + 200;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int n, a[MaxN], ans;
bool b[MaxN];
int main() {
  n = read();
  for(int i = 1; i <= n; ++ i) a[i] = read(), b[a[i]] = 1;
  for(int i = 1; i <= n; ++ i)
    for(int j = 1; j < i; ++ j)
      if(b[a[i] + a[j]]) ans ++, b[a[i] + a[j]] = 0;
  printf("%d", ans);
}