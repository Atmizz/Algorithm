#include <bits/stdc++.h>
#define gc getchar()
typedef long long ll;
inline int read() {
	int s = 0, f = 1; char ch = gc;
	for(; ch < '0' || ch > '9'; ch = gc)
		if(ch == '-') f = -1;
	for(; ch >= '0' && ch < '9'; ch = gc)
		s = (s << 1) + (s << 3) + (ch ^ 48);
	return s * f;
}
int main() {
	int n = read();
	for(int i = 1; i <= n; ++ i) {
		char ch = gc;
		std :: stack <char> str;
		while(ch != '\n') {
			if(ch == ' ') {
				int Num = str.size();
				for(int j = 1; j <= Num; ++ j)
					std :: cout << str.top(), str.pop();
				std :: cout << ' ';
			} else str.push(ch);
			ch = gc;
		}
		int Num = str.size();
			for(int j = 1; j <= Num; ++ j)
				std :: cout << str.top(), str.pop();
		puts("");
	}
}