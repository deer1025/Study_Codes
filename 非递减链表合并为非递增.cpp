void MergeList(LinkList &LA,LinkList &LB,LinkList &LC)
{
	pa=LA->next;pb=LB->next;
	LC=LA=pc;
	LC->next=NULL;
	while(pa||pb){
		if(!pa){
			q=pb;pb=pb->next;
		}
		else if(!pb){
			q=pa;pa=pa->next;
		}//��������q=pa?pa:pb;�� 
		else if(pa->data<=pb->data){
			q=pa;pa=pa->next;
		}
		else{
			q=pb;pb=pb->next;
		}
		q->next=Lc->next;Lc->next=q;
	}
	delete Lb;
}
