#include<bits/stdc++.h>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	string s;
	cin>>s;
	// s=s+s;
	// s=s+s;
	int cnt_1=0,cnt_2=0;
	for(auto i:s)
	{
		if(i=='D')cnt_2++;
		if(i=='T')cnt_1++;
	}
	if(cnt_1>cnt_2)cout<<"T1"<<endl;
	else cout<<"DRX"<<endl;

	return 0;
}