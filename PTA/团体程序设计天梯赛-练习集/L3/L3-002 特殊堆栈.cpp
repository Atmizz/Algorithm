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
int n, mid;
std :: stack <int> s;
std :: vector <int> a;
int main() {
  n = read();
  for(int i = 1; i <= n; ++ i) {
    std :: string str; int x;
    std :: cin >> str;
    if(str == "Push") {
      x = read();
      auto u = std :: lower_bound(a.begin(), a.end(), x);
      a.insert(u, x); s.push(x);
    } else {
      if(s.empty()) {
        std :: cout << "Invalid\n";
        continue;
      }
      if(str == "Pop") {
        auto u = std :: lower_bound(a.begin(), a.end(), s.top());
        printf("%d\n", s.top());
        a.erase(u); s.pop();
      } else {
        printf("%d\n", a[s.size() % 2 ? (((s.size()+1) >> 1) - 1) : ((s.size() >> 1) - 1)]);
      }
    }
  }
  return 0;
}