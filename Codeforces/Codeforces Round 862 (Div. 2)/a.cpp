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
int n, a[MaxN];
int main() {
  n = read();
  while(n --) {
    int x = read();
    for(int i =  1; i <= x; ++ i) a[i] = read();
    for(int i = 0; i <= 1 << 8; ++ i) {
      int check = a[1] ^ i;
      for(int j = 2; j <= x; ++ j)
        check ^= (a[j] ^ i);
      if(check == 0) {
        printf("%d\n", i); x = -1;
        break;
      }
    }
    if(x != -1) printf("-1\n");
  }
  return 0;
}