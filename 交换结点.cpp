void  Exchange��LinkedList p��
//p��˫��ѭ�������е�һ����㣬���㷨��p��ָ�������ǰ����㽻����
{q=p->llink��
 q->llink->rlink=p��   //p��ǰ����ǰ��֮���Ϊp
 p->llink=q->llink��   //p��ǰ��ָ����ǰ����ǰ����
 q->rlink=p->rlink��   //p��ǰ���ĺ��Ϊp�ĺ�̡�
 q->llink=p��          //p����ǰ������
 p->rlink->llink=q��   //p�ĺ�̵�ǰ��ָ��ԭp��ǰ��
 p->rlink=q��          //p�ĺ��ָ����ԭ����ǰ��
}
