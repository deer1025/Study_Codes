#include<iostream>
#include<string.h>
#define MOD 1000000007
using namespace std;
int n,m,k;
int C[50][50];
//动态规划 
int dp[50][50][13][13];
/*i为x轴，j为y轴，index为物品数量，max_v为价值 
这里的每一个格子都代表在横坐标为i 纵坐标为j 物品数量为index 最大价值为max_v的情况下的最大方案数*/
int DP(){
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			// index为物品数量
			for(int index=0;index<=k;++index){
				// max_v为最大价值
				for(int max_v=0;max_v<13;++max_v){
					// 第一个格子
					if(i==1&&j==1){
						// index == 0表示我没拿当前物品的情况
                        // index == 1表示我拿了当前物品的情况并且max_v > C[1][1]并且价值大于第一个格子的价值
                        // 在第一行第一列
                        // 我没拿当前物品 那么方案数就只有1个
                    	// 我拿当前物品并且当前物品的价值要小于z（不然放不下）
						if(index==0||(index==1&&C[1][1]<max_v)){
							dp[i][j][index][max_v]=1;
						}
						continue;
					}
					long na=0,buna=0;//一定要初始化为0 
					// 如果index！=0就表示最少拿了一个物品
                	// max_v > C[i][j]前物品并且当前物品的价值要小于z
					if(index!=0&&C[i][j]<max_v){
						//因为只能向下走和向右走那么就只有两种情况
                        //从上面下来的，从左边过来的
                        //上面i-1,左边j-1
                        //index - 1表示物品数量少一个的情况
                        //由于上面前面的dp的max_v是C[i][j]
						na=dp[i-1][j][index-1][C[i][j]]+dp[i][j-1][index-1][C[i][j]];
					}
					//不拿的情况
                    //也是两种情况从上面过来的，从左边过来的
                    //因为没有拿，那么index也不需要减一
					buna=dp[i-1][j][index][max_v]+dp[i][j-1][index][max_v];
					dp[i][j][index][max_v]=(na+buna)%MOD;
				}
			}
		}
	}
	return dp[n][m][k][12];
}
//dfs+记忆化搜索 
int cache[50][50][14][13];
int dir[][2]={{0,1},{1,0}};
int dfs(int x,int y,int index,int max_v){
	// x == n || y == m 边界判断
    // cnt > k 剪枝 如果当前拿到的物品数量大于k件的话那么就不用继续拿下去了
	if(index>k||x==n||y==m) return 0;//剪枝 
	
	// 如果不等于-1说该值已经计算过
	if(cache[x][y][index][max_v+1]!=-1){
		return cache[x][y][index][max_v+1];
	}
	
	int ans=0;
	// 到达终点的情况
	if(x==n-1&&y==m-1){
		if(index==k||(index=k-1&&C[x][y]>max_v))
		// 因为现在还处于没有拿当前物品的情况 因此如果当前物品的价值大于之前所拿物品的最大价值那么cnt就要+1
			ans=(ans+1)%MOD;
		return ans;
	}
	
	int cur=C[x][y];
	// 拿当前物品的情况
	if(cur>max_v){
		ans+=dfs(x+1,y,index+1,cur);
		ans+=dfs(x,y+1,index+1,cur);
	}
	//不拿当前物品的情况
	ans+=dfs(x+1,y,index,max_v);
	ans+=dfs(x,y+1,index,max_v);
	//记录横坐标为x，纵坐标为y,值为max,拿的物品数量为cnt的情况	
	cache[x][y][index][max_v+1]=ans%MOD;
	return ans%MOD;
}
int main(){
	cin>>n>>m>>k;
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			cin>>C[i][j];
		}
	}
	memset(cache,-1,sizeof(cache));
	cout<<dfs(0,0,0,-1)<<endl;
	cout<<DP()<<endl;
	return 0;
}
