void difference(LinkList& La, LinkList& Lb,int *n)
{
	pa=La->next;pb=Lb->next;
	pre=La;//pre为La中pa所指结点的前驱结点的指针
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
