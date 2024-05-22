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
const int MaxN = 1e6 + 200;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int n, pos[MaxN], cnt;
std :: string s1, s2;
std :: map <char, int> m;
int main() {
  n = read();
  std :: cin >> s1 >> s2;
  for(int i = 0; i < n; ++ i) {
    if(s1[i] != s2[i]) pos[++cnt] = i;
    else {
      m[s1[i]] ++;
      if(m[s1[i]] > 1) pos[0] = -1;
    }
  }
  if(cnt == 2 && s1[pos[1]] == s2[pos[2]] && s1[pos[2]] == s2[pos[1]]) std :: cout << "YES";
  else if(pos[0] == -1 && cnt == 0) std :: cout << "YES"; 
  else std :: cout << "NO";
  return 0;
}