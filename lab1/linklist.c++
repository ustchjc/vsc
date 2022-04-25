#include <stdio.h>
#include <stdlib.h>

#define ElemType int

#define _DEBUG_ 1


typedef struct Lnode
{
  ElemType data;
  struct Lnode *next;
} LinkNode, *Linklist;


LinkNode*first;


LinkNode *initList(){
  LinkNode *p=(LinkNode*)malloc(sizeof(LinkNode));
  if(!p){
    printf("初始化分配头结点失败！\n");
    exit(0);
  }
  p->next=NULL;
  return p;
}

#ifdef _DEBUG_

LinkNode head;


void initList1(LinkNode *p){
  p=(LinkNode *)malloc(sizeof(LinkNode));
  if(!p){
    printf("初始化分配头结点失败！\n");
    exit(0);
  }
  p->next=NULL;
}

void initList2(){
  first=&head;
  first->next=NULL;
}
#endif

int ListLength(Linklist p){
  int count=0;
  while(p->next!=NULL){
    count++;
    p=p->next;
  }
  return count;
}

int ListEmpty(Linklist p){
  if(p->next!=NULL)
    return 1;
  return 0;
}

void ClearList(Linklist p){
  LinkNode *q;
  while(p->next!=NULL){
    q=p->next;
    p->next=q->next;
    free(q);//逐步迭代，p始终为奇数，q始终为偶数
  }
}

void DestroyList(Linklist p){
  ClearList(p);
  free(p);
}

int GetElem(Linklist p, int i,ElemType *e){
  int k=0;
  while(p=p->next){
    k++;
    if(k==i){
      *e=p->data;
      return k;
    }
  }
  return 0;
}

LinkNode *LocateElem(Linklist p, ElemType e){
  while(p=p->next){
    if(p->data==e)
    return p;
  }
  return NULL;
}



LinkNode *PriorElem(Linklist p, LinkNode *cur_e){
  for(;p->next;p=p->next)
    if(p->next==cur_e)
      return p;
  return NULL;
}


LinkNode *NextElem(Linklist p, LinkNode *cur_e){
  return cur_e->next;
}


LinkNode *NextElem(Linklist p, int i, ElemType e){
  if(i<1) return NULL;
  for(;p;p=p->next)
    if(--i<1){
      LinkNode *q=(LinkNode *)malloc(sizeof(LinkNode));
      if(!q){
        printf("插入节点时，分配空间失败！\n");
        exit(0);
      }
      q->next=p->next;
      p->next=q;
      q->data=e;
      return q;
    }
  return NULL;
}

int ListDelete(Linklist p, int i, ElemType *e){
  if(i<1) return 0;
  LinkNode *q=p;
  for(p=p->next;p;p=p->next){
    if(--i<1){
      q->next=p->next;
      *e=p->data;
      free(p);
      return 1;
    }
    q=p;
  }
  return 0;
}

void PrintLinkNode(LinkNode *p){
  printf("%d,",p->data);
}

void Add2(LinkNode *p){
  p->data+=2;
  printf("+2,");
}