#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=1e6;
int a[maxn],c[maxn],b[maxn],d[maxn];
int n;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];c[i]=a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>b[i];d[i]=b[i];
	}
	sort(c+1,c+1+n);
	sort(d+1,d+1+n);
	vector<pair<int,int> >q;
	for(int i=1;i<=n;i++){
		if(a[i]!=c[i]){
			for(int j=i+1;j<=n;j++)
			{
				if(a[j]==c[i]){
					swap(a[j],a[i]);
					swap(b[j],b[i]);
					q.push_back({j,i});
					break;
				}
			}
		}
		if(b[i]!=d[i]){
			for(int j=i+1;j<=n;j++)
			{
				if(b[j]==d[i]){
					swap(a[j],a[i]);swap(b[j],b[i]);
					q.push_back({j,i});
					break;
				}
			}
		}
		if(a[i]!=c[i]){
			cout<<"-1"<<endl;
			return;
		}
		if(b[i]!=d[i]){
			cout<<"-1"<<endl;
			return ;
		}
	}
	cout<<q.size()<<endl;
	for(int i=0;i<q.size();i++)
		cout<<q[i].first<<" "<<q[i].second<<"\n";
}
int main(){
    int __;
    cin>>__;
//    __=1;
    while(__--)solve();
    return 0;
}