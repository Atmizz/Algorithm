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
const int MaxN = 15;
const int Mod = 1e9 + 7;
const int INF = 2147483647;
int f[MaxN][10], ans[10];
void init() {
	for(int i = 0; i <= 9; ++ i) f[1][i] = 1;
	for(int i = 2; i < MaxN; ++ i)
		for(int j = 0; j <= 9; ++ j)
			f[i][j] += f[i-1][j] + ;
}
void dp(int n) {
	if(!n) {
		ans[0] ++;
		return ;
	}
	std :: vector <int> nums;
	while(n) nums.push_back(n % 10), n /= 10;
	for(int i = nums.size(); i >= 0; -- i) {
		int x = nums[i];
		for(int j = 0; j < 
	}
}
void solve() {
	int l = read(), r = read();
	printf("%d", dp(r) - dp(l - 1));
}
int main() {
	init(); solve();
	return 0;
}
