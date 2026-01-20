#include<iostream>
#include<queue>
using namespace std;
int h,w;
int ans=0;
int a[4]={1,-1,1,-1};
char map[20][20];
struct Node{
	int x,y;
	int step;
};
void BFS(int x,int y){
	bool visited[20][20]={0};
	visited[x][y] = 1;
	queue<Node> q;
	Node t;
	t.x=x;
	t.y=y;
	t.step=0;
	q.push(t);
	while(!q.empty()){
		Node tmp = q.front();
		q.pop();
		for(int i=0;i<4;i++){
			if(
			   (i==0||i==1)&&
			   (tmp.x+a[i]>=0&&tmp.x+a[i]<h)&&
			   (map[tmp.x+a[i]][tmp.y]=='.')&&
			   (visited[tmp.x+a[i]][tmp.y]==0)
			   ){
				visited[tmp.x+a[i]][tmp.y]=1;
				Node newNode={tmp.x+a[i],tmp.y,tmp.step+1}; 
				q.push(newNode);
			}
			else if(
					(i==2||i==3)&&
					(tmp.y+a[i]>=0&&tmp.y+a[i]<w)&&
					(map[tmp.x][tmp.y+a[i]]=='.')&&
					(visited[tmp.x][tmp.y+a[i]]==0)
					){
				visited[tmp.x][tmp.y+a[i]]=1;
				Node newNode={tmp.x,tmp.y+a[i],tmp.step+1}; 
				q.push(newNode);
			}
			ans = max(ans,tmp.step);
		}
	};
}
int main(){
	cin>>h>>w;
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			cin>>map[i][j];
		}
	}
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			if(map[i][j]=='#')continue;
			BFS(i,j);
		}
	}
	cout<<ans;
	return 0;
}
