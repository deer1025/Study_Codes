#include<iostream>
#include<string>
#include<queue>
#include<map>
using namespace std;
map<string,int>mp,dir,vis;
int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};
void swap(char &m,char &n){
	char t=m;
	m=n;
	n=t;
}
string alter(string cur,int i){
	int pos;
	for(int i=0;i<cur.length();++i){
		if(cur[i]=='.'){
			pos=i;
			break;
		}
	}
	
	int nx=pos/3+dx[i],ny=pos%3+dy[i];
	if(nx>=0&&nx<3&&ny>=0&&ny<3){
		swap(cur[pos],cur[nx*3+ny]);
		return cur;
	}
	return " ";
}
int bfs(string s,string e){
	queue<string>que;
	que.push(s);
	dir[s]=1;
	mp[s]=0;
	vis[s]=1;
	que.push(e);
	dir[e]=2;
	mp[e]=0;
	vis[e]=1;
	
	while(que.size()){
		string p=que.front();
		que.pop();
		
		for(int i=0;i<4;++i){
			string g=alter(p,i);
			if(dir[g]+dir[p]==3){
				return mp[g]+mp[p]+1;
			}
			if(g!=" "&&vis[g]==0){
				que.push(g);
				vis[g]=1;
				mp[g]=mp[p]+1;
				dir[g]=dir[p];
			}
		}
	}
	return -1;
}
int main(){
	string s,e;
	cin>>s>>e;
	cout<<bfs(s,e);
	return 0;
}

