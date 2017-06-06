#include<stdlib.h>
#include<stdio.h>

typedef struct node{
    long int data;
    struct node *next;
}Node;

Node *create_list(Node *first);
Node *remove_list(Node *first,int c);
void show(Node *first);

int main(void){
    int c;
    long int number;
    Node *first;

    srand(time(NULL));

    while(1){
        printf("=========================================\n");
        printf("chose you want to do ")
        scanf("%d",&c)
        printf("=========================================\n");
        if(c==0)
            exit(1);
        if(c==1)
            create_list();
        if(c<0)
            remove_list();

        show();

    }





}
Node *create_list(Node *first){


    long int number=rand()%1000*100000+rand()%100000+900000000;
    Node *New;
    New=(Node*)malloc(sizeof(Node));
    New->data=number;
    New->next=NULL;

    if(first==NULL){
        return New;
    }

    Node *Find;
    Find=first;
    while(1){
            if(number<(Find->data)){
                New->next=Find;
                *first=*New;
            }
            else{
                while((Find->next->data)>number){
                    Find=Find->next;
                }
                New->next=Find->next;
                Find->next=New;
            }

    }

}

void show(Node *first){
    Node *Now=first;
    int i;

    if(first==NULL){
        printf("no date\n");
    }
    else{
        i=0;
        while(1){
            printf("%d",Now->date)
            Now=Now->next;
            if(Now==NULL)
                break;
            i++;
            if(i%5==0)
                printf("\n");

        }
    }
}

Node *remove_list(Node *first,int c){
    int i;
    Node *Find=first;
    for(i=-1;i>c;i--){
        Find=Find->next;
    }
    Find->ne
}
