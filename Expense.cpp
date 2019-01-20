/*Memory Time 
给出农夫在n天中每天的花费，要求把这n天分作m组，每组的天数必然是连续的，要求分得各组的花费之和应该尽可能地小，最后输出各组花费之和中的最大值

?

解题思路：

经典的二分穷举

详细的思路我写在程序注释中，这样会更容易懂

看完我的程序还是无法切入题目的同学，建议先用 朴素的穷举 去左这题，虽然很大机会会超时，但是只是为了辅助理解。本题的二分纯粹是一个优化穷举的工具。

?
--------------------- 
作者：小優YoU 
来源：CSDN 
原文：https://blog.csdn.net/lyy289065406/article/details/6648554 
版权声明：本文为博主原创文章，转载请附上博文链接！*/
//612K   297MS 
 
#include<iostream>
using namespace std;
 
int n; //天数
int m; //规定的分组数
 
/*判断用当前的mid值能把天数n分成几组*/
/*通过比较group与m的大小，对mid值进行优化*/
 
bool judge_group(int mid,int money[])
{
	int sum=0;
	int group=1;    //当前mid值能把n天分成的组数(初始把全部天数作为1组)
 
	for(int i=1;i<=n;i++)  //从第一天开始向下遍历每天的花费
		if(sum+money[i]<=mid)  //当前i天之和<=mid时，把他们归并到一组
			sum+=money[i];
		else               //若 前i-1天之和 加上第i天的花费 大于mid
		{
			sum=money[i];  //则把前i-1天作为一组，第i天作为下一组的第一天
			group++;    //此时划分的组数+1
		}
 
	if(group>m)
		return false;   //若利用mid值划分的组数比规定的组数要多，则说明mid值偏小
	else
		return true;    //否则mid值偏大
}
 
int main(void)
{
	while(cin>>n>>m)
	{
		int* money=new int[n+1];  //每天花费的金额
		int low=0;  //下界
		int high=0; //上界
 
		for(int i=1;i<=n;i++)
		{
			cin>>money[i];
 
			high+=money[i];   //把所有天数的总花费作为上界high（相当于把n天都分作1组）
			if(low<money[i])
				low=money[i]; //把n天中花费最多的那一天的花费作为下界low（相当于把n天分为n组）
		}                     //那么要求的值必然在[low,high]范围内
 
		int mid=(low+high)/2;
 
		while(low<high)  //可能在low==high之前，分组数就已经=m，但是mid并不是最优，因此要继续二分
		{
			if(!judge_group(mid,money))
				low=mid+1;     //mid值偏小，下界前移
			else
				high=mid-1;    //mid值偏大，上界后移
 
			mid=(low+high)/2;
		}
 
		cout<<mid<<endl;  //二分搜索最后得到的mid值必然是使得分组符合要求的最优值
 
		delete money;
	}
	return 0;
}

