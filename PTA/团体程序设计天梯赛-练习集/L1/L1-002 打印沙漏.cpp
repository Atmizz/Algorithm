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
const int MaxN = 1003;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int n, ans[MaxN], cnt, sum;
int main() {
  n = read(); char ch = gc; ans[++cnt] = 1; sum = 1;
  for(int x = 3; sum + (x << 1) <= n; x += 2)
    ans[++ cnt] = x, sum += (x << 1);
  for(int i = cnt; i >= 1; -- i, puts("")) {
    for(int j = 1; j <= (ans[cnt] - ans[i]) >> 1; ++ j) std :: cout << ' ';
    for(int j = 1; j <= ans[i]; ++ j)
      printf("%c", ch);
  }
  for(int i = 2; i <= cnt; ++ i, puts("")) {
    for(int j = 1; j <= (ans[cnt] - ans[i]) >> 1; ++ j) std :: cout << ' ';
    for(int j = 1; j <= ans[i]; ++ j)
      printf("%c", ch);
  }
  std :: cout << n - sum;
  return 0;
}