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
const int MaxN = 1001;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int Next[MaxN], ans;
void getNext(std :: string s) {
  memset(Next, 0, sizeof Next);
  int i = 0, j = - 1, len = s.length(); Next[0] = -1;
  while(i < len)
    if(j == - 1 || s[i] == s[j]) i ++, j ++, Next[i] = j;
    else j = Next[j];
}
void doKmp(std :: string s1, std :: string s2) {
  int i = 0, j = 0, len1 = s1.length(), len2 = s2.length();
  while(i < len1) {
    if(s1[i] == s2[j] || j == -1) i ++, j ++;
    else j = Next[j];
    if(j == len2) ans ++, j = 0;
  }
}
void doPrint() {
  printf("%d\n", ans);
}
int main() {
  while(1) {
    std :: string s1, s2;
    std :: cin >> s1;
    if(s1 == "#") break;
    std :: cin >> s2; ans = 0;
    getNext(s2); doKmp(s1, s2); doPrint();
  }
  return 0;
}