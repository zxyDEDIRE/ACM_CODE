#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+100;


int a[maxn];
int n;

void qSort(int p[], int start, int last)
{
	int l = start;
	int r = last;
	if (l < r)
	{
		while (l < r)
		{
			while (p[l] <= p[start] && l < last)
				l++;//满足小于基准的条件，指针右移
			while (p[r] >= p[start] && r > start)
				r--;//满足大于基准的条件，指针左移
			if (l < r)
				swap(p[l], p[r]);//交换两个不满足条件的元素
			else
				break;
		}
		swap(p[start], p[r]);//插入基准元素
		qSort(p, start, r - 1);
		qSort(p, r + 1, last);
	}
}

signed main(){


	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];

	qSort(a,1,n);

	for(int i=1;i<=n;i++)
		cout<<a[i]<<" ";cout<<endl;


	return 0;
}