#include "slist.h"

int main() {
    SList myslist;

    SListInit(&myslist);

    int item,key,pos,index;
    SListNode *p;

    int select=1;
    while (select) {
        printf("***************************************\n");
        printf("*  [1]push_back        [2]push_front  *\n");
        printf("*  [3]show_list        [0]quit_system *\n");
        printf("*  [4]pop_back         [5]pop_front   *\n");
        printf("*  [6]insert_pos       [7]insert_val  *\n");
        printf("*  [8]delete_pos       [9]delete_val  *\n");
        printf("*  [10]find            [11]reverse    *\n");
        printf("*  [12]sort            [13]length     *\n");
        printf("*  [14]capacity        [15]clear      *\n");
        printf("***************************************\n");
        printf("请输入你的选择:>");
        scanf("%d",&select);
        switch(select){
            case 1:
                printf("请输入要插入的数据:>");
                while(scanf("%d",&item),item!=-1) {
                    SListPushBack(&myslist, item);
                }
                break;
            case 2:
                printf("请输入要插入的数据:>");
                while(scanf("%d",&item),item!=-1){
                    SListPushFront(&myslist,item);
                }
                break;
            case 3:
                SListShow(myslist);
                break;
            case 4:
                SListPopBack(&myslist);
                break;
            case 5:
                SListPopfront(&myslist);
                break;
            case 7:
                printf("请输入要插入的元素的值:>");
                scanf("%d",&key);
                SListInsertByVal(&myslist,key);
                break;
            case 9:
                printf("请输入要删除的元素的值:>");
                scanf("%d",&key);
                SListDeleteByVal(&myslist,key);
                break;
            case 10:
                printf("请输入要查找的数据:>");
                scanf("%d",&key);
                p = SListFind(myslist,key);
                if(p!=NULL) {
                    printf("找到元素%d,地址为%p\n",p->data, p);
                }else{
                    printf("该元素不存在\n");
                }
                break;
            case 13:
                printf("链表的元素个数是%d\n", SListLength(myslist));
                break;
            default:
                break;
        }
    }

    return 0;
}