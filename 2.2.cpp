/*2.˳����в��Ҹ�����ֵ (20��) 
Cʱ�����ƣ�3000 ���� |  C�ڴ����ƣ�3000 Kb
��Ŀ���ݣ�
����n����������˳���������һ������,��鵽����������λ�ã��鲻�������-1
��������
������n,Ȼ������n��������������һ�������������
 �������
�����ѯ������鵽�����������ţ��������-1
��������
3*
Tom John Mike*/
#include <stdio.h>
#include <stdlib.h>
typedef struct{
   char name[30];
 int last;
}SeqList;
int f(SeqList l,char s,int a);
int main (){
  int a, b, i, j;
  char s;
  SeqList l;
  scanf("%d",&a);
  for(i = 0; i < a; i++)
    scanf("%s",&l.name[i]);
  scanf("%s",&s);
  j=f(l, s, a);
  printf("%d",j);
}
int f(SeqList l,char s,int a){
  int i=0 , j = 0;
  while((i <= l.last ) && (l.name[i] !=s))
    i++;
  if(i <= l.last )
    return i+1;
  else
    return -1;
}

