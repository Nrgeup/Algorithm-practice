#include<iostream>
#include<cstdlib>		/* rand,srand,calloc,free,malloc,realloc,abs,div,labs,ldiv, */
#include<cstdio>		/*scanf,printf*/
#include<cstring>		/*字符串函数memset()*/
#include<cmath>		/**/
#include<iomanip>
#include <vector>
#include<string.h>
#include<string>
#include<algorithm>
#include<map>
#include<stack>

using namespace std;

int p,e,i,d;

int main()
{
	int N=0,x;
	while(cin>>p>>e>>i>>d)
	{
		N++;
		if(p==-1&&e==-1&&i==-1&&d==-1)
			break;
		for(x=d+1;;x++)
		{
			if(((x-p)%23==0)&&((x-e)%28==0)&&((x-i)%33==0))
			{
				break;
			}
		}
		cout<<"Case "<<N<<": the next triple peak occurs in "<<x-d<<" days.\n";
	}
	return 0;
}
