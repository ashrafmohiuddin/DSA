#include<stdio.h>
#include<stdlib.h>

struct Node {
    int value;
    struct Node *left;
    struct Node *right;
};
int long_path(struct Node* tree){
        if (tree == NULL) return 0; 
        int l = height(tree->left); 
        int r = height(tree->right); 
        int l1 = long_path(tree->left); 
        int r1 = long_path(tree->right); 
        return max(l + r, max(l1, r1)); 
}
void create(struct Node ** tree){
    char ch;
    scanf("%c",&ch);
    while(ch==' ' || ch == ')')
        scanf("%c",&ch);
    int n;
    if(scanf("%d",&n)==1){
            struct Node *temp;
            temp = (struct Node *)malloc(sizeof(struct Node));
            temp->value = n;
            temp->left = NULL;
            temp->right = NULL;
            create(&(temp->left));
            create(&(temp->right));
            *tree = temp;
        }
        else
            *tree = NULL;
}
void parantheses(struct Node *tree){
    if(tree==NULL)
        printf("( ) ");
    else{
        printf("( ");
        printf("%d ",tree->value);
        parantheses(tree->left);
        parantheses(tree->right);
        printf(") ");
    }
}
int height(struct Node* tree)  
{ 
   if (tree==NULL)  
       return 0; 
   else 
   { 
       int l= height(tree->left); 
       int r= height(tree->right); 
       if (l > r)  
           return(l+1); 
       else return(r+1); 
   } 
} 
int max(int a,int b){
        if(a>b) return a;
        else return b;}
int main(){
    struct Node *tree = NULL;
    create(&tree);
    printf("%d %d\n",height(tree)-1,long_path(tree));
}
