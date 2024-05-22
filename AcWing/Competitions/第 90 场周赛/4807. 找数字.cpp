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
int n, s;
bool dfs(int step, int sum, std :: string str) {
  std :: cout << step << " " << sum << " " << str << '\n';
  if(sum > s || (sum == s && step < n) || step > n) return false;
  if(sum == s && step == n) {
    std :: cout << str << " "; 
    for(int i = str.length() - 1; i >= 0; -- i)
      std :: cout << str[i];
    return true;
  }
  for(int i = 0; i <= 9; ++ i)
    if(dfs(step + 1, sum + i, str + char(i + 48)))
      return true;
  return false;
}
int main() {
  n = read(), s = read();
  for(int i = 1; i <= 9; ++ i) { 
    std :: string str = "";
    str += char(i + 48);
    if(dfs(1, i, str)) return 0;
  }
  printf("-1 -1");
  return 0;
}