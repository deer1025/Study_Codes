ElemType Max(LinkedList &A) 
{
	if(A->next=NULL){
		return null;
	}
	pMax=A->next;
	p=A->next->next;
	while(p!=Null){
		if(p->data>pMax->data){
			pMax=p;
			p=p->next;
		}
	}
	return pMax->data;
}
