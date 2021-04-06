#include<iostream>
#include<queue>
#include<string.h>
#include<stack>
#include<algorithm>
using namespace std;
/*enum{
	D,L,R,U
};*/
char map[501][501];
int dir[501][501],vis[501][501];
int dx[4]={1,0,0,-1},dy[4]={0,-1,1,0};
char str[5]={"DLRU"};
struct Point{
	int x;
	int y;
	int bu;
};
void bfs(int n,int m){
	queue<Point>que;
	Point p;
	p.x=1;
	p.y=1;
	p.bu=0;
	que.push(p);
	vis[1][1]=1;
	dir[1][1]=-1;

	while(que.size()){
		Point q=que.front();
		que.pop();

		if(q.x==n&&q.y==m){
			cout<<q.bu<<endl;
			return ;
		}
		for(int i=0;i<4;++i){
			int nx=q.x+dx[i],ny=q.y+dy[i];
			if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&dir[nx][ny]<0&&vis[nx][ny]==0&&map[nx][ny]=='0'){
				Point w;
				w.x=nx;
				w.y=ny;
				w.bu=q.bu+1;
				dir[nx][ny]=i;
				vis[nx][ny]=1;
				que.push(w);
			}
		}
	}
}
void path(int x,int y){
	if(x==1&&y==1) return ;
	path(x-dx[dir[x][y]],y-dy[dir[x][y]]);
	cout<<str[dir[x][y]];
}
/*void print(int n,int m){
	int px=n,py=m;
	stack<char>mys;
	while(dir[px][py]!=5){
		if(dir[px][py]==0) {
			mys.push('D');
			px--;
		}
		else if(dir[px][py]==1) {
			mys.push('L');
			py++;
		}
		else if(dir[px][py]==2) {
			mys.push('R');
			py--;
		}
		else if(dir[px][py]==3) {
			mys.push('U');
			px++;
		}
	}
	while(!mys.empty()){
		cout<<mys.top();
		mys.pop();
	}
}*/
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	getchar();
	for(int i=1;i<=n;++i){
		for(int j=1;i<=m;++j){
			scanf("%c",&map[i][j]);
		}
		getchar();
    }

	cout<<n<<m<<endl;
	for(int i=1;i<=n;++i){
		for(int j=1;i<=m;++j){
                cout<<map[i][j];
		}
		cout<<endl;
    }
	/*memset(dir,-1,sizeof(dir));
	dir[0][0]=5;*/
	bfs(n,m);
	//print(n,m);
	path(n,m);
	return 0;
}

