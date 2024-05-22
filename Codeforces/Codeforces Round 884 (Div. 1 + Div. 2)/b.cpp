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
const int MaxN = 2e5 + 200;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int T, n, a[MaxN], b[MaxN];
bool prime(int x) {
  if(x == 1) return false;
  int t = sqrt(x);
  for(int i = 2; i <= t; ++ i)
    if(x % i == 0) return false;
  return true;
}
int vis[MaxN], ans = 0, num;
void solve(int l, int r) {
  memset(vis, 0, sizeof vis);
  for(int i = l; i <= r; ++ i)
    vis[a[i]] = 1;
  for(int i = 1; i <= n + 1; ++ i)
    if(vis[i] == 0) {
      if(prime(i) == true) num ++;
      break;
    }
}
int main() {
  T = read();
  while(T --) {
    n = read();
    for(int i = 1; i <= n; ++ i) a[i] = i;
    do {
      num = 0;
      for(int i = 1; i <= n; ++ i) std :: cout << a[i] << ' ';
      std :: cout << '\n';
      for(int i = 1; i <= n; ++ i)
        for(int j = 1; j <= i; ++ j)
          solve(j, i);
      std :: cout << "num : " << num << '\n';
      if(num > ans) {
        ans = num;
        for(int i = 1; i <= n; ++ i) b[i] = a[i];
      }
    }while(std :: next_permutation(a + 1, a + 1 + n));
    printf("ans : %d\n", ans);
    for(int i = 1; i <= n; ++ i) std :: cout << b[i];
    puts("");
  }
  return 0;
}