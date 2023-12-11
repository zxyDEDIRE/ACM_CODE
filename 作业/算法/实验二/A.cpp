#include<bits/stdc++.h>
#define int long long
using ll=long long;
using namespace std;
int n,a[1000001];
void qsort(int l,int r)
{
	int mid=a[(l+r)/2];//中间数
	int i=l,j=r;
	do{
		while(a[i]<mid) i++;//查找左半部分比中间数大的数
		while(a[j]>mid) j--;//查找右半部分比中间数小的数
		if(i<=j)//如果有一组不满足排序条件（左小右大）的数
		{
			swap(a[i],a[j]);//交换
			i++;
			j--;
		}
	}while(i<=j);
	if(l<j) qsort(l,j);//递归搜索左半部分
	if(i<r) qsort(i,r);//递归搜索右半部分
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	qsort(1,n);
	for(int i=1;i<=n;i++) cout<<a[i]<<" ";
	cout<<endl;
}
signed main(){
 freopen("C:\\Users\\tob\\Desktop\\in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\ans.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	clock_t start, finish;
	start = clock();
	/*******代码*******/
	solve();
	/****************/
	finish = clock();
	 cout << "the time cost is" <<\
	  double(finish - start) / CLOCKS_PER_SEC;
 fclose(stdin);
 // fclose(stdout);
	return 0;
}