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
	while(pa){u=pa;pa=pa->next;delete u;}//����La��Lb��һ�������β��㣬Ϊ��ʱ������ɾ����һ���ǿձ��е�����Ԫ��
	while(pb){u=pb;pb=pb->next;delete u;}
	pc->next=null;//������β���
	delete Lb;
}
