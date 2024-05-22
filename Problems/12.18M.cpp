#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <queue>
#include <stack>
#include <vector>
#include <cstdlib>
#include <map>
#include <set>
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
const int MaxN = 1e6+300;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int t, n, ans;
std :: string str1, str2, Bao[99];
int main() {
  t = read();
  while(t --) {
    std :: cin >> str1;
    n = read(); int BAO = 0;
    std :: cin >> str2; ans = 0;
    for(int i = 0; i < n*2; ++ i) {
      if(str2[i] == 'p') Bao[++BAO] = "p", Bao[BAO] += char((str2[i+1]-'0') % 9 + '0' + 1);
      if(str2[i] == 's') Bao[++BAO] = "s", Bao[BAO] += char((str2[i+1]-'0') % 9 + '0' + 1);
      if(str2[i] == 'm') Bao[++BAO] = "m", Bao[BAO] += char((str2[i+1]-'0') % 9 + '0' + 1);
      if(str2[i] == 'f') Bao[++BAO] = "f", Bao[BAO] += char((str2[i+1]-'0') % 4 + '0' + 1);
      if(str2[i] == 'y') Bao[++BAO] = "y", Bao[BAO] += char((str2[i+1]-'0') % 3 + '0' + 1);
    }
    for(int i = 0 ; i < 28; ++ i)
      for(int j = 1; j <= n; ++ j)
        if(str1[i] == Bao[j][0] && str1[i+1] == Bao[j][1]) ans ++;
    n *= 4;
    double ANS = (double)ans, N = (double)n;
    std :: cout << ANS / N;
  }
  return 0;
}