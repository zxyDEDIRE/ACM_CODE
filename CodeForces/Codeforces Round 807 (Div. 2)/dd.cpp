#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define int long long
int n,c,q;
int a[200005],di[200005];
P t[50];
string s;
void solve()
{
    cin>>n>>c>>q>>s;
    s=" "+s;
    int ti=0;
    di[0]=n;
    for(int i=1;i<=c;i++){
        cin>>t[i].first>>t[i].second;
        di[i]=di[i-1]+t[i].second-t[i].first+1;
    }
    // puts("&&&");
    // for(int i=0;i<=c;i++)cout<<di[i]<<" ";
    // puts("");
    for(int i=1;i<=q;i++){
        int x;
        cin>>x;
        while(1){
            if(x<=n)break;
            int dis=lower_bound(di+1,di+c+1,x)-di;
            x-=di[dis]-t[dis].second;
            //cout<<"--"<<dis<<" "<<x<<" "<<tt<<endl;
        }
        cout<<s[x]<<endl;
    }
}
signed main()
{
	int __=1;
	cin >> __;
	while (__--)
		solve();
}