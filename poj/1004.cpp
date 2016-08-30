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


int main()
{
	
	double sum=0,temp;
	for(int i=0;i<12;i++)
	{
		cin>>temp;
		sum+=temp;
	}

	cout<<'$'<<setiosflags(ios::fixed)<<setprecision(2)<<sum/12<<endl;

	return 0;
}

