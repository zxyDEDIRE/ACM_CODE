#include<bits/stdc++.h>
using namespace std;

int main()
{
	int ans=0;
	for(int i=0;i<(1<<4);i++)
	{
		string s="";
		for(int j=0;j<4;j++)
		{
			if((i>>j)&1) s+='1';
			else s+='0';
		}
		string c=s;
		while(s.size()>1)
		{
			string s1="";
			for(int j=0;j<s.size()-1;j++)
			{
				s1+=(s[j]-'0')^(s[j+1]);
			}
			s=s1;
			if(s.size()==1) break;
		}
		if(s=="1") {
			cout<<c<<'\n';
			ans++;
		}
	}
	cout<<ans<<'\n';
	return 0;
}
/*
1
?????
1010?1?0
10100110
*/
