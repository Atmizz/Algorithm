#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<queue>
using namespace std;
int n,a,b,K[201]={0},v[201]={0},flag=0;
struct node {
	int fl,step;
};
void BFS() {
	node now,net;
	queue<node>q;
	now.fl=a;
	now.step=0;
	q.push(now);
	while(!q.empty()) {
		now=q.front();
		q.pop();
		if(now.fl==b)
		{
			printf("%d",now.step);
			flag=1;
			break;
		}
		if(now.fl+K[now.fl]>=1 && now.fl+K[now.fl]<=n && v[now.fl+K[now.fl]]==0) {
			net.fl=now.fl+K[now.fl];
			v[net.fl]=1;
			net.step=now.step+1;
			q.push(net);
		}
		if(now.fl-K[now.fl]>=1 && now.fl-K[now.fl]<=n && v[now.fl-K[now.fl]]==0) {
			net.fl=now.fl-K[now.fl];
			v[net.fl]=1;
			net.step=now.step+1;
			q.push(net);
		}
	}
}
int main() {
	scanf("%d %d %d",&n,&a,&b);
	for(int i=1;i<=n;i++)
		scanf("%d",&K[i]);
	v[a]=1;
	BFS();
	if(flag==0)
		printf("-1");
	return 0;
}