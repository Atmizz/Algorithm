#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <stack>
#include <algorithm>
#define N 1000001
using namespace std;
inline int read()
{
	int s = 0 , f = 1 ;
	char ch = getchar();
	while(ch < '0' || ch > '9') {
		if(ch == '-')
			f = - 1 ;
		ch = getchar() ;
	}
	while(ch >= '0' && ch <= '9') {
		s = s * 10 + ch - '0' ;
		ch = getchar();
	}
	return s * f ;
}
int n , m , T , x , team[N] = {0} ;
string str;
queue<int>q; // 这个队列是存入小组序号 
queue<int>fa[301]; // 对应的小组序号存入对应的小组的人 
int main()
{
	n = read() ; m = read() ;
	for(int i = 0 ; i < n ; ++ i)
		team[i] = read() ; // 从 0 开始排的 
	T = read() ;
	for(int k = 1 ; k <= T ; ++ k) {
		cin >> str ;
		if(str == "push") {
			x = read() ;
			if(fa[team[x]].empty()) // 如果元素队列为空，那么说明小组队列中没有对影的小组 
				q.push(team[x]);
			fa[team[x]].push(x); // 对应的小组存入元素 
		}
		else {
			int u = q.front();
			printf("%d\n",fa[u].front()); // 输出当前小组的第一位元素 
			fa[u].pop(); // 元素弹出 
			if(fa[u].empty()) // 为空，小组队列弹出第一个小组 
				q.pop();
		}
	}
	return 0;
}