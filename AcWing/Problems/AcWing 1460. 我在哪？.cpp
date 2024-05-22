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
const int MaxN = 107;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int n;
std :: string str;
bool check(int k) {
  std :: unordered_set<std :: string> hash;
  for(int i = 0; i + k - 1 < n; ++ i) {
    std :: string s = str.substr(i, k);
    if(hash.count(s)) return false;
    hash.insert(s);
  } return true;
}
int main() {
  n = read(); std :: cin >> str;
  int l = 1, r = n, mid;
  while(l < r) {
    mid = (l + r) >> 1;
    if(check(mid)) r = mid;
    else l = mid + 1;
  } printf("%d", l);
  return 0;
}