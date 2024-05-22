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
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int PK[MaxN][2], pk[MaxN][2], cnt1 = 1, cnt2 = 1, ans;
int main() {
  while(1) {
    char ch = gc;
    if(ch == 'E') break;
    if(ch == 'W') {
      PK[cnt1][0] ++; pk[cnt2][0] ++; 
      if(PK[cnt1][0] >= 11 && abs(PK[cnt1][0] - PK[cnt1][1]) >= 2) cnt1 ++;
      if(pk[cnt2][0] >= 21 && abs(pk[cnt2][0] - pk[cnt2][1]) >= 2) cnt2 ++;
    } 
    if(ch == 'L') {
      PK[cnt1][1] ++; pk[cnt2][1] ++; 
      if(PK[cnt1][1] >= 11 && abs(PK[cnt1][1] - PK[cnt1][0]) >= 2) cnt1 ++;
      if(pk[cnt2][1] >= 21 && abs(pk[cnt2][1] - pk[cnt2][0]) >= 2) cnt2 ++;
    }
  }

    for(int i = 1; i <= cnt1; ++ i)
      printf("%d:%d\n", PK[i][0], PK[i][1]);
  //  if(PK[cnt1][0] || PK[cnt1][1]) printf("%d:%d\n", PK[cnt1][0], PK[cnt1][1]);
    puts("");
    for(int i = 1; i <= cnt2; ++ i)
      printf("%d:%d\n", pk[i][0], pk[i][1]);  
 //   if(pk[cnt2][0] || pk[cnt2][1]) printf("%d:%d\n", pk[cnt2][0],pk[cnt2][1]);
  
}