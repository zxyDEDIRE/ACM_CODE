#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
int n=1000,cnt=0;
struct node{
	int l,r;
}t[maxn];
void build(int rt,int l,int r)
{
	cnt++;
	t[rt].l=l;
	t[rt].r=r;
	if(l==r)return ;
	int mid=(l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
}
void solve()
{
	build(1,1,n);
	cout<<cnt<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    solve();
    return 0;
}