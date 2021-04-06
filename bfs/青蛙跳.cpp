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

		int pos=s.find('*');//记录s中*的位置 
		int dis=mp[s];//记录状态s的步数 
		for(int i=0;i<6;++i){
			int nx=pos+dir[i];
			if(nx<0||nx>=n){//如果越界就跳过下面 
				continue;
			}
			swap(s[pos],s[nx]);
			if(!mp.count(s)){//如果交换过*位置的状态未出现过，就入队 
				mp[s]=dis+1;
				if(s==ed){
					return mp[s];
				}
				que.push(s);
			} 
			swap(s[pos],s[nx]);//返回原来的状态 
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

