#include<stdio.h>
int max(int x,int y){
	return (x>y)?x:y;
} 
int main(){
	int n1,n2;
	char g1[100],g2[100];
	scanf("%d %s",&n1,g1);         //第一个基因的长度和序列 
	scanf("%d %s",&n2,g2);         //第二个基因的长度和序列 
	int value[5][5]={
	{5,-1,-2,-1,-3},
    {-1,5,-3,-2,-4},
    {-2,-3,5,-2,-2},
    {-1,-2,-2,5,-1},
    {-3,-4,-2,-1,0}
	};                                //碱基对应转换值 
	int v1[100],v2[100];
//	for(int i=n1;i>=1;i--)
//	g1[i]=g1[i-1];
	for(int i=0;i<n1;i++){    //将碱基转换为数字，便于后续计算 
		if (g1[i]=='A') v1[i]=0;
        else if (g1[i]=='C') v1[i]=1;
        else if (g1[i]=='G') v1[i]=2;
        else v1[i]=3;
	}
//	for(int i=n2;i>=1;i--)
//	g2[i]=g2[i-1];
	for(int i=0;i<n2;i++){
		if (g2[i]=='A') v2[i]=0;
        else if (g2[i]=='C') v2[i]=1;
        else if (g2[i]=='G') v2[i]=2;
        else v2[i]=3;
	}
	int sum[100][100];
	for(int i=0;i<=n1;i++)
     for(int j=0;j<=n2;j++){
     	sum[i][j]=0;
	 }
	for(int i=1;i<=n1;i++)
     sum[i][0]=sum[i-1][0]+value[v1[i-1]][4];
  for(int i=1;i<=n2;i++)
    sum[0][i]=sum[0][i-1]+value[4][v2[i-1]];
  for(int i=1;i<=n1;i++){
    for(int j=1;j<=n2;j++){
        sum[i][j]=max(sum[i][j],sum[i-1][j]+value[v1[i-1]][4]);     //  v1[i]与空碱基匹配 
        sum[i][j]=max(sum[i][j],sum[i][j-1]+value[4][v2[j-1]]);     //  v2[j]与空碱基匹配 
        sum[i][j]=max(sum[i][j],sum[i-1][j-1]+value[v1[i-1]][v2[j-1]]);   // v1[i]与v2[j]匹配 
    }
  }
    for(int i = 1; i <= n1; ++ i) {
        for(int j = 1; j <= n2; ++ j) {
            printf("%d ", sum[i][j]);
        }
      puts("");
    }
    printf("%d",sum[n1][n2]);
	return 0;
}