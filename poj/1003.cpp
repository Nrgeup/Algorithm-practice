#include<iostream>
#include<cstdlib>		/* rand,srand,calloc,free,malloc,realloc,abs,div,labs,ldiv, */
#include<cstdio>		/*scanf,printf*/
#include<cstring>		/*字符串函数memset()*/
#include<cmath>		/**/
#include<iomanip>
#include<string>
#include <vector>
#include<algorithm>
#include<string.h>

using namespace std;

double num[1000];



double ANS;

int main()
{
	memset(num,0,sizeof(num));
	num[1]=0.5;
	for(int i=2;i<1000;i++)
	{
		num[i]=num[i-1]+1/double(i+1);
	}

	int ans;
	while(cin>>ANS&&(abs(ANS-0)>=0.0001))
	{
		for(ans=1;ans<1000;ans++)
		{
			if(ANS<=num[ans])
			{
				break;
			}
		}

		cout<<ans<<" card(s)\n";
	}
	return 0;
}
