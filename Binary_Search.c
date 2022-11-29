typedef int ElemType;

int Binary_Search(ElemType A[], ElemType L, ElemType R, ElemType x) {
	int mid;
	while (L<R) {
		mid = (L+R)/2;
		if (x<=A[mid])
			R=mid;
		else
			L=mid+1;
	}
	if (A[L]==x)	return L;
	return -1;
}