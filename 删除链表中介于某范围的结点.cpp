void delete(LinkList &L, int mink, int maxk)
{
   p=L->next; //��Ԫ���
   while (p && p->data<=mink)
    { pre=p;  p=p->next; } //���ҵ�һ��ֵ>mink�Ľ��
   if (p) 
	{
		while (p && p->data<maxk)  p=p->next;
                      // ���ҵ�һ��ֵ ��maxk�Ľ��
    	q=pre->next;// �޸�ָ��
      	while (q!=p) 
        { s=q->next;  delete q;  q=s; } // �ͷŽ��ռ�
        pre->next=p;
   }
}
