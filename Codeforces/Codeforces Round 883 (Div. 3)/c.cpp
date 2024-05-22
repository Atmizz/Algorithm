#include <bits/stdc++.h>
#define ls k << 1
#define rs k << 1 | 1
#define gc getchar()
#define int long long
typedef long long ll;
inline int read() {
  int s = 0, f = 1; char ch = gc;
  for(; ch < '0' || ch > '9'; ch = gc) if(ch == '-') f = -1;
  for(; ch >= '0' && ch <= '9'; ch = gc)
    s = (s << 1) + (s << 3) + (ch ^ 48);
  return s * f;
}
inline int min(int a, int b) {return a < b ? a : b;}
inline int max(int a, int b) {return a > b ? a : b;}
const int MaxN = 1e6 + 20;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int t, n, m, h, T[MaxN];
struct Node {
  int id, socre, time;
  friend bool operator < (Node a, Node b) {
    return a.socre == b.socre ? (a.time == b.time ? a.id < b.id : a.time < b.time) : a.socre > b.socre;
  }
}a[MaxN];
signed main() {
  t = read();
  while(t --) {
    n = read(), m = read(), h = read();
    for(int i = 1; i <= n; ++ i) {
      for(int j = 1; j <= m; ++ j) T[j] = read();
      std :: sort(T + 1, T + 1 + m);
      int sum = 0; a[i].id = i; a[i].socre = a[i].time = 0;
      for(int j = 1; j <= m; ++ j) {
        if(sum + T[j] > h) break;
        sum += T[j]; a[i].time += sum; a[i].socre ++;
      }
    } std :: sort(a + 1, a + 1 + n);
    for(int i = 1; i <= n; ++ i)
      if(a[i].id == 1) {
        printf("%d\n", i);
        break;
      }
  }
  return 0;
}