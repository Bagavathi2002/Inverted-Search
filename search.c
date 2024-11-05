#include "inverted_search.h"
void search(Wlist *head,char *word){
    if(head==NULL){
        printf("List empty,search is not possible\n");
        return ;
    }
    while(head){
        if(strcmp(head->word,word)){
            printf("Word %s is present in %d files\n", word, head->file_count);
            Ltable *Thead =head->Tlink;
            while(Thead){
                printf("In file : %s        %d time\n",Thead->file_name,Thead->word_count);
                Thead=Thead->table_link;
            }
            printf("\n");
            return ;
        }
        head=head->link;
    }
    printf("Search word is not found\n");
}