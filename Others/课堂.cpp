#include<bits/stdc++.h>
#define left 0
#define right 1
#define INF 0x7ffffff
//INF一定不能设成0x7fffffff，否则就会像我在单词划分那道题一样爆int 
using namespace std;
struct node{
	int m;
	int w;
}lamp[105];
int dp[105][105][2],n,c;
int sum[105][105],v[105];
int main(){
	scanf("%d%d",&n,&c);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&lamp[i].m,&lamp[i].w);//读入 
	for(int i=1;i<=n;i++)
		v[i]=v[i-1]+lamp[i].w;//前缀和 
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			dp[i][j][0]=dp[i][j][1]=INF;//初始化dp数组 

	dp[c][c][0]=dp[c][c][1]=0;//因为老张一开始就在c处，所以c盏灯一开始就是关掉的

	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			sum[i][j]=v[n]-(v[j]-v[i-1]);//表示在关完第i盏灯到第j盏灯后每s所耗电量 
			
	for(int i=c;i>0;i--){//此处要从大到小枚举，否则会在决策时用到之前没求过的量，从大到小枚举就可以有效的避免，（具体证明参见我的luogu blog中石子合并的题解），当然也可以在这一层循环枚举有限的长度，本质不变 
		for(int j=i+1;j<=n;j++){
			dp[i][j][left]=min(dp[i+1][j][left]+(lamp[i+1].m-lamp[i].m)*sum[i+1][j],dp[i+1][j][right]+(lamp[j].m-lamp[i].m)*sum[i+1][j]);
			dp[i][j][right]=min(dp[i][j-1][left]+(lamp[j].m-lamp[i].m)*sum[i][j-1],dp[i][j-1][right]+(lamp[j].m-lamp[j-1].m)*sum[i][j-1]);
		//状态转移 
		}
	}
	int ans=min(dp[1][n][0],dp[1][n][1]);//因为到了最后仍有两种情况，所以要判断 
	cout<<ans<<endl;
	return 0;
}
