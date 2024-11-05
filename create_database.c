#include "inverted_search.h"
char fname[FNAME_SIZE];
int flag=1;
void create_database(Flist *f_head,Wlist *head[]){
    while(f_head){
        read_datafile(f_head ,head, f_head->file_name);
        f_head=f_head->link;
    }
}

Wlist *read_datafile(Flist *file,Wlist *head[],char *filename){
    FILE *fptr=fopen(filename,"r");
    strcpy(fname,filename);
    char word[WORD_SIZE];
    while(fscanf(fptr, "%s", word)!=EOF){
        int index=tolower(word[0]) % 97;
        if(!(index >= 0 && index <= 25)){
            index=26;
        }
        flag=1;
        if(head[index] !=NULL){
            Wlist *temp=head[index];
            while(temp != NULL){
                if(!strcmp(temp->word,word)){
                    update_word_count(&temp,filename);
                    flag =0;
                    break;
                }
                temp=temp->link;
            }
        }
        if(flag == 1){
        insert_at_last(&head[index],word);
        }
    }
}

int update_word_count(Wlist **head, char *file_name) {
    // Pointer to the head of the list of Ltable nodes associated with the word
    Ltable *file_node = (*head)->Tlink;

    // Traverse through Ltable nodes to see if the file already exists
    while (file_node != NULL) {
        if (strcmp(file_node->file_name, file_name) == 0) {
            // If file_name matches, increment word count for that file
            file_node->word_count++;
            return 0;  // Success
        }
        file_node = file_node->table_link;
    }

    // If file_name was not found, create a new Ltable node
    Ltable *new_file_node = (Ltable *)malloc(sizeof(Ltable));
    if (!new_file_node) {
        perror("Failed to allocate memory for new Ltable node");
        return -1;  // Memory allocation error
    }

    // Initialize the new Ltable node
    strcpy(new_file_node->file_name, file_name);  
    new_file_node->word_count = 1;
    new_file_node->table_link = (*head)->Tlink;

    // Update the file table and increment file count
    (*head)->Tlink = new_file_node;
    (*head)->file_count++;

    return 0;
}
