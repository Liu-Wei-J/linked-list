#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
    char name[15];
    char data[15];
    struct node *next;
}Node;

void Add(Node *first);
void Delete(Node *first);
void Search(Node *first);
void show(Node *first);
void Output(Node *first);
int cmp(char a[15],char b[15]);


int main(void){
    Node *first;
    first=(Node*)malloc(sizeof(Node));
    first->next=NULL;

    while(1){
        int c;
        printf("\n\nplease choose a task:\n");
        printf("1\)Add\n");
        printf("2\)Search\n");
        printf("3\)List all\n");
        printf("4\)Delete\n");
        printf("5\)Exit\n:");
        scanf("%d",&c);
        if(c!=1&&c!=5&&first->next==NULL){
            printf("no data in the list!\n");
            continue;
        }

        switch(c){

            case 1:
                Add(first);
                break;

            case 2:
                Search(first);
                break;

            case 3:
                show(first);
                break;

            case 4:
                Delete(first);
                break;

            case 5:
                Output(first);
                exit(1);
        }



    }
}

void Add(Node *first){
    FILE *in;
    Node *Now=first ;
    Node *New;
    char aa[15],bb[15];


    in=fopen("input.txt","r");

    while(fscanf(in,"%s %s",aa,bb) != EOF){

        New=(Node*)malloc(sizeof(Node));

        strcpy(New->name,aa);
        strcpy(New->data,bb);

        //New->name=aa;
        //New->data=bb;
        New->next=NULL;
        Now=first;

        while(1){

            if(Now->next == NULL){
                Now->next=New;
                //printf("sjdhgfa");
                break;
            }
            else if((Now->next->data) > (New->data)){
                New->next=Now->next;
                Now->next=New;
                break;
            }
            else
                Now=Now->next;
        }


    }
}
int cmp(char a[15],char b[15]){

}

void Search(Node *first){
    Node *Find=first->next;
    char s[15];
    printf("Search:");
    scanf("%s",s);

    printf("==================Search=================\n");
    while(1){
        if(strcmp(Find->data,s)==0 || strcmp(Find->name,s) == 0){
            printf("the name:%s\tmoney:%s\n",Find->name,Find->data);
        }

        if(Find->next==NULL){
            printf("==============Search end================");
            break;
        }
        Find=Find->next;

    }


}

void show(Node *first){
    Node *Now= first->next;
    int i=0;

    while(1){
        printf("No.%d id %15s with %15s $\n",i,Now->name,Now->data);
        if(Now->next == NULL){
            break;
        }
        Now=Now->next;
        i++;
    }
}

void Delete(Node *first){
    Node *Find,*Will_det;
    int c,i;
    printf("enter number to delete:");
    scanf("%d",&c);

    for(i=0;i<c;i++){
        Find=Find->next;
    }
    printf("the name:%s\t money:%s",Find->next->name,Find->next->data);
    Will_det=Find->next;
    Find->next=Will_det->next;
    free(Will_det);

}

void Output(Node *first){
    FILE *out;
    out=fopen("output.txt","w");
    Node *Now= first->next;
    int i=0;

    while(1){
        fprintf(out,"No.%d id %15s with %15s $\n",i,Now->name,Now->data);
        if(Now->next == NULL){
            break;
        }
        Now=Now->next;
        i++;
    }
}
