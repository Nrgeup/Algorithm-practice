#include<iostream>
#include<cstdlib>		/* rand,srand,calloc,free,malloc,realloc,abs,div,labs,ldiv, */
#include<cstdio>		/*scanf,printf*/
#include<cstring>		/*字符串函数memset()*/
#include<cmath>			/**/
#include<iomanip>
#include <vector>
#include<string.h>
#include<string>
#include<algorithm>
#include<map>
#include<stack>

using namespace std;

int n,m;

struct node
{
	int pos;
	int sort_num;
};

char STR[101][51];

node DATA[101];

int cal_sort(int k)
{
	int ans=0;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(STR[k][i]>STR[k][j])
				ans++;
		}
	}
	return ans;
}

bool cmp(node a,node b)
{
	return a.sort_num<b.sort_num;
}

int main()
{
	int N=0,x;
	cin>>n>>m;
	memset(STR,0,sizeof(STR));
	memset(DATA,0,sizeof(DATA));
	for(int i=0;i<m;i++)
	{
		cin>>STR[i];
		DATA[i].pos=i;
		DATA[i].sort_num=cal_sort(i);
	}

	sort(DATA,DATA+m,cmp);


	for(int i=0;i<m;i++)
	{
		cout<<STR[DATA[i].pos]<<endl;
	}
	return 0;
}
