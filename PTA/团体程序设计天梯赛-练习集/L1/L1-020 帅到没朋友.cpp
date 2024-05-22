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
int n, m;
std :: unordered_set <std :: string> s;
std :: unordered_set <std :: string> check;
std :: vector <std :: string> ans, One;
int main() {
  n = read();
  while(n --) {
    int x = read();
    for(int i = 1; i <= x; ++ i) {
      std :: string S;
      std :: cin >> S;
      if(x == 1) One.push_back(S);
      else s.insert(S);
    }
  } m = read();
  while(m --) {
    std :: string S;
    std :: cin >> S;
    if(s.find(S) == s.end()) {
      if(check.find(S) == check.end()) ans.push_back(S);
      check.insert(S);
    }
  }
  for(auto S : One) {
    if(s.find(S) == s.end()) {
      if(check.find(S) == check.end()) ans.push_back(S);
      check.insert(S);
    }
  }
  if(ans.empty()) std :: cout << "No one is handsome";
  else {
    std :: cout << ans[0];
    for(int i = 1; i < ans.size(); ++ i)
      std :: cout << ' ' << ans[i];
  }
  return 0;
}