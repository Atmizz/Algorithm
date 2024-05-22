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
const int MaxN = 1e8 + 200;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int isNotPrime[MaxN], isPrime[MaxN], cnt, n, k, ans;
int main() {
  n = read(); k = read();
  for(int i = 2; i <= n; ++ i) {
    if(!isNotPrime[i]) isPrime[++cnt] = i;
    for(int j = 1; j <= cnt && i * isPrime[j] <= n; ++ j) {
      isNotPrime[i*isPrime[j]] = 1;
      if(!(i & isPrime[j])) break;
    }
  }
  for(int i = 1; i <= cnt - 1; ++ i)
    if(isPrime[i] + isPrime[i+1] + 1 <= n && isNotPrime[isPrime[i] + isPrime[i+1]+1] == 0)
      ans ++;
  printf(ans >= k ? "YES" : "NO");
  return 0;
}