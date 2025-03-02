#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5;
struct node
{  
    int x,y;  
    bool operator <(const node &a)const //排序并且去重复  
    {  
               return a.x >x;
    }  
};  
int main()
{
	set<node>s;
	s.insert(node{1,1});
	s.insert(node{2,3});
	set<node>::iterator it;
	node x=*s.rbegin();
	int ss=x.x;
	cout<<x.x<<" "<<x.y<<endl;
}