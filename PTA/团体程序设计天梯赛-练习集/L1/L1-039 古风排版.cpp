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
const int MaxN = 1e3 + 200;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
std :: string str;
char ans[MaxN][MaxN];
int n, len, m;
int main() {
  n = read();
  getline(std :: cin, str); len = str.length();
  m = len / n; if(len % n) m ++;
  int now = 0;
  for(int j = m; j >= 1; -- j)
    for(int i = 1; i <= n; ++ i)
      ans[i][j] = (now >= len) ? ' ' : str[now], now ++;
  for(int i = 1; i <= n; ++ i, puts(""))
    for(int j = 1; j <= m; ++ j)
      putchar(ans[i][j]);
  return 0;
}