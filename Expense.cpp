/*Memory Time 
����ũ����n����ÿ��Ļ��ѣ�Ҫ�����n�����m�飬ÿ���������Ȼ�������ģ�Ҫ��ֵø���Ļ���֮��Ӧ�þ����ܵ�С�����������黨��֮���е����ֵ

?

����˼·��

����Ķ������

��ϸ��˼·��д�ڳ���ע���У�����������׶�

�����ҵĳ������޷�������Ŀ��ͬѧ���������� ���ص���� ȥ�����⣬��Ȼ�ܴ����ᳬʱ������ֻ��Ϊ�˸�����⡣����Ķ��ִ�����һ���Ż���ٵĹ��ߡ�

?
--------------------- 
���ߣ�С��YoU 
��Դ��CSDN 
ԭ�ģ�https://blog.csdn.net/lyy289065406/article/details/6648554 
��Ȩ����������Ϊ����ԭ�����£�ת���븽�ϲ������ӣ�*/
//612K   297MS 
 
#include<iostream>
using namespace std;
 
int n; //����
int m; //�涨�ķ�����
 
/*�ж��õ�ǰ��midֵ�ܰ�����n�ֳɼ���*/
/*ͨ���Ƚ�group��m�Ĵ�С����midֵ�����Ż�*/
 
bool judge_group(int mid,int money[])
{
	int sum=0;
	int group=1;    //��ǰmidֵ�ܰ�n��ֳɵ�����(��ʼ��ȫ��������Ϊ1��)
 
	for(int i=1;i<=n;i++)  //�ӵ�һ�쿪ʼ���±���ÿ��Ļ���
		if(sum+money[i]<=mid)  //��ǰi��֮��<=midʱ�������ǹ鲢��һ��
			sum+=money[i];
		else               //�� ǰi-1��֮�� ���ϵ�i��Ļ��� ����mid
		{
			sum=money[i];  //���ǰi-1����Ϊһ�飬��i����Ϊ��һ��ĵ�һ��
			group++;    //��ʱ���ֵ�����+1
		}
 
	if(group>m)
		return false;   //������midֵ���ֵ������ȹ涨������Ҫ�࣬��˵��midֵƫС
	else
		return true;    //����midֵƫ��
}
 
int main(void)
{
	while(cin>>n>>m)
	{
		int* money=new int[n+1];  //ÿ�컨�ѵĽ��
		int low=0;  //�½�
		int high=0; //�Ͻ�
 
		for(int i=1;i<=n;i++)
		{
			cin>>money[i];
 
			high+=money[i];   //�������������ܻ�����Ϊ�Ͻ�high���൱�ڰ�n�춼����1�飩
			if(low<money[i])
				low=money[i]; //��n���л���������һ��Ļ�����Ϊ�½�low���൱�ڰ�n���Ϊn�飩
		}                     //��ôҪ���ֵ��Ȼ��[low,high]��Χ��
 
		int mid=(low+high)/2;
 
		while(low<high)  //������low==high֮ǰ�����������Ѿ�=m������mid���������ţ����Ҫ��������
		{
			if(!judge_group(mid,money))
				low=mid+1;     //midֵƫС���½�ǰ��
			else
				high=mid-1;    //midֵƫ���Ͻ����
 
			mid=(low+high)/2;
		}
 
		cout<<mid<<endl;  //�����������õ���midֵ��Ȼ��ʹ�÷������Ҫ�������ֵ
 
		delete money;
	}
	return 0;
}

