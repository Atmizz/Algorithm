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
const int MaxN = 15;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int f[MaxN][MaxN];
void init() {
  for(int i = 0; i < 10; ++ i) f[1][i] = 1;
  for(int i = 2; i < MaxN; ++ i)
    for(int j = 0; j < 10; ++ j)
      for(int k = j; k < 10; ++ k)
        f[i][j] += f[i-1][k];
}
int dp(int n) {
  if(n == 0) return 1;
  std :: vector <int> nums;
  while(n) nums.push_back(n % 10), n /= 10;
  int res = 0, last = 0;
  for(int i = nums.size() - 1; i >= 0; -- i) {
    int x = nums[i];
    for(int j = last; j < x; ++ j)
      res += f[i+1][j];
    if(x < last) break;
    last = x;
    if(i == 0) res ++;
  } return res;
}
int main() {
  init();
  int l, r;
  while(~scanf("%d %d", &l, &r)) printf("%d\n", dp(r) - dp(l - 1));
  return 0;
}