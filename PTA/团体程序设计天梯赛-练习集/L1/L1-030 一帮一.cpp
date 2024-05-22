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
const int MaxN = 55;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
struct Node {
  std :: string s1, s2;
  int rank;
  friend bool operator < (Node a, Node b) {
    return a.rank < b.rank;
  }
}a[MaxN];
struct Rank {
  std :: string name;
  int rank;
};
int main() {
  int n = read(), cnt = 0;
  std :: deque <Rank> man, woman;
  for(int i = 1; i <= n; ++ i) {
    int opt = read(); std :: string name;
    std :: cin >> name;
    if(opt == 0) woman.push_back({name, i});
    else man.push_back({name, i});
  }
  while(man.size())
    a[++cnt] = {man.front().rank < woman.back().rank ? man.front().name : woman.back().name, man.front().rank < woman.back().rank ? woman.back().name : man.front().name, min(man.front().rank, woman.back().rank)}, man.pop_front(), woman.pop_back();
  std :: sort(a + 1, a + 1 + (n >> 1));
  for(int i = 1; i <= n >> 1; ++ i)
    std :: cout << a[i].s1 << ' ' << a[i].s2 << '\n';
  return 0;
}