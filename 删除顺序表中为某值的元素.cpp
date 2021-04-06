void Delete(ElemType A[ ],int n)
{
//A是有n个元素的一维数组，本算法删除A中所有值为item的元素
	int i=0,j=n-1;
	while(i<j){
		while(i<j&&A[i]!=item){
			i++;//若值不为item，左移指针。
		}
		if(i<j){
			while(i<j&&A[j]==item){
			j--;//若右端元素为item，指针左移
		}
		}
		if(i<j){
			A[i++]=A[j--];
		}
	}
	
}
