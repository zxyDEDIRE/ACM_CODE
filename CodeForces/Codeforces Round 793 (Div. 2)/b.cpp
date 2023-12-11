#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
int p[maxn];
int a[maxn];
int n;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	sort(p+1,p+1+n);
	int l=1,r=n,fl=1;
	for(int i=1;i<=n;i++)
	{
		if(fl&1)a[l++]=p[i];
		else a[r--]=p[i];
		fl++;
	}
	int lena=1,lenb=1;
	for(int i=1;i<n;i++){
		if(a[i+1]>a[i])lena++;
	}
	for(int i=n-1;i>=1;i--){
		if(a[i+1]<a[i])lenb++;
	}
	cout<<min(lena,lenb)<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int __;
    cin>>__;
//    __=1;
    while(__--)solve();
    return 0;
}
/*
2 5 4 5 2 4
2 2 4 4 5 5
2 5 4 5 2 4
2 2 4 4 5 5
6
2 4 5 6 4 2
2 4 6 5 4 2
*/