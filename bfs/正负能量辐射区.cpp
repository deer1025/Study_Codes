#include<iostream>
#include<queue>
using namespace std;
char map[98][98];
int vis[98][98];
int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
struct Point{
	int x;
	int y;
	int bu;
};
int n;
int bfs(int i,int j){
	queue<Point>que;
	Point p;
	p.x=i;
	p.y=j;
	p.bu=0;
	que.push(p);
	vis[i][j]=1;
	
	while(que.size()){
		Point q=que.front();
		que.pop();
		
		if(map[q.x][q.y]=='B'){
			return q.bu;
		}
		for(int i=0;i<4;++i){
			int nx=q.x+dir[i][0],ny=q.y+dir[i][1];
			if(nx>=0&&nx<n&&ny>=0&&ny<n&&vis[nx][ny]==0){
				if((map[q.x][q.y]=='A'&&map[nx][ny]=='+')||(map[q.x][q.y]=='+'&&(map[nx][ny]=='-'||map[nx][ny]=='B'))||(map[q.x][q.y]=='-'&&(map[nx][ny]=='+'||map[nx][ny]=='B'))){
					Point w;
					w.x=nx;
					w.y=ny;
					w.bu=q.bu+1;
					vis[nx][ny]=1;
					que.push(w);
				}
			}	
		}
	}
	return -1;
}
int main(){
	cin>>n;
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			cin>>map[i][j];
		}
	}
	int i,j;
	for(i=0;i<n;++i){
		for(j=0;j<n;++j){
			if(map[i][j]=='A'){
				cout<<bfs(i,j)<<endl;
				return 0;
			}
		}
	}	
}
