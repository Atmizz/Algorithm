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
const int MaxN = 1300;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int n, m, k, s[13];
struct Node {
  int date, val;
  friend bool operator < (Node a, Node b) {
    return a.date < b.date;
  }
}a[MaxN];
void prepare() {
  s[1] = 31; s[2] = 59; s[3] = 90; s[4] = 120; s[5] = 151; s[6] = 181;
  s[7] = 212; s[8] = 243; s[9] = 273; s[10] = 304; s[11] = 334;
}
int f[MaxN][5030];
int main() {
  prepare();
  n = read(); m = read(); k = read();
  for(int i = 1; i <= n; ++ i) {
    int m = read(), d = read(); a[i].val = read();
    a[i].date = s[m-1] + d;
  }
  std :: sort(a + 1, a + 1 + n);
  for(int i = 1; i <= n; ++ i) {
    int last = i - 1;
    while(last > 0 && a[i].date - a[last].date < k) last --;
    for(int j = m; j >= a[i].val; -- j) {
      f[i][j] = f[i-1][j];
      f[i][j] = max(f[i][j], f[last][j-a[i].val] + a[i].val);
    }
  }
  for(int i = m; i >= 0; -- i)
    if(f[n][i]) {
      printf("%d\n", f[n][i]);
      return 0;
    }
  return 0;
}