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
const int MaxN = 35;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int f[MaxN][MaxN], l, r, K, B;
void init() {
  for(int i = 0; i < MaxN; ++ i)
    for(int j = 0; j <= i; ++ j)
      if(!j) f[i][j] = 1;
      else f[i][j] = f[i-1][j] + f[i-1][j-1];
}
int dp(int n) {
  if(n == 0) return 0;
  std :: vector <int> nums;
  while(n) nums.push_back(n % B), n /= B;
  int res = 0, last = 0;
  for(int i = nums.size() - 1; i >= 0; -- i) {
    int x = nums[i];
    if(x > 0) {
      res += f[i][K-last];
      if(x > 1) {
        if(K - last - 1 >= 0) res += f[i][K-last-1];
        break;
      } else {
        last ++;
        if(last > K) break;
      }
    }
    if(i == 0 && last == K) res ++;
  }
  return res;
}
void solve() {
  l = read(); r = read(); K = read(); B = read();
  printf("%d\n", dp(r) - dp(l-1));
}
int main() {
  init(); solve();
  return 0;
}