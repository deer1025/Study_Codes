#include<iostream>
#include<cstdio>
using namespace std;
int full[3],orign[3],target;//������������������ʼ��״̬����Ҫ���Ŀ������ 
typedef struct{
	int num[3];
	int step;//����Ŀǰ״̬�������˶��ٲ� 
	int fa;//��¼�Ǵ��ĸ�����״̬�ݱ���� 
}oil;
int vis[100][100];
oil q[100];
void prin(int a){
	if(q[a].fa!=a){
		prin(q[a].fa);
	}
	printf("%d,%d,%d\n",q[a].num[0],q[a].num[1],q[a].num[2]);//�������״̬ 
}
void bfs(){
	int r=1,f=0;//r��¼�������ж��ٸ�����״̬��f��¼�Ѿ��ж��ٸ�����״̬��ջ����̽����һ��״̬ 
	oil st,temp;
	st.num[0]=orign[0];
	st.num[1]=orign[1];
	st.num[2]=orign[2];
	st.step=0;
	st.fa=0;
	q[0]=st;
	
	while(r>f){
		st=q[f];
		
		//�����߽� 
		if(st.num[0]==target||st.num[1]==target||st.num[2]==target){
			cout<<"������ "<<st.step<<"��"<<endl;
			prin(f);//ʹ��������״̬�ӿ�ʼ������� 
			return ;
		}	
		
		//�ѵ�i��ƿ�ӷ����j��ƿ���� 
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
				//�����״̬δ����������ջ 
				if(vis[temp.num[1]][temp.num[2]]==0){
					vis[temp.num[1]][temp.num[2]]=1;
					q[r++]=temp;
				}
			}
		}
		f++;
	}
	cout<<"������"<<endl;
	return ;
} 
int main(){
	scanf("%d,%d,%d,%d,%d,%d,%d",&full[0],&full[1],&full[2],&orign[0],&orign[1],&orign[2],&target);
	bfs();
	return 0;
}
