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
const int MaxN = 5e3 + 200;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int n, m;
std :: map <std :: string, int> ez;
std :: vector <std :: string> List, ans;
int main() {
  n = read();
  for(int i = 1; i <= n; ++ i) {
    std :: string str;
    std :: cin >> str;
    ez[str] = -1;
  } m = read(); int sum = 0;
  for(int i = 1; i <= m; ++ i) {
    std :: string str; int x;
    std :: cin >> str; x = read();
    List.push_back(str);
    if(ez[str] != -1) ez[str] = x;
    sum += x;
  } sum /= m;
  for(auto str : List)
    if(ez[str] > sum && ez[str] != -1) ans.push_back(str);
  std :: sort(ans.begin(), ans.end());
  if(ans.size()) 
    for(auto str : ans) std :: cout << str << '\n';
  else printf("Bing Mei You");
  return 0;
}