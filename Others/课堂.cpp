#include<bits/stdc++.h>
#define left 0
#define right 1
#define INF 0x7ffffff
//INFһ���������0x7fffffff������ͻ������ڵ��ʻ����ǵ���һ����int 
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
		scanf("%d%d",&lamp[i].m,&lamp[i].w);//���� 
	for(int i=1;i<=n;i++)
		v[i]=v[i-1]+lamp[i].w;//ǰ׺�� 
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			dp[i][j][0]=dp[i][j][1]=INF;//��ʼ��dp���� 

	dp[c][c][0]=dp[c][c][1]=0;//��Ϊ����һ��ʼ����c��������cյ��һ��ʼ���ǹص���

	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			sum[i][j]=v[n]-(v[j]-v[i-1]);//��ʾ�ڹ����iյ�Ƶ���jյ�ƺ�ÿs���ĵ��� 
			
	for(int i=c;i>0;i--){//�˴�Ҫ�Ӵ�Сö�٣�������ھ���ʱ�õ�֮ǰû����������Ӵ�Сö�پͿ�����Ч�ı��⣬������֤���μ��ҵ�luogu blog��ʯ�Ӻϲ�����⣩����ȻҲ��������һ��ѭ��ö�����޵ĳ��ȣ����ʲ��� 
		for(int j=i+1;j<=n;j++){
			dp[i][j][left]=min(dp[i+1][j][left]+(lamp[i+1].m-lamp[i].m)*sum[i+1][j],dp[i+1][j][right]+(lamp[j].m-lamp[i].m)*sum[i+1][j]);
			dp[i][j][right]=min(dp[i][j-1][left]+(lamp[j].m-lamp[i].m)*sum[i][j-1],dp[i][j-1][right]+(lamp[j].m-lamp[j-1].m)*sum[i][j-1]);
		//״̬ת�� 
		}
	}
	int ans=min(dp[1][n][0],dp[1][n][1]);//��Ϊ������������������������Ҫ�ж� 
	cout<<ans<<endl;
	return 0;
}
