#include <bits/stdc++.h>
#define ls k << 1
#define rs k << 1 | 1
#define gc getchar()
typedef unsigned long long ll;
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
const int MaxN = 5e3 + 10;
const ll Mod = 1e9 + 7;
const int INF = 2147483647;
ll len, d[MaxN], p[MaxN];
char str[MaxN];
ll calc() {
  memset(d, 0, sizeof d);
  memset(p, 0, sizeof p);
  p[0] = 1;
  for(int i = 1; i <= len; ++ i) {
    for(int j = 0; j <= len; ++ j) d[j] = p[j], p[j] = 0;
    if(str[i] == '(')
      for(int j = 1; j <= len; ++ j)
        p[j] = d[j-1];
    else {
      p[0] = (d[0] + d[1]) % Mod;
      for(int j = 1; j <= len; ++ j)
        p[j] = (d[j+1] + p[j-1]) % Mod;
    }
  }
  for(int i = 0; i <= len; ++ i)
    if(p[i]) return p[i] % Mod;
  return - 1;
}
int main() {
  scanf("%s", str + 1); len = strlen(str + 1);
  ll l = calc();
  std :: reverse(str + 1, str + 1 + len);
  for(int i = 1; i <= len; ++ i)
    if(str[i] == '(') str[i] = ')';
    else str[i] = '(';
  ll r = calc();
  printf("%llu", l * r % Mod);
  return 0;
}