typedef int ElemType;
void swap(ElemType*, ElemType*);

void Qsort(ElemType A[], ElemType L, ElemType R) {
	if (L>=R)	return;
	int pivot, i=L, j=R;
	//把A[L~R]中随机一个元素和A[L]交换
	pivot = A[L];
	while (i<j) {
		while(i<j && A[j]>pivot)
			j--;
		while (i<j && A[i]<=pivot)
			i++;
		if(i<j)
			swap(&A[i], &A[j]);
	}
	swap(&A[L],&A[i]);

	Qsort(A, L,i-1);
	Qsort(A,i+1,R);
}


void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
