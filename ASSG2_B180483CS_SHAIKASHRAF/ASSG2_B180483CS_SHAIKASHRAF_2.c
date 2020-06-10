#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node{
    int value;
    struct Node *left;
    struct Node *right;
};
int insert(struct Node ** tree,int n){
    struct Node *new;
    new = (struct Node *)malloc(sizeof(struct Node));
    new->value = n;
    new->left = NULL;
    new->right = NULL;
    if(*tree==NULL)
        *tree = new;
    else{
        struct Node *temp;
        temp = *tree;
        int flag = 0;
        while(temp!=NULL){
                if(temp->value>n){
                    if(temp->left!=NULL)
                        temp = temp->left;
                    else
                        flag = 1;
                }
                else if(temp->value<n){
                    if(temp->right!=NULL)
                        temp = temp->right;
                    else
                        flag = 2;
                }
                if(flag!=0)
                    break;
        }
        if(flag==1)
            temp->left = new;
        else
            temp->right = new;
    }
}
void parantheses(struct Node *tree){
        struct Node *temp;
        temp = tree;
        if(temp==NULL)
            printf("()");
        else{
            printf("(");
            printf("%d",temp->value);
            parantheses(tree->left);
            parantheses(tree->right);
            printf(")");
        }
}
int main(){
    char ch[4];
    scanf("%s",ch);
    int n;
    struct Node *tree = NULL;
    while(1){
        if(strcmp(ch,"insr")==0){
            scanf("%d",&n);
            insert(&tree,n);
        }
        else if(strcmp(ch,"prep")==0)
            parantheses(tree);
        else if(strcmp(ch,"stop")==0)
            break;
        scanf("%s",ch);
    }
    return 0;
}
