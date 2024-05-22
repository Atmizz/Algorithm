#include <cstdio>
#include <queue>
#include <stack>
#include <cmath>
#include <cstdlib>
#include <map>
#include <vector>
#include <iostream>
#include <cstring>
#include <set>
#include <algorithm>
#define gc getchar()
typedef unsigned long long ll;
inline int read() {
	int s = 0, f = 1; char ch = gc;
	for(; ch < '0' || ch > '9'; ch = gc) if(ch == '-') f = - 1;
	for(; ch >= '0' && ch <= '9'; ch = gc) s = (s << 3) + (s << 1) + (ch ^ 48);
	return s * f;
}
inline int abs(int a) { return a < 0 ? -a : a;}
inline int max(int a, int b) { return a > b ? a : b;}
inline int min(int a, int b) { return a < b ? a : b;}
const int MaxN = 1e6 + 200;
const int mod = 1e9 + 7;
const int INF = 0x7fffffff;
int N, n;
int main() {
	N = read();
	std :: cout << 0;
	if(N > 40620) std :: cout << N % 40320 + 1;
	else std :: cout << ++ n;
	while (N > 40320) N -= 40320;
	
	if(N > 5040) std :: cout << N % 5040 + 1;
	else std :: cout << ++ n;
	while (N > 5040) N -= 5040;
	
	if(N > 720) std :: cout << N % 720 + 1;
	else std :: cout << ++ n;
	while (N > 720) N -= 720;
	
	if(N > 120) std :: cout << N % 120 + 1;
	else std :: cout << ++ n;
	while (N > 120) N -= 120;
	
	if(N > 24) std :: cout << N % 24 + 1;
	else std :: cout << ++ n;
	while (N > 24) N -= 24;
	
	if(N > 6) std :: cout << N % 6 + 1;
	else std :: cout << ++ n;
	while (N > 6) N -= 6;
	
	if(N > 2) std :: cout << N % 2 + 1;
	else std :: cout << ++ n;
	while (N > 2) N -= 2;
	
	if(N > 1) std :: cout << N % 1 + 1;
	else std :: cout << ++ n;
	while (N > 1) N -= 1;

	std :: cout << ++ n;
}