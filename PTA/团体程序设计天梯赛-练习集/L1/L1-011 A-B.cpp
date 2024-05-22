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
const int MaxN = 1e4 + 200;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
std :: string s1, s2;
std :: unordered_set <char> s;
int main() {
  getline(std :: cin, s1); getline(std :: cin, s2);
  int len1 = s1.length(), len2 = s2.length();
  for(int i = 0; i < len2; ++ i)
    s.insert(s2[i]);
  for(int i = 0; i < len1; ++ i)
    if(s.find(s1[i]) == s.end()) std :: cout << s1[i];
  return 0;
}