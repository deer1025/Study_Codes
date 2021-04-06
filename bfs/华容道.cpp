#include<iostream>
#include<cstdio>
#include<map>
#include<queue>
#include<cstring>
using namespace std;
string st="";
map<string,int>mp;
int dir[4]={-1,1,-4,4};
int orgposA,orgposB;
int bfs(){
	queue<string>que;
	que.push(st);
	mp[st]=0;

	while(que.size()){
		string temp=que.front();
		que.pop();

		int pos=temp.find(' ');
		int dis=mp[temp];
		for(int i=0;i<4;++i){
            int nx=pos+dir[i];
            if((nx>=0&&nx<=2)||(nx>=4&&nx<=6)){
                swap(temp[pos],temp[nx]);
                if(mp.count(temp)==0){
                    mp[temp]=dis+1;
                    //����״̬���жϷ������� 
                    if(temp.find('A')==orgposB&&temp.find('B')==orgposA){
                        return mp[temp];
                    }
                    que.push(temp);
                }
                swap(temp[pos],temp[nx]);//��Ҫ����ԭ����״̬ 
            }
		}
	}
	return -1;
}
int main(){
	string map;
    getline(cin,map);
    st+=map;
    st+='#';
/*���ڣ����ĸ�λ�ã��±�Ϊ3��-1��Ϊ2������2������3������3*2����С�
�����á�#���Լ�(nx>=0&&nx<=2)||(nx>=4&&nx<=6)ֱ��ʹ���ĸ�λ��ʧЧ��
  ���ĸ��ַ��±�Ϊ4��ȥ4�պ�Ϊ����������Ԫ��*/ 
    getline(cin,map);
    st+=map;

	//��¼��ʼAB��λ�� 
	orgposA=st.find('A');
	orgposB=st.find('B');
	cout<<bfs()<<endl;
	return 0;
}

