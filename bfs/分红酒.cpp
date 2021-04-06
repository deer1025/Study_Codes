#include<iostream>
#include<cstdio> 
#include<queue> 
#include<cstring>
using namespace std;
int full[4]={9,7,4,2};
typedef struct{
	int num[4];
	int step;
}alchol;
int vis[10][8][5][3];
int  pour(alchol &t,int i,int j){//表示从状态t把第i个瓶子倒入第j个瓶子 
	if(i==j) return 0;
	if(!t.num[i]) return 0;//i瓶已空 
	if(t.num[j]==full[j]) return 0;//j瓶已满
	//注意以下if语句两个num[i]与num[j]交换值的地方不能交换顺序 ；else语句也一样 
	if(t.num[i]+t.num[j]>full[j]){
		t.num[i]=t.num[i]-(full[j]-t.num[j]);
		t.num[j]=full[j];
	} 
	else{
		t.num[j]=t.num[i]+t.num[j];
		t.num[i]=0;
	}
	if(vis[t.num[0]][t.num[1]][t.num[2]][t.num[3]]) return 0;//表示此状态已经访问过 
	vis[t.num[0]][t.num[1]][t.num[2]][t.num[3]]=1;
	t.step++;
	return 1;
}
int main(){
	alchol st,ed;
	st.num[0]=9;
	st.num[1]=0;
	st.num[2]=0;
	st.num[3]=0;
	st.step=0;
	memset(vis,0,sizeof(vis));
	while(scanf("%d,%d,%d,%d",&ed.num[0],&ed.num[1],&ed.num[2],&ed.num[3])!=EOF){
		queue<alchol>que;
		que.push(st);
//		vis[st.num[0]][st.num[1]][st.num[2]][st.num[3]]=1;
	
		if(ed.num[0]>full[0]||ed.num[1]>full[1]||ed.num[2]>full[2]||ed.num[3]>full[3]){
			cout<<"-1"<<endl;
			continue;
		}
		if((ed.num[0]+ed.num[1]+ed.num[2]+ed.num[3])!=9){
			cout<<"-1"<<endl;
			continue;
		}
		
		while(que.size()){
			alchol temp=que.front();
			que.pop();
			
			if(temp.num[0]==ed.num[0]&&temp.num[1]==ed.num[1]&&temp.num[2]==ed.num[2]&&temp.num[3]==ed.num[3]){
				cout<<temp.step<<endl;
				break;
			}
			int i,j;
			alchol temp1;
			for(i=0;i<4;++i){
				for(j=0;j<4;++j){
					temp1=temp;
					if(pour(temp1,i,j)){
						que.push(temp1);
					}
				}
			}
		}
	}
	return 0;
} 
