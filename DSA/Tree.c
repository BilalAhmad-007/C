#include<stdio.h>
#include<malloc.h>
struct Node
{
    int data;
    struct Node *l;
    struct Node *r;
};
typedef struct Node Node;
Node* createNode(int data){
    Node* n= (Node*)malloc(sizeof(Node));
    n->data=data;
    n->l=NULL;
    n->r=NULL;
    return n;
}
void preOrder(Node* root){
    if(root!=NULL)
    {   
        printf("%d ", root->data);
        preOrder(root->l);
        preOrder(root->r);
    }
}
void postOrder(Node* root){
    if(root!=NULL)
    {   
        postOrder(root->l);
        postOrder(root->r);
        printf("%d ",root->data);
    }
}
void inOrder(Node* root){
    if(root!=NULL)
    {   
        inOrder(root->l);
        printf("%d ",root->data);
        inOrder(root->r);
    }
}
int main(){
    Node* root=createNode(1);   
    Node* l1=createNode(2);     
    Node* r1=createNode(3);    
    Node* l2=createNode(4);    
    Node* r2=createNode(5);    
    Node* l3=createNode(6);    
    Node* r3=createNode(7);    

    //        1
    //       / \
    //      2   3
    //     / \ / \
    //    4  5 6  7

    //linking the nodes:
    root->l=l1;
    root->r=r1;
    l1->l=l2;
    l1->r=r2;
    r1->l=l3;
    r1->r=r3;

    printf("PreOrder traversal:\n");
    preOrder(root);
    printf("\nInOrder traversal:\n");
    inOrder(root);
    printf("\nPostOrder traversal:\n");
    postOrder(root);
    return 0;
}