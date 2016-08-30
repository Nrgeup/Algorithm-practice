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


int mmmap[26] = {'2', '2', '2','3', '3', '3', '4', '4', '4', 
                '5', '5', '5', '6', '6', '6', '7', '7', '7', 
                '7', '8', '8', '8', '9', '9', '9', '9'};//按键映射表


struct PHONE
{
	char con[9];
};
PHONE phone[100000];

int n;

bool cmp(PHONE a,PHONE b)
{
	for(int i=0;i<9;i++)
	{
		if(a.con[i]!=b.con[i])
			return a.con[i]<b.con[i];
	}
	return false;
}

int main()
{
	char str[80];
	int phone_i,phone_j;
	memset(str,0,sizeof(str));

	cin>>n;
	for(phone_i=0;phone_i<n;phone_i++)
	{
		cin>>str;
		phone_j=0;
		for(int j=0;str[j]!='\0';j++)
		{
			if(phone_j==3)
			{phone[phone_i].con[phone_j]='-';phone_j++;}
			if(str[j]=='-')
				continue;
			if(str[j]>='A'&&str[j]<='Z')
			{phone[phone_i].con[phone_j]=mmmap[str[j]-'A'];phone_j++;}
			else
				{phone[phone_i].con[phone_j]=str[j];phone_j++;}
		}
	}

	sort(phone, phone+n, cmp);

	int ok=0, count=1,i;
	for(i=1;i<n;i++)
	{
		if(strcmp(phone[i].con, phone[i-1].con) == 0){
			count++;
			ok=1;
		}
		else
		{
			if(count>1)
				cout<<phone[i-1].con<<' '<<count<<endl;
			count=1;
		}

	}
	if(count>1)
			cout<<phone[i-1].con<<' '<<count<<endl;
	if(!ok)
		cout<<"No duplicates.\n";
	return 0;
}
