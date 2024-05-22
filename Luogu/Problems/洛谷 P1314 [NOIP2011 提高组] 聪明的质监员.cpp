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
inline int abs(int a) {return a < 0 ? -a : a;}
inline int min(int a, int b) {return a < b ? a : b;}
inline int max(int a, int b) {return a > b ? a : b;}
const int MaxN = 2e5 + 200;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
struct Node {
  int w, v;
}a[MaxN];
int n, m, L[MaxN], R[MaxN];
ll s, ans, Final = INF;
bool Check(int mid) {
  ll A = 0;
  for(int i = 1; i <= m; ++ i)
    for(int j = L[i]; j <= R[i]; ++ j)
      if(a[j].w >= s) A += a[j].v;
  if(abs(A - s) < Final) {Final = abs(A-s); return true;}
  return false;
}
int main() {
  n = read(); m = read(); scanf("%lld", &s);
  if(s > 1e6) s = 1e6;
  for(int i = 1; i <= n; ++ i) a[i].w = read(), a[i].v = read();
  for(int i = 1; i <= m; ++ i) L[i] = read(), R[i] = read();
  for(int i = 1; i <= m; ++ i)
    for(int j = L[i]; j <= R[i]; ++ j)
      if(a[j].w >= s) ans += a[j].v;
  Final = min(Final, abs(s - ans));
  int l = 0, r = 1e6, mid;
  while(l < r) {
    mid = (l + r) >> 1;
    if(Check(mid)) r = mid;
    else l = mid + 1;
  } printf("%lld", Final);
	return 0;
}