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
const int MaxN = 1e8 + 20;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int prime[MaxN], n, q, cnt;
bool isNotPrime[MaxN];
int main() {
  n = read(), q = read();
  for(int i = 2; i <= n; ++ i) {
    if(!isNotPrime[i]) prime[++cnt] = i;
    for(int j = 1; j <= cnt && prime[j] * i <= n; ++ j) {
      isNotPrime[prime[j] * i] = 1;
      if(i % prime[j] == 0) break;
    }
  }
  while(q --) {
    int x = read();
    printf("%d\n", prime[x]);
  }
  return 0;
}