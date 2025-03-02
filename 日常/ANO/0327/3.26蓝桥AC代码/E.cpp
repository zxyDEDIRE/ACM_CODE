#include<bits/stdc++.h>
using namespace std;
#define ll long long
set<int>s;
int main()
{
	int n,k,x;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>x;
		s.insert(x);
	}
	int j=0,flag=1;
	set<int>::iterator it;
	for (it = s.begin(); it != s.end(); it++)
	{
		j++;
		if(j==k)printf("%d\n", *it),flag=0;
	}
	if(flag)cout<<"NO RESULT"<<endl;
}