#include <bits/stdc++.h>
#define gc getchar()
typedef long long ll;
const int MaxN = 1e6 + 200;
inline int abs(int x) {return x < 0 ? -x : x;}
inline int max(int a, int b) {return a > b ? a : b;}
inline int min(int a, int b) {return a < b ? a : b;}
inline int read() {
    int s = 0, f = 1; char ch = gc;
    for(; ch < '0' || ch > '9'; ch = gc) if(ch == '-') f = -1;
    for(; ch >= '0' && ch <= '9'; ch = gc)
        s = (s << 1) + (s << 3) + (ch ^ 48);
    return s * f;
}
int n, m, Pos, N, Num;
bool ans[MaxN];
int main() {
    while(~scanf("%d %d", &n, &m)) {
        std :: vector <int> a; Pos = 0, N = n, Num = n * 2; m --;
        for(int i = 0; i < Num; ++ i) a.push_back(i);
        memset(ans, 0, sizeof ans);
        while(a.size() > N) {
            Pos += m; Pos = Pos % Num; Num --;
            ans[a[Pos]] = 1;
            a.erase(a.begin() + Pos);
    /*
            std :: cout << '\n';
            for(int i = 1; i <= a.size(); ++ i) std :: cout << a[i-1] << " ";
            std :: cout << '\n';
    */
        }
        /*
        for(int i = 0; i < 2 * n; ++ i)
            std :: cout << "ans "  << i << " " << ans[i] << '\n';
        */
        for(int i = 0; i < 2 * n; ++ i) {
        	if(i % 50 == 0 && i != 0) std :: cout << '\n';
					if(ans[i]) std :: cout << 'B';
	        else std :: cout << 'G';
        }
        std :: cout << '\n' << '\n';
    }
}