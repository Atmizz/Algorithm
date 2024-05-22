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
const int MaxN = 2e5 + 20;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int n, odd[MaxN], even[MaxN], ans;
char str[MaxN];
int main() {
  n = read();
  scanf("%s", str + 1);
  for(int i = 1; i <= n; ++ i) {
    odd[i] = odd[i-1]; even[i] = even[i-1];
    if(str[i] == 'G') {
      if(i % 2 == 1) odd[i] ++;
      else even[i] ++;
    }
  } ans = max(0, even[n]);
  for(int i = 1; i <= n; ++ i)
    if(odd[i] > even[i]) ans = max(ans, even[n] - even[i] + odd[i]);
  printf("%d", ans);
  return 0;
}