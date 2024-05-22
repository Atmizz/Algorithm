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
const int MaxN = 1003;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
std :: string str;
int len, ans;
bool check(int l, int r) {
  int le = r - l + 1;
  if(le == 1) return true;
  le >>= 1;
  for(int i = 0; i <= le; ++ i)
    if(str[l+i] != str[r-i]) return false;
  return true;
}
int main() {
  getline(std :: cin, str); len = str.length();
  for(int i = 0; i < len; ++ i)
    for(int j = len - 1; j >= i; -- j)
      if(str[i] == str[j])
        if(check(i, j)) {ans = max(ans, j - i + 1); break;}
  printf("%d", ans);
  return 0;
}