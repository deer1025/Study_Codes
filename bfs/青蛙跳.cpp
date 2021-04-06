#include<iostream>
#include<cstring>
#include<map>
#include<queue>
#include<algorithm>
using namespace std;
string st,ed;
map<string,int>mp;
int n;
int dir[6]={-3,-2,-1,1,2,3};
int bfs(){
	queue<string>que;
	que.push(st);
	mp[st]=0;

	while(que.size()){
		string s=que.front();
		que.pop();

		int pos=s.find('*');//��¼s��*��λ�� 
		int dis=mp[s];//��¼״̬s�Ĳ��� 
		for(int i=0;i<6;++i){
			int nx=pos+dir[i];
			if(nx<0||nx>=n){//���Խ����������� 
				continue;
			}
			swap(s[pos],s[nx]);
			if(!mp.count(s)){//���������*λ�õ�״̬δ���ֹ�������� 
				mp[s]=dis+1;
				if(s==ed){
					return mp[s];
				}
				que.push(s);
			} 
			swap(s[pos],s[nx]);//����ԭ����״̬ 
		}
	}
	return -1; 
}
int main(){
	cin>>st>>ed;
	n=st.size(); 
	cout<<bfs();
	return 0;
}

