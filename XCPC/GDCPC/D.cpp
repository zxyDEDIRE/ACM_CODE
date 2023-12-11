
#include<bits/stdc++.h>
using namespace std;
long long p[1000000];
long long n,s,t;
int main()
{
	cin>>n;
    if(n==1||n==2){
        cout<<1<<" "<<1<<endl;
        return 0;
    }
	p[1]=s=1;
	p[2]=t=2;
	for(int i=3;i;i++)
	{
		p[i]=p[i-1]+p[i-2];
        if(p[i]<=n)
        {
            s=p[i-1],t=p[i];
        }
		if(p[i]>=n)
			break;
		
	}
	cout<<s<<" "<<t;
}
