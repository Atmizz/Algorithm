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
const int MaxN = 0;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int minn = -INF, maxx = INF;
int main() {
  int n = read();
  for(int i = 1; i <= n; ++ i) {
    int a = read(), b = read();
    maxx = min(maxx, a / b);
    minn = max(minn, a / (b + 1) + 1);
  } printf("%d %d", minn, maxx);
  return 0;
}

/*
75 3 18 25
53 2 18 26
59 2 20 29

*/