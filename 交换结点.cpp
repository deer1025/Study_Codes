void  Exchange（LinkedList p）
//p是双向循环链表中的一个结点，本算法将p所指结点与其前驱结点交换。
{q=p->llink；
 q->llink->rlink=p；   //p的前驱的前驱之后继为p
 p->llink=q->llink；   //p的前驱指向其前驱的前驱。
 q->rlink=p->rlink；   //p的前驱的后继为p的后继。
 q->llink=p；          //p与其前驱交换
 p->rlink->llink=q；   //p的后继的前驱指向原p的前驱
 p->rlink=q；          //p的后继指向其原来的前驱
}
