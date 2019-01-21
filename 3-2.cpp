#include <stdio.h>
#include <stdlib.h>
#define MaxSize 10000
typedef int DataType;
typedef struct{
	int i, j;
	DataType v;
}TriTupleNode;
typedef struct{
	TriTupleNode data[MaxSize];
	int m, n, t; 
}TriTupleTable;
void TransMatrix(TriTupleTable *b, TriTupleTable *a){
	int p, q,co1;
	b->m = a->n; b->n = a->m;
	b->t = a->t;
	if(b->t <=0)
	{
		printf("A = 0");
		exit(1);
	}
	q = 0;
	for(co1 = 0; co1 < a->n;co1++)
		for(p = 0; p < a->t; p++)
			if(a->data[p].j  == co1){
				b->data[q].i = a->data[p].j;
				b->data[q].j = a->data[p].i;
				b->data[q].v = a->data[p].v;
				q++;
			}
}
int  main(){
	TriTupleTable a, b;
	
	TransMatrix (&a, &b);
	return 1; 
}
