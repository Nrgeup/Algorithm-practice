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
#include<queue>
#include<iomanip>
#include<cassert>


using namespace std;


int n, t, k;
int num[2000], sum[2000], digit[2000], ansdigit[5000], ansnum[5000];

//求绝对值函数，可以用math中的同名函数
//int abs(int x )
//{
//  if (x < 0) return -x;
//	return x;
//}

//循环变量i和周围元素位置映射
/*****
*0 1 2
*3   4
*5 6 7
******/
inline int Map(int c, int now)
{
  switch (c)
  {
    case 0: return now - t - 1;
    case 1: return now - t;
    case 2: return now - t + 1;
    case 3: return now - 1;
    case 4: return now + 1;
    case 5: return now + t - 1;
    case 6: return now + t;
    case 7: return now + t + 1;
  }
  assert(false);
  return -1;
}

//算出位置y的元素值,这里forward很巧妙，为0向前找，为1向后找
int number(int c, int y, bool forward)
{
  int i;
  if (forward)
  {
    for (i = c; i <= n; ++i)
      if (sum[i] >= y) break;
    return i;
  }
  else
  {
    for (i = c; i > 0; --i)
      if (sum[i] < y) break;
    return i+1;
  }
}

//判断边界情况 
bool ok(int now, int i)
{
  if (now < t && (i == 1 || i == 0 || i == 2)) return false;//起始行的前一行
  if (now > sum[n] - t && (i == 6 || i == 5 || i == 7)) return false;//结束行的后一行
  if (now % t == 1 && (i == 0 || i == 3 || i == 5)) return false;//左边一行的左边
  if (now % t == 0 && (i == 2 || i == 4 || i == 7)) return false;//右边一行的右边
  return true;
}

//比较与周围8个元素之差的绝对值大小
int get(int x, int now)
{
  int i, max = 0, m;
  for (i = 0; i < 8; ++i)
  {
    m = Map(i, now);
    if (ok(now, i) && m > 0 && m <= sum[n])
    {
      m = number(x, m, i / 4);
      if (max < abs(digit[x] - digit[m])) max = abs(digit[x] - digit[m]);
    }
  }
  return max;
}
//减少重复计算 
int late(int x, int now, int r)
{
    int p;
    if (r <= now) return 1;
    if (now % t != 1)
    {
        if (digit[number(x, now - 1, 0)] != digit[x]) return 1;
        if (now > t)
        {
            p = number(x, now - t - 1, 0);
            if ((sum[p] - 1) / t < (now - 1) / t)
            {
              if (sum[p] <= now - t + 1) return 1;
              if (r > sum[p] - 1 + t) r = sum[p] - 1 + t;
            }
        }
        if (now <= sum[n] - t)
        {
            p = number(x, now + t - 1, 1);
            if ((sum[p] - 1) / t == (now - 1) / t + 1)
            {
              if (sum[p] <= now + t + 1) return 1;
              if (r > sum[p] - 1 - t) r = sum[p] - 1 - t;
            }
        }
        return r - now + 1;
    }
    else
    {
        if (now > t)
        {
            p = number(x, now - t, 0);
            if ((sum[p] - 1) / t < (now - 1) / t)
            {
              if (sum[p] <= now - t + 1) return 1;
              if (r > sum[p] - 1 + t) r = sum[p] - 1 + t;
            }
        }
        if (now <= sum[n] - t)
        {
            p = number(x, now + t, 1);
            if ((sum[p] - 1) / t == (now - 1) / t + 1)
            {
              if (sum[p] <= now + t + 1) return 1;
              if (r > sum[p] - 1 - t) r = sum[p] - 1 - t;
            }
        }
        return r - now + 1;
    }
}
//程序的主体部分，计算start和end之间的部分。这段程序实际上是个递归，多行的情况可以归约到start和end在同一行的情况
void make(int x, int start, int end)
{
  int i, r;
  int a = (start - 1) / t, b = (end - 1) / t;
  if (a != b)//如果不在同一行
  {
    make(x, start, b * t);//归约
    make(x, b * t + 1, end);//同一行的情况
    return;
  }
  //通过get函数算出最大的绝对值，保存在last中，the保存当前位置算出的最大绝对值。如果两者相同，就要进行合并
  int last = get(x, start), sum = 0, the;
  for (i = start; i <= end;)
  {
    the = get(x, i);
    r = late(x, i, end - 1);
    if (the == last)
      sum += r;//合并
    else
    {
      ansdigit[++k] = last;
      ansnum[k] = sum;
      sum = r;
      last = the;
    }
    i += r;
  }
  ansdigit[++k] = last;
  ansnum[k] = sum;
}
int main()
{
  int i, x, y;
  sum[0] = 0;
  while ((cin>>t) && t)
  {
    i = 0;
    k = 0;
    while ((cin>>x>>y) && (x || y))
    {
      digit[++i] = x; //digit数组保存输入元素
      num[i] = y;//num数组保存元素个数
      sum[i] = sum[i - 1] + num[i];//sum数组记录元素个数和，主要用于判断元素i的周围8个元素是什么
    }
    n = i;
    for (i = 1; i <= n; ++i)
    {
      if (num[i] <= t + t + 2)//不存在同一个元素跨越3行的情况
        make(i, sum[i - 1] + 1, sum[i]);
      else
      {
        make(i, sum[i - 1] + 1, sum[i - 1] + t + 1);//前面部分同if部分
        ansdigit[++k] = 0;//中间直接为0
        ansnum[k] = num[i] - 2 * t - 2;//0的个数
        make(i, sum[i] - t, sum[i]);//后面部分也需要计算
      }
    }
    printf("%d\n", t);//输出开始
    for (i = 1; i <= k;)
    {
      int outdigit = ansdigit[i];
      int outnum = 0;
      while (i <= k && ansdigit[i] == outdigit)//如果相邻元素相同，需要合并
        outnum += ansnum[i++];
      printf("%d %d\n", outdigit, outnum);
    }
    printf("0 0\n");
  }
  printf("0\n");
}
