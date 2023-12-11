#include<bits/stdc++.h>
using namespace std;


struct node{
	int x,a,d,t;
};
int n,m=0,free=0;
int main()
{
	cin>>n;
	vector<node> v(n+1);
	for(int i=1;i<=n;i++)
	{
		cin>>x>>a>>d>>t;
		v[i]={x,a,d,t};
	}
	sort(v.begin()+1,v.begin()+n+1,[](node &a,node &b){
		return a.a<b.a;
	});
	
	priority_queue<int> q;
	for(int i=1;i<=n;i++)
	{
		auto [x,a,d,t]=v[i];
		while(q.size()&&q.front()<a)
		{
			q.pop();
			free++;
		}
		
		if(t==0)//社恐，加桌子 
		{
			if(free)
				free--;
			else
				m++;
			q.push()
		}
		else//社牛，拼桌子 / 加桌子 
		{
			
		}
	}
}
