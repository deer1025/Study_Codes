void difference(LinkList& La, LinkList& Lb,int *n)
{
	pa=La->next;pb=Lb->next;
	pre=La;//preΪLa��pa��ָ����ǰ������ָ��
	while(pa&&pb)
	{
		if(pa->data<pb->data){
			pre=pa;pa=pa->next;*n++;
		}
		else if(pa->data>pb->data){
			pb=pb->next;
		}
		else{
			pre->next=pa->next;
			u=pa;
			pa=pa->next;
			delete u;
		}
	}
 } 
