#include "inverted_search.h"
int k=0;
char file_name[FNAME_SIZE];
void save_database(Wlist *head[]){
    if(k==0){
    printf("Enter the filename to save the database\n");
    scanf("%s" ,file_name);
    k++;
    }
    FILE *fptr =fopen(file_name ,"w");
    for(int i=0;i< 27;i++){
        if(head[i]!= NULL){
            write_databasefile(head[i], fptr);
        }
    }
    fclose(fptr);
}

void write_databasefile(Wlist *head, FILE *databasefile) {
    Wlist *current = head;
    while (current != NULL) {
        fprintf(databasefile,"#[%d]\n",tolower(head->word[0])%97);
        fprintf(databasefile, "Word is [%s]; File Count is %d :", current->word, current->file_count);
        
        Ltable *table_entry = current->Tlink;
        while (table_entry != NULL) {
            fprintf(databasefile, "  file is  %s : word Count is %d \n", table_entry->file_name, table_entry->word_count);
            table_entry = table_entry->table_link;
        }
        fprintf(databasefile,"\n");

        current = current->link;  
    }
}
