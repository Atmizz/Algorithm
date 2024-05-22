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
const int MaxN = 20;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
std :: string ans, str;
int a, b;
void dfs(int k, int x, int y, std :: string s) {
  if(k == str.length()) {
    if(s > ans) ans = s;
    return ;
  }
  int a1 = 9 + '0' - str[k], a2 = str[k] - '0' + 1;
  // std :: cout << "k : " << k << '\n';
  // std :: cout << a1 << ' ' << a2 << '\n';
  if(a1 + x <= a && a2 + y <= b) dfs(k + 1, a1 + x, y, s + "9"), dfs(k + 1, x, a2 + y, s + "9");
  else if(a1 + x <= a) dfs(k + 1, a1 + x, y, s + "9");
  else if(a2 + y <= b) dfs(k + 1, x, y + a2, s + "9");
  else dfs(k + 1, a, y, s + char(a - x + str[k]));
}
int main() {
  std :: cin >> str; a = read(); b = read();
  dfs(0, 0, 0, ""); std :: cout << ans;
  return 0;
}