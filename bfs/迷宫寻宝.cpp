#include<iostream>
#include<string.h>
#define MOD 1000000007
using namespace std;
int n,m,k;
int C[50][50];
//��̬�滮 
int dp[50][50][13][13];
/*iΪx�ᣬjΪy�ᣬindexΪ��Ʒ������max_vΪ��ֵ 
�����ÿһ�����Ӷ������ں�����Ϊi ������Ϊj ��Ʒ����Ϊindex ����ֵΪmax_v������µ���󷽰���*/
int DP(){
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			// indexΪ��Ʒ����
			for(int index=0;index<=k;++index){
				// max_vΪ����ֵ
				for(int max_v=0;max_v<13;++max_v){
					// ��һ������
					if(i==1&&j==1){
						// index == 0��ʾ��û�õ�ǰ��Ʒ�����
                        // index == 1��ʾ�����˵�ǰ��Ʒ���������max_v > C[1][1]���Ҽ�ֵ���ڵ�һ�����ӵļ�ֵ
                        // �ڵ�һ�е�һ��
                        // ��û�õ�ǰ��Ʒ ��ô��������ֻ��1��
                    	// ���õ�ǰ��Ʒ���ҵ�ǰ��Ʒ�ļ�ֵҪС��z����Ȼ�Ų��£�
						if(index==0||(index==1&&C[1][1]<max_v)){
							dp[i][j][index][max_v]=1;
						}
						continue;
					}
					long na=0,buna=0;//һ��Ҫ��ʼ��Ϊ0 
					// ���index��=0�ͱ�ʾ��������һ����Ʒ
                	// max_v > C[i][j]ǰ��Ʒ���ҵ�ǰ��Ʒ�ļ�ֵҪС��z
					if(index!=0&&C[i][j]<max_v){
						//��Ϊֻ�������ߺ���������ô��ֻ���������
                        //�����������ģ�����߹�����
                        //����i-1,���j-1
                        //index - 1��ʾ��Ʒ������һ�������
                        //��������ǰ���dp��max_v��C[i][j]
						na=dp[i-1][j][index-1][C[i][j]]+dp[i][j-1][index-1][C[i][j]];
					}
					//���õ����
                    //Ҳ�������������������ģ�����߹�����
                    //��Ϊû���ã���ôindexҲ����Ҫ��һ
					buna=dp[i-1][j][index][max_v]+dp[i][j-1][index][max_v];
					dp[i][j][index][max_v]=(na+buna)%MOD;
				}
			}
		}
	}
	return dp[n][m][k][12];
}
//dfs+���仯���� 
int cache[50][50][14][13];
int dir[][2]={{0,1},{1,0}};
int dfs(int x,int y,int index,int max_v){
	// x == n || y == m �߽��ж�
    // cnt > k ��֦ �����ǰ�õ�����Ʒ��������k���Ļ���ô�Ͳ��ü�������ȥ��
	if(index>k||x==n||y==m) return 0;//��֦ 
	
	// ���������-1˵��ֵ�Ѿ������
	if(cache[x][y][index][max_v+1]!=-1){
		return cache[x][y][index][max_v+1];
	}
	
	int ans=0;
	// �����յ�����
	if(x==n-1&&y==m-1){
		if(index==k||(index=k-1&&C[x][y]>max_v))
		// ��Ϊ���ڻ�����û���õ�ǰ��Ʒ����� ��������ǰ��Ʒ�ļ�ֵ����֮ǰ������Ʒ������ֵ��ôcnt��Ҫ+1
			ans=(ans+1)%MOD;
		return ans;
	}
	
	int cur=C[x][y];
	// �õ�ǰ��Ʒ�����
	if(cur>max_v){
		ans+=dfs(x+1,y,index+1,cur);
		ans+=dfs(x,y+1,index+1,cur);
	}
	//���õ�ǰ��Ʒ�����
	ans+=dfs(x+1,y,index,max_v);
	ans+=dfs(x,y+1,index,max_v);
	//��¼������Ϊx��������Ϊy,ֵΪmax,�õ���Ʒ����Ϊcnt�����	
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
