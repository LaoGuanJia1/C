 # include <stdio.h>
# include <stdlib.h>
/*������ѭ��������ÿ������ڵ㶼������������ɣ�������|ָ����*/
typedef struct lianbiao //����ṹ����������struct lianbiao����������һ���ڵ�����������Լ����
{
    int data; //������
    struct lianbiao * pNext; //ָ���򣬴���ڵ��д���ָ�룬ָ����һ������Ľڵ㣬ָ������;��ǽṹ������ͣ�������һ���ڵ�����struct lianbiao
}LianBiao, *PLianBiao; //���ṹ�庯������struct lianbiao����typedef�ؼ��ֽ��ж���,LianBiao�ȼ���struct lianbiao
                       //typedef int  *z����z��int*�ı���,����typedef struct lianbiao  *PLianBiao ����PLianBiao�ȼ���struct lianbiao*   
//��������
PLianBiao create_list(void);
void traverse_list(struct lianbiao *); 

int main(void)
{   
    PLianBiao pHead = NULL; //�ȼ���struct lianbiao *pHead = NULL 

    pHead = create_list(); //����һ����ѭ�������������������ͷ�ڵ�ĵ�ַ����pHead
    traverse_list(pHead); //ͨ��ͷָ����������ͱ���������ȡ������Ч����

    return 0;
}

//��������
struct lianbiao *create_list(void)  //˼·���Ǵ���һ����ͷָ��ָ���ͷ���Ȼ��ͨ��forѭ�����ι����´������������ڵ�
{                                                           
    int len; //���������Ч�ڵ�ĸ���
    int i;
    int val; //������ʱ����û�����Ľڵ��ֵ

    //��malloc��������һ���������Ч���ݵ�ͷ��㣬���ص�һ���ֽڵĵ�ַ����ͷָ��pHead����ͷָ��ָ�����ͷ���
    struct lianbiao *pHead = (struct lianbiao *)malloc(sizeof(struct lianbiao)); //malloc�������䶯̬�ڴ棬���������ڴ�ռ䲻���ͷ�
    if (NULL == pHead)//��ַΪ�գ�Ҳ���ǿ�ָ�룬����ʧ��                        //������ڴ��С����һ������ڵ�Ĵ�С���������ýڵ����������                             
    {                                                                            
        printf("����ʧ�ܣ�������ֹ!\n");                                            
        exit(-1);  //������ֹ
    }
    struct lianbiao *pTail = pHead; //����һ��βָ�룬ʼ��ָ��β�ڵ㣬������Ϊ������ͷ��㣬��Ϊ��һ���ڵ�����β�ڵ����ͷ��� 
    pTail->pNext = NULL; //β�ڵ��ָ����Ϊ�գ���һ����Ϊ�˷�ֹֻ��һ��ͷ�������

    printf("����������Ҫ���ɵ�����Ľڵ�ĸ���:len = ");
    scanf("%d",&len);

    for (i=0; i<len; ++i) //forѭ��ǰ����Ҫ������һ��ͷ���
    {
        printf("�������%d���ڵ��ֵ:",i+1);
        scanf("%d",&val);

        struct lianbiao *pNew = (struct lianbiao *)malloc(sizeof(struct lianbiao)); //����һ���½ڵ�
        if (NULL == pNew)
        {
            printf("����ʧ�ܣ�������ֹ!\n");
            exit(-1);
        }
        pNew->data = val; //���û���������ݸ����µĽڵ��������
        pTail->pNext = pNew; //���½ڵ�ĵ�ַ����β�ڵ��ָ���������͹�Գ�pTailβָ��������ˣ�βָ����Զָ�����һ���ڵ㣬����������һ���ڵ�
        pNew->pNext = NULL; //ÿ����һ���½ڵ㣬�½ڵ�ͻ���β�ڵ㣬������Ҫ���½ڵ��ָ�������
        pTail = pNew; //���½ڵ�ĵ�ַ����βָ�룬��βָ��ָ���½ڵ�Ҳ�������һ���ڵ�
    }
    return pHead; //����ͷָ�루ע�������pHeadͷָ���main������ͷָ�벻��ͬһ��ָ�������ֻ������һ����
}

void traverse_list(PLianBiao pHead) //����ı�����������ÿ���ڵ����Ч����˳�����
{
    struct lianbiao *p = pHead->pNext; //˼·�����һ��ָ�룬��ÿ���ڵ��ָ���򸳸�����ָ�룬���Ƿ�Ϊ�գ����һ���ڵ�ָ����Ϊ��

    while (NULL != p)  //�����Ϊ�գ�һֱѭ��
    {
        printf("%d ",p->data);  
        p = p->pNext;
    }
    printf("\n");
    return;
}