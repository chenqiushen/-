#include <stdio.h>
#include <stdlib.h>

void splitN(int n, int m); // n����Ҫ��ֵ����� m�ǲ�ֵĽ���
int x[1024]= {0} , total = 0; //total���ڼ�����ֵķ������� x[] ���ڴ洢�� 

int main(){
	int n;
	printf("please input the natural number n:");
	scanf("%d", &n);
	splitN(n, 1);
	printf("There are %d ways to split natural %d", total, n);
	return 0;	
}

void splitN(int n, int m){// n����Ҫ��ֵ����� m�ǲ�ֵĽ���
	int rest , i, j;
	for(i = 1; i <= n; i++)
	{// ��1��ʼ���Բ��
		if(i >= x[m-1])
		{//��ֵ������ڻ����ǰһ���Ӷ���֤���ظ�
			x[m] = i; //�������������
			rest =  n - i; // ʣ�µ�����n - i, ����Ѿ�û��ʣ�µ��ˣ����ҽ��ȣ��ܵĲ�ָ���������1��˵���Ѿ��õ�һ������� 
			if(rest == 0 &&m > 1)
			{
				total++;
				printf("%d\t", total);
				for(j = 1; j < m; j++)
				{
					printf("%d ",x[j]);
				}
				printf("%d", x[m]);
					printf("\n");
				
			 } 
			 else{
			 	splitN(rest, m+1); // ����ʣ�µ������ж�Ϊ m+1��� 
			 }
			 x[m] = 0; //ȡ�����ν����������һ�β�֡������ָ��������� 
		} 
	}
}
