#include <bits/stdc++.h>
#define ls k << 1
#define rs k << 1 | 1
#define gc getchar()
typedef long long ll;
inline ll read() {
  ll s = 0, f = 1; char ch = gc;
  for(; ch < '0' || ch > '9'; ch = gc) if(ch == '-') f = -1;
  for(; ch >= '0' && ch <= '9'; ch = gc)
    s = (s << 1) + (s << 3) + (ch ^ 48);
  return s * f;
}
inline int abs(int a) {return a < 0 ? -a : a;}
inline int min(int a, int b) {return a < b ? a : b;}
inline int max(int a, int b) {return a > b ? a : b;}
const int MaxN = 0;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
ll l, m, ans[7], num[7];
int main() {
  l = read(); m = read(); ll sum = 1ll; num[0] = 1ll;
  for(int i = 1; i <= l; ++ i) sum *= 26, num[i] = num[i-1] * 26;
  ll n = sum - m;
  for(int i = l; i >= 1; -- i)
    ans[i] = n / num[i-1], n -= ans[i] * num[i-1];
  for(int i = l; i >= 1; -- i)
    std :: cout << char(ans[i] + 'a');
  return 0;
}