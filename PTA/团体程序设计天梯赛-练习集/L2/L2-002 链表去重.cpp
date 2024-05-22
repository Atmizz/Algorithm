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
int n, vis[MaxN], val[MaxN];
std :: string pos[MaxN], net[MaxN];
std :: map <std :: string, int> m;
struct Node {
  std :: string pos;
  int val;
};
std :: vector <Node> a1, a2;
int main() {
  std :: string str; std :: cin >> str; n = read();
  for(int i = 1; i <= n; ++ i) {
    std :: cin >> pos[i]; val[i] = read(); std :: cin >> net[i];
    m[pos[i]] = i;
  } int x = m[str];
  while(1) {
    // std :: cout << x << '\n';
    if(!vis[abs(val[x])]) a1.push_back({pos[x], val[x]}), vis[abs(val[x])] = 1;
    else a2.push_back({pos[x], val[x]});
    if(net[x] == "-1") break;
    x = m[net[x]];
  } int m1 = a1.size(), m2 = a2.size();
  for(int i = 0; i <= m1 - 2; ++ i)
    std :: cout << a1[i].pos << ' ' << a1[i].val << ' ' << a1[i+1].pos << '\n';
  std :: cout << a1[m1-1].pos << ' ' << a1[m1-1].val << " -1\n";
  if(a2.size()) {
    for(int i = 0; i <= m2 - 2; ++ i)
      std :: cout << a2[i].pos << ' ' << a2[i].val << ' ' << a2[i+1].pos << '\n';
    std :: cout << a2[m2-1].pos << ' ' << a2[m2-1].val << " -1\n";
  }
  return 0;
}