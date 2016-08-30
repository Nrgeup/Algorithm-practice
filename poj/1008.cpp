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

int n,m,allday;

string Haab_month[19]={"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"};

string Tzolkin_day[20]={"imix","ik","akbal","kan","chicchan","cimi","manik","lamat","muluk","ok","chuen","eb","ben","ix","mem","cib","caban","eznab","canac","ahau"};

int main()
{
	int SIZE;
	cin>>SIZE;
	cout<<SIZE<<endl;
	int day,year,newyear,newmonth,newday;
	string mon;
	for(int now_input=1;now_input<=SIZE;now_input++)
	{
		cin>>day;
		getchar();
		cin>>mon>>year;
		//cout<<"==========\n";
		//cout<<day<<"   "<<mon<<"    "<<year<<endl;
		allday=365*year;
		for(int i=0;i<19;i++)
		{
			if(mon==Haab_month[i])
			{allday+=day;break;}
			allday+=20;
		}

		newyear=allday/260;
		allday=allday%260;

		newday=allday%20;
		newmonth=allday%13+1;
		cout<<newmonth<<' '<<Tzolkin_day[newday]<<' '<<newyear<<endl;
	}
	return 0;
}
