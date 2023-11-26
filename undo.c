
# ifndef UNDO

# define UNDO
# include <stdio.h>
# include <stdlib.h>
# include "object.h"



struct Data
{   
    object player;
    object snake;
    char cursor;
};
typedef struct Data  Data;


struct Node
{
    Data data;
    struct Node* next;
};

typedef struct Node Node;


Node* createnode(){
    Node* newnode;
    newnode = (Node*)malloc(sizeof(Node));
    return newnode;
}

void push(Node** head,Data data){
    Node* newnode = createnode();
    if( *head == 0){
        
        newnode->data = data;
        newnode->next =0;
        *head = newnode;
        
    }
    else{
        newnode->data = data;
        newnode->next = *head;
        *head = newnode;
    }
}

Data pop(Node** head){
    Data data={{-1,-1,100},{-1,-1,100},'>'};
    if(*head == 0){

        return data;
    }
    else{
        Node* del;
        data = (*head)->data;
        del = *head;
        *head = (*head)->next;
        free(del);

        return data;
    }
}


#endif