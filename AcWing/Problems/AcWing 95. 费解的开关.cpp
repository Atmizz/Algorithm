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
const int MaxN = 1e6+300;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int T, f[6];
int main() {
  T = read();
  while(T --) {
    std :: string str;
    memset(f, 0, sizeof f);
    for(int i = 1; i <= 5; ++ i) {
      std :: cin >> str;
      for(int j = 0; j < 5; ++ j)
        f[i] = (f[i] << 1) + (str[j] - 48);
    }
    
  }
  return 0;
}