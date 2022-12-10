#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node* link;
}node;
node* head=NULL;
node* temp=NULL;
node *create(int n){
    node* p=NULL;
    int i=0;
    for(i=0;i<n;i++){
        temp=(node*)malloc(sizeof(node));
        printf("enter the no. of node %d==",i+1);
        scanf("%d",&temp->data);
        temp->link=NULL;
        if(head==NULL){
            head=temp;
        }else{
            p=head;
            while(p->link!=NULL){
                p=p->link;
            }p->link=temp;
        }
    }return head;
}
void display(node* head){
    node* p=head;
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->link;
    }
}
void delbeg(){
    temp=head;
    head=temp->link;
    free(temp);
}
void delend(){
    node* ptr=NULL;
    temp=head;
    while(temp->link!=NULL){
        ptr=temp;
        temp=temp->link;
    }ptr->link=NULL;
    free(temp);
}
void delpos(){
    int pos,i=1;
    node* ptr;
    temp=head;
    printf("enter the pos to delete==");
    scanf("%d",&pos);
    while(i<pos-1){
      temp=temp->link;
      i++;
    }ptr=temp->link;
    temp->link=ptr->link;
    free(ptr);
}
int main(){int n;
    printf("enter the node==");
    scanf("%d",&n);
    head=create(n);
    display(head);
    delbeg();
    printf("\n");
    display(head);
    delend();
    printf("\n");
    display(head);
    delpos();
    display(head);  
    return 0;
}