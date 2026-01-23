#include<iostream>
using namespace std;
int ans=-1,c=0;
int el[201]={0};
int n,f,t; // from to
void dfs(int now,int count){
	if(now==t){
		if(ans==-1) ans = c;
		else{
			ans = min(ans,c);
		}
		return;
	}
	//上
	if(n>=now+el[now]){
		c++;
		dfs(now+el[now],c);
		//回溯
		c--;
	}
	//下
	if(0<now-el[now]){
		c++;
		dfs(now-el[now],c);
		//回溯
		c--;
	}
}
int main(){
	//输入
	cin>>n>>f>>t;
	for(int i=1;i<=n;i++){
		cin>>el[i]; // 第i层的数字k
	}
	//
	dfs(f,0);
	cout<<ans;
	return 0;
}

