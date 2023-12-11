#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
int num[maxn];
int p[maxn];
int n,k;
void solve()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>p[i];
    sort(p+1,p+1+n);




    int ans=0;
    p[n+1]=p[n]+k+k;
    for(int i=1;i<=n;i++)
    {
        num[i]++;
        if(p[i]==p[i+1])num[i+1]+=num[i];
        else if(p[i+1]-p[i]>k)ans+=num[i];
    }


    cout<<ans<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    solve();
    return 0;
}
/*

*/

作者：十月三日
链接：https://www.acwing.com/activity/content/code/content/3625410/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。