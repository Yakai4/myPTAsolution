```C
List Reverse(List L)
{
    List temp,Head=L,Rear=L;
    if(L==NULL)  return L;
    while(Head->Next!=NULL)
    {
        Head=Head->Next;
    }
    Head->Next=L;
    do{
        temp = L->Next;
        L->Next = Head->Next;
        Head->Next = L;
        L=temp;
    }while(temp!=Head);
    Rear->Next = NULL;
    return Head;
}
```
百度了一下发现多种链表翻转的方法，时间复杂度最好为`O(N)`，空间复杂度最好为`O(1)`。比如以上代码。。。  
直接把最后一个结点当作第一个结点，L当然是最后一个结点的尾指针。。。  
然后遍历链表，头插法依次插入。（头插法特性就是：链表从头指针开始遍历的话，输出与输入顺序是反的）。。。  
以上。  
拓展阅读
[四种方法翻转链表](http://c.biancheng.net/view/8105.html)
