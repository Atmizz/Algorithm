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
ll t, n;
int main() {
  t = read();
  while(t --) {
    n = read();
    if(n == 0) {
      printf("0\n");
      continue;
    } else if(n == 1) {
      printf("1\n");
      continue; 
    }
    if(n % 2) printf("3\n");
    else printf("2\n");
  }
  return 0;
}