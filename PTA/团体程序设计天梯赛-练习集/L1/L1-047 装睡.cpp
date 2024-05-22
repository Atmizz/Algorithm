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
const int MaxN = 0;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int main() {
  int t = read(), a, b;
  std :: vector <std :: string> ans;
  while(t --) {
    std :: string name;
    std :: cin >> name;
    a = read(); b = read();
    if(a >= 15 && a <= 20 && b >= 50 && b <= 70) continue;
    ans.push_back(name);
  }
  for(auto x : ans) std :: cout << x << '\n';
  return 0;
}