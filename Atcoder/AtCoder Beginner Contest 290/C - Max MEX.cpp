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
const int MaxN = 3e5 + 20;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int cnt[MaxN], n, k;
int main() {
  n = read(); k = read();
  for(int i = 1; i <= n; ++ i) {
    int x = read();
    if(x < k) cnt[x] ++;
  }
  for(int i = 0; i < k; ++ i)
    if(cnt[i] == 0) {
      printf("%d", i);
      return 0;
    }
  printf("%d", k);
  return 0;
}