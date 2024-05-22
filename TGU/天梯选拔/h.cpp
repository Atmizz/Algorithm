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
const int MaxN = 266;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
char str[MaxN];
int k, cnt, ans[MaxN], n;
int main() {
  scanf("%s", str + 1); k = read();
  int len = strlen(str + 1), x = 1; n = len - k;
  // std :: cout << n << '\n';
  while(cnt < n) {
    int minn = INF, pos = -1;
    for(int i = x; i <= len - n + cnt + 1; ++ i)
      if(minn > str[i] - 48) minn = str[i] - 48, pos = i;
    ans[++cnt] = minn, x = pos + 1;
  }
  int Begin = 1;
  if(std :: count(ans + 1, ans + 1 + n, 0) == n) {
    std :: cout << '0';
    return 0;
  }
  while(ans[Begin] == 0) Begin ++;
  for(int i = Begin; i <= n; ++ i) std :: cout << ans[i];
  return 0;
}