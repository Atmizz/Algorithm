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
const int Mod = 11;
const int INF = 2147483647;
int n, a[MaxN], sum, pre[MaxN], last[MaxN], ans;
int main() {
	n = read();
  for(int i = 1; i <= n; ++ i) a[i] = read(), sum += a[i];
  for(int i = 1; i <= n; ++ i) a[i] -= (sum / n);
  for(int i = 1; i < n; ++ i)
    if(a[i] != 0) a[i+1] += a[i], ans ++;
  printf("%d", ans);
	return 0;
}