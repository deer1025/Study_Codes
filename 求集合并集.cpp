void Mix(LinkList& La, LinkList& Lb, LinkList& Lc) 
{
	pa=La->next;pb=Lb->next;pc=Lc=La;
	while(pa&&pb)
	{
		if(pa->data==pb->data){
			pc->next=pa;
			pc=pa;
			pa=pa->next;
			q=pb;
			pb=pb->next;
			delete q;		
		}
		else if(pa->data<pb->data)
		{
			q=pa;
			pa=pa->next;
			delete q;
		}
		else if(pa->data>pb->data)
		{
			q=pb;
			pb=pb->next;
			delete q;
		}
	}
	while(pa){u=pa;pa=pa->next;delete u;}//链表La和Lb有一个到达表尾结点，为空时，依次删除另一个非空表中的所有元素
	while(pb){u=pb;pb=pb->next;delete u;}
	pc->next=null;//置链表尾标记
	delete Lb;
}
