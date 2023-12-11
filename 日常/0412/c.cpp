#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=1e6;
ll p[10];
int n;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);


	int n;
	cin>>n;
	while(n--)
	{
		
		string str;
		cin>>str;
		
		cout<<"He/She is from ";
		int t=(str[0]-'0')*10+str[1]-'0';
		switch(t)
		{
			case 33:cout<<"Zhejiang";break;
			case 82:cout<<"Macao";break;
			case 11:cout<<"Beijing";break;
			case 54:cout<<"Tibei";break;
			case 71:cout<<"Taiwan";break;
			case 21:cout<<"Liaoning";break;
			case 81:cout<<"Hong Kong";break;
			case 31:cout<<"Shanghai";break;
		}
		cout<<",and his/her birthday is on ";
		cout<<str[10]<<str[11]<<",";
		cout<<str[12]<<str[13]<<",";
		cout<<str[6]<<str[7]<<str[8]<<str[9]<<" ";
		cout<<"based on the table.";
		cout<<endl;
	}
	
}
/*
6 4 2 2
He/She is from Zhejiang,and his/her birthday is on 10,12,1989 based on the table.
He/She is from Zhejiang,and his/her birthday is on 10,12,1989 based on the table.
He/She is from Zhejiang,and his/her birthday is on 10,12,1989 based on the table.
1
310000198910120036
*/