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
std :: vector <std :: string> a;
int main() {
  while(1) {
    std :: string str;
    std :: cin >> str;
    if(str == ".") break;
    a.push_back(str);
  }
  if(a.size() <= 1) std :: cout << "Momo... No one is for you ...";
  else if(a.size() < 14) std :: cout << a[1] << " is the only one for you...";
  else std :: cout << a[1] << " and " << a[13] << " are inviting you to dinner...";
  return 0;
}