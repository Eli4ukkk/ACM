#include<iostream>
using namespace std;
int ans=0;
int n,m,bar;
int sx,sy,fx,fy;
int mp[5][5]={0};
bool visited[5][5]={0};
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
void DFS(int x,int y){
	cout<<"访问坐标 ( "<<x<<" , "<<y<<" )"<<endl;
	if(
		x==fx&&
		y==fy
	){
		ans++;
		return;
	}
	else{
		for(int i=0;i<4;i++){
			int nx = x+dx[i];
			int ny = y+dy[i];
			if(
				!visited[nx][ny]&&
				nx>=0&&nx<n&&
				ny>=0&&ny<m&&
				!mp[nx][ny]
			){
				visited[nx][ny]=true;
				DFS(nx,ny);
				visited[nx][ny]=false;
			}
		}
	}
}
int main(){
	cin>>n>>m>>bar;
	cin>>sx>>sy>>fx>>fy;
	sx--;
	sy--;
	fx--;
	fy--;
	for(int i=0;i<bar;i++){
		int x,y;
		cin>>x>>y;
		x--;
		y--;
		mp[x][y]=1; // 障碍物
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<<mp[i][j]<<" ";
		}
		cout<<endl;
	}
	//
	visited[sx][sy]=true;
	DFS(sx,sy);
	cout<<ans;
	return 0;
}
