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
int  pour(alchol &t,int i,int j){//��ʾ��״̬t�ѵ�i��ƿ�ӵ����j��ƿ�� 
	if(i==j) return 0;
	if(!t.num[i]) return 0;//iƿ�ѿ� 
	if(t.num[j]==full[j]) return 0;//jƿ����
	//ע������if�������num[i]��num[j]����ֵ�ĵط����ܽ���˳�� ��else���Ҳһ�� 
	if(t.num[i]+t.num[j]>full[j]){
		t.num[i]=t.num[i]-(full[j]-t.num[j]);
		t.num[j]=full[j];
	} 
	else{
		t.num[j]=t.num[i]+t.num[j];
		t.num[i]=0;
	}
	if(vis[t.num[0]][t.num[1]][t.num[2]][t.num[3]]) return 0;//��ʾ��״̬�Ѿ����ʹ� 
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
