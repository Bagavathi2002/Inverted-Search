#include "inverted_search.h"
int insert_at_last(Wlist **head,data_t *data){
    Wlist *new=malloc(sizeof(Wlist));

    new->file_count=1;
    strcpy(new->word,data);
    new->Tlink=NULL;
    new->link=NULL;

    updata_link_table(&new);
    if(*head==NULL){
        *head=new;
        return SUCCESS;
    }

    Wlist *temp=*head;
    while(temp->link){
        temp=temp->link;
    }
    temp->link=new;
    return SUCCESS;
}

int updata_link_table(Wlist **head){
    Ltable *new=malloc(sizeof(Ltable));

    new->word_count=1;
    strcpy(new->file_name,fname);
    new->table_link=NULL;
    (*head)->Tlink=new;
}