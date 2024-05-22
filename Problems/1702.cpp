#include <bits/stdc++.h>
#define gc getchar()
typedef long long ll;
const int MaxN = 1e6 + 200;
inline int abs(int x) {return x < 0 ? -x : x;}
inline max(int a, int b) {return a > b ? a : b;}
inline min(int a, int b) {return a < b ? a : b;}
inline int read() {
    int s = 0, f = 1; char ch = gc;
    for(; ch < '0' || ch > '9'; ch = gc) if(ch == '-') f = -1;
    for(; ch >= '0' && ch <= '9'; ch = gc)
        s = (s << 1) + (s << 3) + (ch ^ 48);
    return s * f;
}
int main() {
  int n = read();
  for(int i = 1; i <= n; ++ i) {
  	int m = read(); std :: string str;
  	std :: cin >> str;
  	if(str == "FIFO") {
  		std :: queue <int> Q;
  		for(int j = 1; j <= m; ++ j) {
  			std :: string str1; int k;
				std :: cin >> str1;
				if(str1 == "IN")
					k = read(), Q.push(k);
				else if(str1 == "OUT" && (!Q.empty())) printf("%d\n", Q.front()), Q.pop();
				else printf("None\n");
  		}
  	} else {
  		std :: stack <int> S;
  		for(int j = 1; j <= m; ++ j) {
  			std :: string str1; int k;
				std :: cin >> str1;
				if(str1 == "IN")
					k = read(), S.push(k);
				else if(str1 == "OUT" && (!S.empty())) printf("%d\n", S.top()), S.pop();
				else printf("None\n");
  		}
  	}
  }
}