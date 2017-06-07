#include<stdlib.h>
#include<stdio.h>

typedef struct node{
    long int data;
    struct node *next;
}Node;

Node *first_list(void);
Node *create_list(Node *first);
Node *remove_list(Node *first,int c);
void show(Node *first);

int main(void){
    int c;
    long int number;
    Node *first=first_list;

    srand(time(NULL));

    while(1){
        printf("=========================================\n");
        printf("chose you want to do \n");
	printf("0.exit 1.creat <0:remove  :");
        scanf("%d",&c);
        printf("=========================================\n");
        if(c==0)
            exit(1);
        if(c==1)
            create_list(first);
        if(c<0)
            remove_list(first,c);

        show(first);

    }





}


Node *first_list(void){
    Node *New;
    New=(Node*)malloc(sizeof(Node));
    New->data=0;
    New->next=NULL;
    return New;
}

Node *create_list(Node *first){


printf("gdfjgkldfj");
    long int number=rand()%1000*100000+rand()%100000+900000000;
    Node *New;
    New=(Node*)malloc(sizeof(Node));
    New->data=number;
    //printf("%d",New->data);
    New->next=NULL;

    /*
    if(first==NULL){
        return New;
    }
    */

    Node *Find;
    Find=first;
    while(1){
	    //number bigger than any other data,so Find is move to the last.
	    if(Find->next==NULL){
		    Find->next=New;
		    break;
	    }
	    //Find not at last 
	    else{
		    //next data bigger than number, so number will be insert to next Find.
		    if(number<(Find->next->data)){
			   New->next=Find->next;
			   Find->next=New;
			   break;
		    }
		    //number is also bigger than next data, so make Find to the next node.
		    Find=Find->next;
	    }
    }



/*
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
*/
}

void show(Node *first){
	
printf("gdfjgkldfj");
    Node *Now=first->next;
    int i;

    if(Now==NULL){
        printf("no date\n");
    }
    else{
        i=0;
        while(1){
            printf("%d\t",Now->data);
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
    Node *Find=first,*Well_remove;
    for(i=-1;i>c;i--){
        Find=Find->next;
    }
    Well_remove=Find->next;
    Find->next=Find->next->next;
    free(Well_remove);
}
