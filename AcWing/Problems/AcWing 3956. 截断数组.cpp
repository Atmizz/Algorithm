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
const int MaxN = 1e5+300;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
ll n, a[MaxN], sum[MaxN], ans, rx, cnt[MaxN];
int main() {
  n = read();
  for(int i = 1; i <= n; ++ i) a[i] = read();
  for(int i = 1; i <= n; ++ i) sum[i] = sum[i-1] + a[i];
  if(sum[n] % 3) {
    printf("0");
    return 0;
  }
  sum[0] = sum[n] / 3;
  for(int i = 1; i <= n; ++ i) {
    cnt[i] = cnt[i-1];
    if(sum[i] == sum[0]) cnt[i] ++;
    // printf("%d %d\n", i, cnt[i]);
  }
  for(int i = n; i > 2; i --) {
    // printf("%d %d %d\n", i, sum[n] - sum[i-1], cnt[i-1]);
    if(sum[n] - sum[i-1] == sum[0])
      ans += cnt[i-2];
  }
  printf("%lld", ans);
  return 0;
}
/*
1 3 4 6

*/