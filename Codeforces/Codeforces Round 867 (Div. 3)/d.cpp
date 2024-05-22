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
const int MaxN = 1e6 + 200;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int n, vis[MaxN], a[MaxN];

bool check(int x) {
  a[1] = x; a[2] = x - 1; a[3] = 2;  a[4] = 1;
  for(int i = 5; i <= x; ++ i) a[i] = i - 2;
  do {
    memset(vis, 0, sizeof vis);
    int sum = 0, flag = 1;
    // for(int i = 1; i <= x; ++ i) std :: cout << a[i] << ' ';
    // puts("");
    for(int i = 1; i <= x; ++ i) {
      sum += a[i]; sum %= x;
      if(vis[sum+1]) {flag = 0; break;}
      vis[sum+1] = 1;
    }
    if(flag) {
      for(int i = 1; i <= x; ++ i) std :: cout << a[i] << ' ';
      puts("");
      return 1;
    }
  }while(std :: next_permutation(a + 1, a + 1 + x));
}
int main() {
  for(int i = 2; i <= 20; ++ i) {
    std :: cout << i << '\n';
    if(i % 2 || !check(i)) printf("-1\n");
  }
  return 0;
}