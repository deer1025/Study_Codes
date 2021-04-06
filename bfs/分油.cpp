#include<iostream>
#include<cstdio>
using namespace std;
int full[3],orign[3],target;//各个容器的容量，开始的状态，和要求的目标油量 
typedef struct{
	int num[3];
	int step;//到达目前状态共经历了多少步 
	int fa;//记录是从哪个容器状态演变而来 
}oil;
int vis[100][100];
oil q[100];
void prin(int a){
	if(q[a].fa!=a){
		prin(q[a].fa);
	}
	printf("%d,%d,%d\n",q[a].num[0],q[a].num[1],q[a].num[2]);//输出各个状态 
}
void bfs(){
	int r=1,f=0;//r记录队列中有多少个容器状态，f记录已经有多少个容器状态出栈进行探索下一个状态 
	oil st,temp;
	st.num[0]=orign[0];
	st.num[1]=orign[1];
	st.num[2]=orign[2];
	st.step=0;
	st.fa=0;
	q[0]=st;
	
	while(r>f){
		st=q[f];
		
		//结束边界 
		if(st.num[0]==target||st.num[1]==target||st.num[2]==target){
			cout<<"共经历 "<<st.step<<"步"<<endl;
			prin(f);//使队列容器状态从开始往后输出 
			return ;
		}	
		
		//把第i个瓶子放入第j个瓶子中 
		for(int i=0;i<3;++i){
			for(int j=0;j<3;++j){
				if(i==j) continue;
				//
				int x=st.num[i]<=full[j]-st.num[j]?st.num[i]:(full[j]-st.num[j]);
				temp=st;
				temp.num[i]-=x;
				temp.num[j]+=x;
				temp.step++;
				temp.fa=f;
				//如果此状态未经历过则入栈 
				if(vis[temp.num[1]][temp.num[2]]==0){
					vis[temp.num[1]][temp.num[2]]=1;
					q[r++]=temp;
				}
			}
		}
		f++;
	}
	cout<<"不可能"<<endl;
	return ;
} 
int main(){
	scanf("%d,%d,%d,%d,%d,%d,%d",&full[0],&full[1],&full[2],&orign[0],&orign[1],&orign[2],&target);
	bfs();
	return 0;
}
