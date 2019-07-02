#include<bits/stdc++.h>
using namespace std;
int flag;
void dfs(vector<int>v[],bool vis[],int f)
{
	stack<int>s;
	s.push(f);
	vis[f]=true;
	while(!s.empty())
	{
		int x=s.top();
		s.pop();
		for(int i=0;i<v[x].size();i++)
		{
			if(vis[v[x][i]]==false)
			{
				s.push(v[x][i]);
				vis[v[x][i]]=true;
			}
		}
	}
}
int main()
{
	int n,m,x,y;
	flag=0;
	cin>>n>>m;
	vector<int>v[n+1];
	bool vis[n+1];
	memset(vis,false,sizeof(vis));
	for(int i=0;i<m;i++)
	{
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	if(m==n-1)  //checking for the number of edges required to form a tree
	{
	dfs(v,vis,1);
	for(int i=1;i<=n;i++)
	{
		if(vis[i]==false)
		{
			cout<<"NO";
			flag=1;
			break;
		}
	}
	if(flag==0)
	cout<<"YES"<<endl;
    }
    else
    cout<<"NO"<<endl;
}
