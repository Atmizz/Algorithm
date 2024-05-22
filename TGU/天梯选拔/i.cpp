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
int a[8][9], x[13];
int main() {
  char str[12];
  a[1][2] = 1; a[2][3] = 1; a[3][4] = 2; a[4][5] = 2; a[5][6] = 2; a[6][7] = a[7][8] = 1;
  scanf("%s", str + 1);
  for(int i = 1; i <= 10; ++ i) x[i] = str[i] - 48;
  a[1][1] = x[7]; a[1][0] += x[7];
  a[2][1] = x[4]; a[2][0] += x[4];
  a[3][1] = x[8]; a[3][0] += x[8];
  a[3][2] = x[2]; a[3][0] += x[2];
  a[4][1] = x[5]; a[4][0] += x[5];
  a[4][2] = x[1]; a[4][0] += x[1];
  a[5][1] = x[9]; a[5][0] += x[9];
  a[5][2] = x[3]; a[5][0] += x[3];
  a[6][1] = x[6]; a[6][0] += x[6];
  a[7][1] = x[10]; a[7][0] += x[10];
  if(x[1] == 1) {
    std :: cout << "No";
    return 0;
  }
  for(int i = 1; i < 7; ++ i)
    for(int j = i + 2; j <= 7; ++ j)
      if(a[i][0] > 0 && a[j][0] > 0)
        for(int k = i + 1; k < j; ++ k) {
          // std :: cout << i << ' ' << j << ' ' << k << ' ' << a[k][0] << '\n';
          if(a[k][0] == 0) {
            printf("Yes");
            return 0;
          }
        }
  printf("No");
  return 0;
}