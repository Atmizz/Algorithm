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
inline int max(int a, int b) {return a > b ? a : b;}
const int MaxN = 0;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
ll n, h, m, s;
void print(int x) {
  if(x < 10) std :: cout << '0';
  printf("%d", x);
}
int main() {
  n = read(); n /= 1000;
  m = n / 60; s = n % 60;
  h = m / 60; m %= 60;
  h %= 24;
  print(h); std :: cout << ':';
  print(m); std :: cout << ':';
  print(s);
  return 0;
}