#include <bits/stdc++.h>
#define ls k << 1
#define rs k << 1 | 1
#define gc getchar()
typedef long long ll;
inline ll read() {
  ll s = 0, f = 1; char ch = gc;
  for(; ch < '0' || ch > '9'; ch = gc) if(ch == '-') f = -1;
  for(; ch >= '0' && ch <= '9'; ch = gc)
  s = (s << 1) + (s << 3) + (ch ^ 48);
  return s * f;
}
inline int abs(int a) {return a < 0 ? -a : a;}
inline int min(int a, int b) {return a < b ? a : b;}
const int MaxN = 100;
const int Mod = 1e4;
const int INF = 2147483647;
int n, m;
struct HP {
  int p[520], len;
  HP() {
    memset(p, 0, sizeof p);
    len = 0;
  }
  void read() {
    int x; scanf("%d", &x);
    while(x > Mod) p[++len] = x % Mod, x /= Mod;
    if(x) p[++len] = x;
  }
  void print() {
    printf("%d", p[len]);
    for(int i = len - 1; i >= 1; -- i)
      if(p[i] == 0) printf("0000");
      else {
        for(int k = 10; k * p[i] < Mod; k *= 10)
          printf("0");
        printf("%d", p[i]);
      }
  }
  void printBackspace() {
    std :: cout << ' ';
  }
  void printEnter() {
    std :: cout << '\n';
  }
}dp[MaxN][MaxN], base[MaxN], ans, t[MaxN];
HP operator + (const HP &a, const HP &b) {
  HP c; c.len = std :: max(a.len, b.len); int x = 0;
  for(int i = 1; i <= c.len; ++ i) {
    c.p[i] = a.p[i] + b.p[i] + x;
    x = c.p[i] / Mod, c.p[i] %= Mod;
  }
  if(x > 0) c.p[++c.len] = x;
  return c;
}
HP operator * (const HP &a, const HP &b) {
  HP c; c.len = std :: max(a.len, b.len);
  for(int i = 1; i <= a.len; ++ i) {
    int x = 0;
    for(int j = 1; j <= b.len; ++ j) {
      c.p[i+j-1] += a.p[i] * b.p[j] + x;
      x = c.p[i+j-1] / Mod;
      c.p[i+j-1] %= Mod;
    }
    c.p[i+b.len] = x;
  } c.len = a.len + b.len;
  while(c.p[c.len] == 0 && c.len > 1) c.len --;
  return c;
}
HP operator - (const HP &x, const HP &y) {
  HP c, a = x, b = y; c.len = std :: max(a.len, b.len);
  for(int i = 1; i <= a.len; ++ i) {
    if(a.p[i] < b.p[i]) {
      a.p[i+1] --;
      a.p[i] += Mod;
    }
    c.p[i] += (a.p[i] - b.p[i]);
  }
  while(c.p[c.len] == 0 && c.len > 1) c.len --;
  return c;
}
HP max (const HP &a, const HP &b) {
  if(a.len > b.len) return a;
  if(a.len < b.len) return b;
  for(int i = a.len; i >= 1; -- i)
    if(a.p[i] > b.p[i]) return a;
    else if(a.p[i] < b.p[i]) return b;
  return a;
}
void baseTwo() {
  base[0].p[1] = 1; base[0].len = 1;
  HP x; x.p[1] = 2; x.len = 1;
  for(int i = 1; i <= m; ++ i)
    base[i] = base[i-1] * x;
}
int main() {
  n = read(); m = read(); baseTwo();
  while(n --) {
    HP maxx; memset(dp, 0, sizeof dp); memset(t, 0, sizeof t);
    for(int i = 1; i <= m; ++ i) t[i].read();
    for(int i = 1; i <= m; ++ i)
      for(int j = m; j >= i; -- j) {
        dp[i][j] = max(dp[i][j], dp[i][j+1] + t[j+1] * base[m - j + i - 1]);
        dp[i][j] = max(dp[i][j], dp[i-1][j] + t[i-1] * base[m - j + i - 1]);
         maxx = max(maxx, dp[i][j]);
        //  dp[i][j].print(); std :: cout << '\n';
      }
    for(int i = 1; i <= m; ++ i)
      //  printf("%d %d ", i, i); dp[i][i].printBackspace(), dp[i][i].print(), res.printBackspace(), res.print(), dp[i][i].printEnter(); 
      maxx = max(maxx, dp[i][i] + t[i] * base[m]);
    ans = ans + maxx;
  }
  ans.print();
  return 0;
}