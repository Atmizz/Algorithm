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
const int MaxN = 100;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
std :: string str1, str2;
std :: unordered_set <int> hash;
int calc(std :: string str, int b) {
  int res = 0;
  for(auto x : str)
    res = res * b + x - '0';
  return res;
}
int main() {
  std :: cin >> str1 >> str2;
  for(int i = 0; i < str1.length(); ++ i) {
    std :: string str = str1; str[i] ^= 1;
    if(str[0] == '0' && str.length() > 1) continue;
    hash.insert(calc(str, 2));
  }
  for(int i = 0; i < str2.length(); ++ i)
    for(int j = 0; j < 3; ++ j)
      if(str2[i] - '0' != j) {
        std :: string str = str2;
        str[i] = j + '0'; int x;
        if(str[0] == '0' && str.length() > 1) continue;
        x = calc(str, 3);
        if(hash.count(x)) printf("%d", x);
      }
  return 0;
}