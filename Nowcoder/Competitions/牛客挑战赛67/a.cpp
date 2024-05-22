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
const int MaxN = 4e5 + 200;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int n, a, b, t, ans[MaxN];
void sort1() {
  ans[a] = b; int cnt = 0;
  for(int i = 1; i <= n << 1; ++ i) {
      if(i == a) continue;
      cnt ++; if(cnt == b) cnt ++;
      ans[i] = cnt;
    }
}
void sort2() {
  ans[a] = b; int cnt = (n << 1) + 1;
  for(int i = 1; i <= n << 1; ++ i) {
      if(i == a) continue;
      cnt --; if(cnt == b) cnt --;
      ans[i] = cnt;
    }
}
int main() {
  t = read();
  while(t --) {
    n = read(); a = read(); b = read();
    memset(ans, -1, sizeof ans);
    if((a <= n && b <= n) || (a > n && b > n)) sort1();
    else sort2();
    for(int i = 1; i <= n << 1; ++ i)
      printf("%d ", ans[i]);
    puts("");
  }
  return 0;
}