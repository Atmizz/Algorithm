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
const int MaxN = 1e6 + 10;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int len;
std :: unordered_map <ll, char> val;
std :: string str;
void dfs(ll k, int &pos) {
  val[k] = str[pos];
  // std :: cout << k << ' ' << val[k] << '\n';
  if(val[k] == '#') return ;
  dfs(ls, ++ pos); dfs(rs, ++ pos);
  return ;
}
void Print(int k) {
  if(val[k] == '#') return ;
  Print(ls); std :: cout << val[k] << ' '; Print(rs);
}
int main() {
  std :: cin >> str; str = '0' + str;
  int pos = 1; dfs(1ll, pos); Print(1);
  return 0;
}