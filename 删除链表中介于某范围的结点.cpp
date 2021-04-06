void delete(LinkList &L, int mink, int maxk)
{
   p=L->next; //首元结点
   while (p && p->data<=mink)
    { pre=p;  p=p->next; } //查找第一个值>mink的结点
   if (p) 
	{
		while (p && p->data<maxk)  p=p->next;
                      // 查找第一个值 ≥maxk的结点
    	q=pre->next;// 修改指针
      	while (q!=p) 
        { s=q->next;  delete q;  q=s; } // 释放结点空间
        pre->next=p;
   }
}
