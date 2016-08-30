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



int main()
{
	int N,year;
	double X,Y,R;
	cin>>N;
	for(int i=1;i<=N;i++)
	{
		cin>>X>>Y;
		R=X*X+Y*Y;
		for(year=0;year*100/3.1415926<R;year++);
		cout<<"Property "<<i<<": This property will begin eroding in year "<<year<<".\n";
	}
	cout<<"END OF OUTPUT.\n";
	return 0;
}
