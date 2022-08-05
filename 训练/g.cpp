#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6;
struct node{
	int l,r,val;
};
int a[maxn];
int n,m;
void pushup(int rt)
{
	
}

int main()
{
	cin>>n>>m;
	set<long long >s;
    map<long long,int>mp;
	for(int i=1;i<=n;i++)
    {
        cin>>a[i],s.insert(a[i]);
        mp[a[i]]++;
    }
		
//     for(auto j:s)
//             cout<<j<<" ";
//         cout<<endl;
    
	//cout<<*s.begin()<<" "<<*s.rbegin()<<endl; 
	while(m--)
	{
		long long x,y;
		cin>>x>>y;
		auto t=(s.upper_bound(x-1));
        t--;
        int fl=*t;
// 		cout<<fl<<endl;
		if(fl>=x)continue;
		if(mp[fl])
		{
//             cout<<"Yes"<<endl;
			 mp[fl]--;
             mp[fl+y]++;
            if(mp[fl]==0)s.erase(fl);
            s.insert(fl+y);
		}
// 		for(auto j:s)
//             cout<<j<<" ";
//         cout<<endl;
	}
	cout<<*s.rbegin()<<endl;
}
/*
5 3 7 2 11

5 3
5 3 3 2 1
4 4
2 10
3 10

*/