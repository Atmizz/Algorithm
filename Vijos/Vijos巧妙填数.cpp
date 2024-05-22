#include <bits/stdc++.h>
#define gc getchar()
#define ll long long
inline int read() {
	int s = 0, f = 1; char ch = gc;
	for(; ch < '0' || ch > '9'; ch = gc) if(ch == '-') f = -1;
	for(; ch >= '0' && ch <= '9'; ch = gc)
		s = (s << 1) + (s << 3) + (ch ^ 48);
	return s * f;
}
const int MaxN = 5e5 + 200;
const int Mod = 11;
const int INF = 2147483647;
bool flag[10];
bool Check(int x) {
//  std :: cout << x  << " " << x / 100 << " " << x % 100 / 10 << " " << x % 10 <<'\n'; 
  if(flag[x % 10] || x % 10 == 0) return 0;
  flag[x % 10] = 1;
  if(flag[(x % 100) / 10] || (x % 100) / 10 == 0) return 0;
  flag[(x % 100) / 10] = 1;
  if(flag[x / 100]) return 0;
  flag[x / 100] = 1;
  return 1;
}
int main() {
	for(int i = 102; i <= 333; ++ i) {
    for(int j = 1; j <= 9; ++ j) flag[j] = 0;
      if(Check(i) == 0 || Check(i * 2) == 0 || Check(i * 3) == 0) continue;
      std :: cout << i << " " << i * 2 << " " << i * 3 << '\n';
  }
	return 0;
}