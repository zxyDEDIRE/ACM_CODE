#include<bits/stdc++.h>
using namespace std;
queue<int>q;
int n,m;
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		q.push(i);
	int j=0;
	int it;
	while(!q.empty())
	{
		++j;
		int k=q.front();q.pop();
		if(j==m){
			j=0;
			it=k;
		}
		else q.push(k);
	}
	cout<<it<<endl;
}