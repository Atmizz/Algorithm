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
const int MaxN = 1030;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int s[MaxN];
int main() {
  int t = read();
  while(t --) {
    int ans = 0, ave = 0;
    memset(s, -1, sizeof s);
    while(1) {
      int opt = read(), mm, ss; char ch;
      std :: cin >> ch; mm = read(); ss = read();
      if(opt == 0) {
        if(ans != 0) ave = (int)(1.0 * ave / ans + 0.5);
        printf("%d %d\n", ans, ave);
        break;
      }
      if(ch == 'S') s[opt] = mm * 60 + ss;
      if(ch == 'E' && s[opt] != -1) ans ++, ave += (mm * 60 + ss - s[opt]), s[opt] = -1;
    }
  }
  return 0;
}