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
const int MaxN = 1e5 + 20;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
std :: string str;
ll ans = 0;
ll pre[MaxN], suf[MaxN], pos[27];
int main() {
  std :: cin >> str; ll len = str.length(); str = "0" + str;
  for(int i = 1; i <= 26; ++ i) pos[i] = 0;
  for(int i = 1; i <= len; ++ i)
    pre[i] = pos[str[i]-'a'+1], pos[str[i]-'a'+1] = i;
  for(int i = 1; i <= 26; ++ i) pos[i] = len + 1;
  for(int i = len; i >= 1; -- i)
    suf[i] = pos[str[i]-'a'+1], pos[str[i]-'a'+1] = i;
  for(int i = 1; i <= len; ++ i)
    ans += (i - pre[i]) * (suf[i] - i);
  printf("%lld", ans); 
  return 0;
}