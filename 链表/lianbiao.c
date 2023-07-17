 # include <stdio.h>
# include <stdlib.h>
/*创建非循环单链表，每个链表节点都是由两部分组成（数据域|指针域）*/
typedef struct lianbiao //构造结构体数据类型struct lianbiao，代表链表一个节点的数据类型以及组成
{
    int data; //数据域
    struct lianbiao * pNext; //指针域，代表节点中存在指针，指向下一个链表的节点，指针的类型就是结构体的类型，代表下一个节点类型struct lianbiao
}LianBiao, *PLianBiao; //将结构体函数类型struct lianbiao利用typedef关键字进行定义,LianBiao等价于struct lianbiao
                       //typedef int  *z代表z是int*的别名,这里typedef struct lianbiao  *PLianBiao 所以PLianBiao等价于struct lianbiao*   
//函数声明
PLianBiao create_list(void);
void traverse_list(struct lianbiao *); 

int main(void)
{   
    PLianBiao pHead = NULL; //等价于struct lianbiao *pHead = NULL 

    pHead = create_list(); //创建一个非循环单链表，并将单链表的头节点的地址赋给pHead
    traverse_list(pHead); //通过头指针这个参数和遍历函数获取链表有效数据

    return 0;
}

//创建链表
struct lianbiao *create_list(void)  //思路就是创造一个由头指针指向的头结点然后通过for循环依次挂上新创造的其他链表节点
{                                                           
    int len; //用来存放有效节点的个数
    int i;
    int val; //用来临时存放用户输入的节点的值

    //用malloc函数生成一个不存放有效数据的头结点，返回第一个字节的地址赋给头指针pHead，则头指针指向这个头结点
    struct lianbiao *pHead = (struct lianbiao *)malloc(sizeof(struct lianbiao)); //malloc函数分配动态内存，函数结束内存空间不会释放
    if (NULL == pHead)//地址为空，也就是空指针，分配失败                        //分配的内存大小就是一个链表节点的大小，所以引用节点的数据类型                             
    {                                                                            
        printf("分配失败，程序终止!\n");                                            
        exit(-1);  //程序终止
    }
    struct lianbiao *pTail = pHead; //生成一个尾指针，始终指向尾节点，这里因为先做的头结点，作为第一个节点所以尾节点就是头结点 
    pTail->pNext = NULL; //尾节点的指针域为空，这一步是为了防止只有一个头结点的情况

    printf("请输入你需要生成的链表的节点的个数:len = ");
    scanf("%d",&len);

    for (i=0; i<len; ++i) //for循环前面需要先生成一个头结点
    {
        printf("请输入第%d个节点的值:",i+1);
        scanf("%d",&val);

        struct lianbiao *pNew = (struct lianbiao *)malloc(sizeof(struct lianbiao)); //生成一个新节点
        if (NULL == pNew)
        {
            printf("分配失败，程序终止!\n");
            exit(-1);
        }
        pNew->data = val; //将用户输入的数据赋给新的节点的数据域
        pTail->pNext = pNew; //将新节点的地址赋给尾节点的指针域，这里就凸显出pTail尾指针的作用了，尾指针永远指向最后一个节点，方便操作最后一个节点
        pNew->pNext = NULL; //每生成一个新节点，新节点就会变成尾节点，所以需要将新节点的指针域清空
        pTail = pNew; //将新节点的地址赋给尾指针，则尾指针指向新节点也就是最后一个节点
    }
    return pHead; //返回头指针（注：这里的pHead头指针和main函数的头指针不是同一个指针变量，只是名字一样）
}

void traverse_list(PLianBiao pHead) //链表的遍历函数，将每个节点的有效数据顺序输出
{
    struct lianbiao *p = pHead->pNext; //思路是设计一个指针，将每个节点的指针域赋给测试指针，看是否为空，最后一个节点指针域为空

    while (NULL != p)  //如果不为空，一直循环
    {
        printf("%d ",p->data);  
        p = p->pNext;
    }
    printf("\n");
    return;
}