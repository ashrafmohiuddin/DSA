#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node {
    int count;
    char ch;
    struct Node *next;
};
struct Node *search(struct Node *list,char c);
void create(struct Node ** list,char str[],int l);
void print(struct Node *list);
struct Node *sortedmerge(struct Node *a,struct Node *b);
void mergesort(struct Node ** list);
void resvalue(struct Node *list,int n);
void split(struct Node *list,struct Node ** left,struct Node ** right);
int main(){
    char str[1000];
    scanf("%s",str);
    int l = strlen(str);
    struct Node *list=NULL;
    create(&list,str,l);
    mergesort(&list);
    int n=0;
    struct Node *temp = list;
    while(temp!=NULL){
        n++;
        temp = temp->next;
    }
    resvalue(list,n);
}
void resvalue(struct Node *list,int n){
	int i;
    int sum = (list->count + list->next->count)*(n-1);
    list = list->next->next;
    for(i=n-2;i>0;i--){
        sum += (list->count)*i;
        list = list->next;
    }
    printf("%d ",sum);
}
void create(struct Node ** list,char str[],int l){
	int i;
    for(i=0;i<l;i++){
        if(*list==NULL){
            struct Node *temp;
            temp = (struct Node *)malloc(sizeof(struct Node));
            temp->count = 0;
            temp->ch = str[i];
            temp->next = NULL;
            *list = temp;
        }
        struct Node *temp = search(*list,str[i]);
        if(temp!=NULL)
            temp->count ++;
        else{
            struct Node *temp;
            temp = (struct Node *)malloc(sizeof(struct Node));
            temp->count = 1;
            temp->ch = str[i];
            temp->next = NULL;
            struct Node *temp1 = *list;
            while(temp1->next!=NULL)
                temp1 = temp1->next;
            temp1->next = temp;
        }
    }
}
struct Node *search(struct Node *list,char c){
    if(list==NULL)
        return NULL;
    if(list->ch == c)
        return list;
    else
        return search(list->next,c);
}
void mergesort(struct Node ** list){
    struct Node *temp = *list;
    struct Node *left;
    struct Node *right;
    if(temp==NULL || temp->next==NULL)
        return ;
    split(temp,&left,&right);
    mergesort(&left);
    mergesort(&right);
    *list = sortedmerge(left,right);
}
struct Node *sortedmerge(struct Node *a,struct Node *b){
    struct Node *res = NULL;
    if(a==NULL)
        return b;
    else if(b==NULL)
        return a;
    if(a->count <= b->count){
        res = a;
        res->next = sortedmerge(a->next,b);
    }
    else{
        res = b;
        res->next = sortedmerge(a,b->next);
    }
    return res;
}
void split(struct Node *list,struct Node ** left,struct Node ** right){
        struct Node *fast;
        struct Node *slow;
        slow = list;
        fast = list->next;
        while(fast!=NULL){
            fast = fast->next;
            if(fast!=NULL){
                slow = slow->next;
                fast = fast->next;
            }
        }
        *left = list;
        *right = slow->next;
        slow->next = NULL;
}
