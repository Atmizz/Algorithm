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
const int MaxN = 1e5 + 200;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int T, n, m, block, blk[MaxN], b[1000][11][10];
int a[MaxN], mod[11];
int query(int l, int r, int d, int p) {
  int sum = 0;
  for(int i = l; i <= min(r, blk[l] * block); ++ i)
    sum += (a[i]/mod[d-1]%10 == p);
  if(blk[l] != blk[r])
    for(int i = (blk[r] - 1) * block + 1; i <= r; ++ i)
      sum += (a[i]/mod[d-1]%10 == p);
  for(int i = blk[l] + 1; i <= blk[r] - 1; ++ i)
    sum += b[i][d][p];
  return sum;
}
int main() {
  T = read(); mod[0] = 1; 
  for(int i = 1; i <= 10; ++ i) mod[i] = mod[i-1] * 10;
  while(T --) {
    n = read(); m = read();
    memset(b, 0, sizeof b);
    block = sqrt(n);
    for(int i = 1; i <= n; ++ i) {
      a[i] = read();
      blk[i] = (i - 1) / block + 1;
      for(int j = 0; j < 10; ++ j)
        b[blk[i]][j+1][a[i]/mod[j]%10] ++;
    }
    for(int i = 1; i <= m; ++ i) {
      char ch; int l, r, d, p;
      std :: cin >> ch;
      if(ch == 'S') {
        l = read();
        for(int j = 0; j < 10; ++ j)
          b[blk[l]][j+1][a[l]/mod[j]%10] --;
        a[l] = read();
        for(int j = 0; j < 10; ++ j)
          b[blk[l]][j+1][a[l]/mod[j]%10] ++;
      } else {
        l = read(); r = read(); d = read(); p = read();
        printf("%d\n", query(l, r, d, p));
      }
    }
  }
  return 0;
}