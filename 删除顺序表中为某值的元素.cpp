void Delete(ElemType A[ ],int n)
{
//A����n��Ԫ�ص�һά���飬���㷨ɾ��A������ֵΪitem��Ԫ��
	int i=0,j=n-1;
	while(i<j){
		while(i<j&&A[i]!=item){
			i++;//��ֵ��Ϊitem������ָ�롣
		}
		if(i<j){
			while(i<j&&A[j]==item){
			j--;//���Ҷ�Ԫ��Ϊitem��ָ������
		}
		}
		if(i<j){
			A[i++]=A[j--];
		}
	}
	
}
