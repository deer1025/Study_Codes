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
                    //结束状态的判断放在这里 
                    if(temp.find('A')==orgposB&&temp.find('B')==orgposA){
                        return mp[temp];
                    }
                    que.push(temp);
                }
                swap(temp[pos],temp[nx]);//还要返回原来的状态 
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
/*由于（第四个位置）下标为3，-1后为2，但是2并不与3相邻在3*2表格中。
故利用‘#’以及(nx>=0&&nx<=2)||(nx>=4&&nx<=6)直接使第四个位置失效。
  第四个字符下表为4减去4刚好为其上面相邻元素*/ 
    getline(cin,map);
    st+=map;

	//记录初始AB的位置 
	orgposA=st.find('A');
	orgposB=st.find('B');
	cout<<bfs()<<endl;
	return 0;
}

