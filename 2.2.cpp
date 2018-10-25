/*2.顺序表中查找给定的值 (20分) 
C时间限制：3000 毫秒 |  C内存限制：3000 Kb
题目内容：
输入n个姓名建立顺序表，并查找一个人名,如查到则输出其表中位置，查不到则输出-1
输入描述
先输入n,然后输入n个姓名。再输入一个待查的姓名。
 输出描述
输出查询结果，查到则输出表中序号，否则输出-1
输入样例
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

