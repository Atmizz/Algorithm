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
const int MaxN = 5e4 + 200;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int t, n, m, ans[MaxN], pos[MaxN << 1], List[MaxN << 2];
int main() {
  t = read();
  while(t --) {
    n = read(); m = read();
    memset(ans, -1, sizeof ans);
    memset(pos, 0, sizeof pos);
    int l = m, r = m + n - 1;
    for(int i = l; i <= r; ++ i) List[i] = i - l + 1, pos[i-l+1] = i;
    for(int i = 1; i <= m; ++ i) {
      int x = read();
      if(pos[x]) {
        std :: swap(List[pos[x]], List[l]);
        std :: swap(pos[List[pos[x]]], pos[List[l]]);
      } else {
        l --; List[l] = x; pos[x] = l; ans[List[r]] = i; pos[List[r]] = 0; r --;
      }
    }
    for(int i = 1; i <= n; ++ i) printf("%d ", ans[i]);
    puts("");
  }
  return 0;
}