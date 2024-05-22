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
const int MaxN = 2e5 + 100;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int t, len, ans;
int main() {
  t = read();
  while(t --) {
    std :: string str;
    std :: cin >> str;
    len = str.length(); ans = 0;
    int Min = min(str[0], str[len-1]);
    int Max = max(str[0], str[len-1]);
    for(int i = 1; i < len - 1; ++ i)
      if(str[i] >= Min && str[i] <= Max)
        ans ++;
    printf("%d %d\n", Max - Min, ans + 2);
  }
  return 0;
}