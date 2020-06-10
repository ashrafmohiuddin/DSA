#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node {
    int value;
    struct Node * left;
    struct Node * right;
};
void insert(struct Node **,int );
void successor(struct Node *,int );
void predecessor(struct Node *,int );
struct Node *search(struct Node *,int );
struct Node *delete(struct Node *,int );
void preorder(struct Node *);
void inorder(struct Node *);
void postorder(struct Node *);
void findMin(struct Node *);
void findMax(struct Node *);
int main(){
    char ch[4];
    scanf("%s",ch);
    int n,k;
    struct Node *tree = NULL;
    while(1){
        if(!strcmp(ch,"insr")){
            scanf("%d",&n);
            insert(&tree,n);
        }
        else if(!strcmp(ch,"srch")){
            scanf("%d",&k);
            if(search(tree,k)!=NULL)
                printf("FOUND\n");
            else
                printf("NOT FOUND\n");
        }
        else if(!strcmp(ch,"minm"))
            findMin(tree);
        else if(!strcmp(ch,"maxm"))
            findMax(tree);
        else if(!strcmp(ch,"pred")){
            scanf("%d",&k);
            predecessor(tree,k);
        }
        else if(!strcmp(ch,"succ")){
            scanf("%d",&k);
            successor(tree,k);
        }
        else if(!strcmp(ch,"delt")){
            scanf("%d",&k);
            if(delete(tree,k)==NULL)
                printf("NULL\n");
        }
        else if(!strcmp(ch,"inor")){
            inorder(tree);
            printf("\n");
        }
        else if(!strcmp(ch,"prer")){
            preorder(tree);
            printf("\n");
        }
        else if(!strcmp(ch,"post")){
            postorder(tree);
            printf("\n");
        }
        else if(!strcmp(ch,"stop"))
            break;
        scanf("%s",ch);
    }
return 0;
}
void insert(struct Node ** tree,int n){
    struct Node *new;
    new = (struct Node *)malloc(sizeof(struct Node));
    new->value = n;
    new->left = NULL;
    new->right = NULL;
    if(*tree == NULL)
        *tree = new;
    else{
        struct Node *temp;
        temp = *tree;
        int flag = 0;
        while(1){
            if(temp->value>=n){
                if(temp->left!=NULL)
                    temp = temp->left;
                else
                    flag = 1;
            }
            else{
                if(temp->right!=NULL)
                    temp = temp->right;
                else
                    flag = 2;
            }
            if(flag)
                break;
        }
        if(flag == 1)
            temp->left = new;
        else
            temp->right = new;
    }
}

void findMin(struct Node *tree){
    if(tree!=NULL){
        while(tree->left!=NULL)
            tree = tree->left;
        printf("%d\n",tree->value);
    }
    else
        printf("NIL\n");
}

void findMax(struct Node *tree){
    if(tree!=NULL){
        while(tree->right!=NULL)
            tree = tree->right;
        printf("%d\n",tree->value);
    }
    else
        printf("NIL\n");
}

void inorder(struct Node *tree){
    if(tree!=NULL){
        inorder(tree->left);
        printf("%d ",tree->value);
        inorder(tree->right);
    }
}

void preorder(struct Node *tree){
    if(tree!=NULL){
        printf("%d ",tree->value);
        preorder(tree->left);
        preorder(tree->right);
    }
}

void postorder(struct Node *tree){
    if(tree!=NULL){
        postorder(tree->left);
        postorder(tree->right);
        printf("%d ",tree->value);
    }
}

struct Node * search(struct Node * tree,int n){
    while(tree!=NULL){
        if(tree->value>n)
            tree = tree->left;
        else if(tree->value<n)
            tree = tree->right;
        else
            break;
    }
    return tree;
}

struct Node *delete(struct Node *tree,int n){
    if(tree==NULL){
        return NULL;
    }
    if(tree->value>n)
        tree->left = delete(tree->left,n);
    else if(tree->value<n)
        tree->right = delete(tree->right,n);
    else{
        if(tree->left==NULL && tree->right==NULL)
            tree = NULL;
        else if(tree->left == NULL)
            tree = tree->right;
        else if(tree->right == NULL)
            tree = tree->left;
        else{
            struct Node *temp;
            temp = tree->right;
            while(temp->left!=NULL)
                temp = temp->left;
            tree->value = temp->value;
            tree->right = delete(tree->right,temp->value);
        }
    }
    return tree;
}

void predecessor(struct Node *tree,int n){
    struct Node *temp;
    temp = search(tree,n);
    if(temp==NULL)
        printf("NULL\n");
    else if(temp->left!=NULL){
        struct Node *old;
        old = temp->left;
        while(temp->right!=NULL)
            temp = temp->right;
        printf("%d\n",temp->value);
    }
    else{
        struct Node *t;
        t = tree;
        while(t->left!=NULL)
            t =t->left;
        if(t->value==n){
            printf("-1\n");
            return;
        }
        int x;
        t = tree;
        while(t->value!=n){
            if(n>t->value){
                x = t->value;
                t = t->right;
            }
            else
                t = t->left;
        }
        printf("%d\n",x);
    }
}

void successor(struct Node *tree,int n){
    struct Node *temp;
    temp = search(tree,n);
    if(temp==NULL)
        printf("NULL\n");
    else if(temp->right!=NULL){
        struct Node *t;
        t = temp->right;
        while(t->left!=NULL)
            t = t->left;
        printf("%d\n",t->value);
    }
    else{
        struct Node *t;
        t = tree;
        while(t->right!=NULL)
            t = t->right;
        if(t->value == n)
            printf("-1\n");
        else{
            int x;
            t = tree;
            while(t->value!=n){
                if(n<t->value){
                    x = t->value;
                    t = t->left;
                }
                else
                    t = t->right;
            }
            printf("%d\n",x);
        }
    }
}
