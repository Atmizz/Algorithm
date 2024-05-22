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
inline int abs(int a) {return a < 0 ? -a : a;}
inline int min(int a, int b) {return a < b ? a : b;}
inline int max(int a, int b) {return a > b ? a : b;}
const int MaxN = 2e5 + 200;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int dp[MaxN], v[MaxN], p[MaxN], q[MaxN], n, m, Num[MaxN][3];
int main() {
  m = read(); n = read();
  for(int i = 1; i <= n; ++ i) {
      v[i] = read(), p[i] = read(), q[i] = read();
      if(q[i] != 0) Num[q[i]][0] ++, Num[q[i]][Num[q[i]][0]] = i;
  }
/*
  for(int i = 1; i <= n; ++ i)
    if(q[i] == 0) std :: cout << i << " " << Num[i][0] <<  " "  << Num[i][1] << " " << Num[i][2] << '\n';
*/
  for(int i = 1; i <= n; ++ i)
    if(q[i] == 0)
      for(int j = m; j >= 0; -- j) {
        if(v[i] > j) continue ;
       // std :: cout << dp[j] << " i : " << i << " " << j << "  ";
        dp[j] = max(dp[j - v[i]] + p[i] * v[i], dp[j]);/*, std :: cout << dp[j] << " " << j << '\n';*/
        
        if(Num[i][0] == 1)
          if(j >= v[i] + v[Num[i][1]]) dp[j] = max(dp[j-v[i]-v[Num[i][1]]] + p[i] * v[i] + v[Num[i][1]] * p[Num[i][1]], dp[j]);
        if(Num[i][0] == 2) {
          if(j >= v[i] + v[Num[i][1]]) dp[j] = max(dp[j-v[i]-v[Num[i][1]]] + p[i] * v[i] + v[Num[i][1]] * p[Num[i][1]], dp[j]);
          if(j >= v[i] + v[Num[i][2]]) dp[j] = max(dp[j-v[i]-v[Num[i][2]]] + p[i] * v[i] + v[Num[i][2]] * p[Num[i][2]], dp[j]);
          if(j >= v[i] + v[Num[i][1]] + v[Num[i][2]])
            dp[j] = max(dp[j], dp[j-v[i]-v[Num[i][1]]-v[Num[i][2]]] + v[i] * p[i] + v[Num[i][1]] * p[Num[i][1]] + v[Num[i][2]] * p[Num[i][2]]);
//          std :: cout << dp[j] << j << '\n';
        } //std :: cout << dp[j] << '\n';
      } printf("%d", dp[m]);
	return 0; 
}