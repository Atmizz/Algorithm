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
int T, n, k, d;
int work() {
  std :: map<int, bool> g;
  int cnt = 1, Now = 0; g[0] = true;
  while(1) {
    printf("cnt : %d\n", Now);
    if(cnt == k) return Now;
    Now = (Now + d) % n;
    while(g[Now]) Now = (Now + 1) % n;
    g[Now] = true;
    cnt ++;
  }
}
int main() {
  T = read();
  while(T --) {
    n = read(); d = read(); k = read();
    printf("%d\n", work());
  }
  return 0;
}