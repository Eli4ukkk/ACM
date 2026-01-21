#include<iostream>
#include<queue>
using namespace std;
int n;
int map[30][30]={0};
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
bool visit[30][30]={0};	// 全局标记 避免二重循环多次访问一块不能作画的区域
struct Node{
	int x,y; // 坐标
};
void BFS(int x,int y){
	bool visited[30][30]={0};//记录访问
	int f=1; // 用来标记这个联通的区域是否能够作画 1可以 0不行
	if(
	   (x==0||x==n-1||y==0||y==n-1)&&
	   map[x][y]==0
	   ){
		f=0; //如果这块区域可以到达边界且边界为0 就是不能作画 f 标记为 0
	}
	visit[x][y]=true; // 全局标记 避免二重循环多次访问一块不能作画的区域
	visited[x][y]=true; // 标记
	queue<Node> q;
	Node t = {x,y}; // BFS的头
	q.push(t);
	while(!q.empty()){
		Node newNode = q.front();
		q.pop();
		int nx,ny;
		for(int i=0;i<4;i++){
			nx = newNode.x+dx[i];
			ny = newNode.y+dy[i];
			if(
			   (nx==0||nx==n-1||ny==0||ny==n-1)&&
			   map[nx][ny]==0
			){
				f=0; //如果这块区域可以到达边界且边界为0 就是不能作画 f 标记为 0
			}
			//不管是 f = 0 / 1 都先把这联通的区域先搜索了
			if(
			   nx>=0&&nx<n&&
			   ny>=0&&ny<n&&
			   !visited[nx][ny]&&
			   !visit[nx][ny]&&
			   map[nx][ny]==0
			){	
				visit[nx][ny]=true; // 全局标记 避免二重循环多次访问一块不能作画的区域
				visited[nx][ny]=true;
				Node tmp = {nx,ny};
				q.push(tmp);
			}
		}
	}
	if(f==1){ // 可以作画
		bool visited[30][30]={0};//记录访问
		visited[x][y]=true; // 标记
		map[x][y]=2; // 作画
		queue<Node> q;
		Node t = {x,y}; // BFS的头
		q.push(t);
		while(!q.empty()){
			Node newNode = q.front();
			q.pop();
			int nx,ny;
			for(int i=0;i<4;i++){
				nx = newNode.x+dx[i];
				ny = newNode.y+dy[i];
				//不管是 f = 0 / 1 都先把这联通的区域先搜索了
				if(
				   nx>=1&&nx<n-1&&
				   ny>=1&&ny<n-1&&
				   !visited[nx][ny]&&
				   map[nx][ny]==0
				){
					map[nx][ny]=2; // 作画
					visited[nx][ny]=true;
					Node tmp = {nx,ny};
					q.push(tmp);
				}
			}
		}
	}
	else{ // 不可以作画
		return;
	}
}
int main(){
	cin>>n;
	//输入
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>map[i][j];
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(!visit[i][j]&&map[i][j]==0){
				BFS(i,j);
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<map[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
