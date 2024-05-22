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
const int MaxN = 1e5 + 200;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int n, m, cnt;
int main() {
  n = read(); m = read();
  std :: string str = "baixiang";
  for(int i = 1; i <= n; ++ i) {
    std :: string s;
    std :: cin >> s; int len = s.length();
    for(int i = 0; i < len; ++ i) {
      bool flag = 0;
      for(int k = 0; k < 8 && i + k < len; ++ k)
        if(str[k] != s[i+k]) {
          flag = 1; break;
        }
      if(flag == 0) {
        cnt ++;
        if(cnt == m + 1) std :: cout << s << '\n';
        break;
      }
    }
  } if(cnt <= m) std :: cout << "yin wei ta shi you liang xin de zhong guo zhi zao";
  return 0;
}