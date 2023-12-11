#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	int T;
	cin>>T;
	while(T--)
	{
		vector<int>x,y;
		string a,b;
		int n;
		cin>>n>>a>>b;
		if(a[0]!=b[0]||a.back()!=b.back()){
			cout<<-1<<endl;
			continue;
		}
		char cha=a[0],chb=b[0];
		int lena=1,lenb=1;
		for(int i=0;i<a.size();i++)
		{
			if(cha!=a[i])
			{
				x.push_back(lena);
				cha=a[i];
				lena=1;
			}
			else lena++;
			if(chb!=b[i])
			{
				y.push_back(lenb);
				chb=b[i];
				lenb=1;
			}
			else lenb++;
		}
		x.push_back(lena);x.push_back(0);
		y.push_back(lenb);y.push_back(0);


		if(x.size()!=y.size()){
			cout<<"-1"<<endl;
			continue;
		}
		ll res=0;
		int k=x.size();
		for(int i=0;i<k;i++)
		{
			ll len=x[i]-y[i];
			res+=abs(len);
			x[i+1]+=len;
		}
		cout<<res<<endl;

	}
	return 0;
}