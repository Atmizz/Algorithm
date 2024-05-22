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
const int MaxN = 12;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
char M[MaxN] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};
int val[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
int main() {
  int n = read(), flag = 1;
  while(n --) {
    std :: string str;
    std :: cin >> str;
    int Z = 0;
    for(int i = 0; i < 17; ++ i) {
      if(str[i] < '0' || str[i] > '9') {
        std :: cout << str << '\n';
        str[17] = M[Z%11];
        break;
      }
      Z += (str[i] - 48) * val[i];
    } Z %= 11;
    if(M[Z] != str[17]) std :: cout << str << '\n', flag = 0;
  }
  if(flag) std :: cout << "All passed";
  return 0;
}