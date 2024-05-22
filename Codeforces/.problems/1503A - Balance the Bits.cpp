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
const int MaxN = 2e5 + 200;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int T, n;
void solve() {
  n = read();
  std :: string str; std :: cin >> str;
  std :: vector <char> ans(n);
  int cnt0 = 0, cnt1 = 0;
  for(int i = 0; i < n; ++ i)
    if(str[i] == '1') cnt1 ++;
    else cnt0 ++;
  if(cnt0 & 1 || str[0] == '0' || str[n-1] == '0') {
    puts("NO");
    return ;
  }
  bool flag = false;
  for(int i = 0; i < n; ++ i)
    if(str[i] == '1') {
      if(cnt1) ans[i] = '(', cnt1 -= 2;
      else ans[i] = ')';
    } else {
      if(!flag) ans[i] = ')';
      else ans[i] = '(';
      flag ^= 1;
    }
  puts("YES");
  for(auto x : ans) putchar(x);
  puts("");
  for(int i = 0; i < n; ++ i)
    putchar(str[i] == '1' ? ans[i] : (ans[i] == '(' ? ')' : '('));
  puts("");
}
int main() {
  T = read();
  while(T --) solve();
  return 0;
}