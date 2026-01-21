#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int n;
int x_1,y_1,x_2,y_2;
int ans = 0;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int visited[100][100] = {0};
vector<string> mp(100);
struct Node{
	int x,y;
	int step;
};
void BFS(){
	if(
	    x_1 == x_2&&
	    y_1 == y_2
	){
		ans = 0;
		return;
	}
	Node staNode = {x_1,y_1,0};
	queue<Node> q;
	q.push(staNode);
	while(!q.empty()){
		Node t = q.front();
		q.pop();
		if(
		    t.x == x_2&&
			t.y == y_2
		){
			ans = t.step;
		}
		for(int i=0;i<4;i++){
			int nx = t.x +dx[i];
			int ny = t.y +dy[i];
			if(
			    nx>=0&&nx<n&&
			    ny>=0&&ny<n&&
			    !visited[nx][ny]&&
				mp[nx][ny] == '0'
			){
				cout<<"访问坐标( "<<nx<<" , "<<ny<<" )"<<endl;
				visited[nx][ny]=true;
				Node tmp = {nx,ny,t.step+1};
				q.push(tmp);
			}
		}
	}
}
int main(){
	//输入
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>mp[i];
	}
	cin>>x_1>>y_1>>x_2>>y_2;
	x_1--;
	y_1--;
	x_2--;
	y_2--;
	//BFS
	BFS();
	cout<<ans;
	return 0;
}
