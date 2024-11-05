#include "inverted_search.h"

void file_validation_n_file_list(Flist **f_head,char *argv[]){
    int i=1;
    while(argv[i]!=NULL){
        int empty= isFileEmpty(argv[i]);
        if(empty==FILE_NOTAVAILABLE){
            printf("File : %s is not  avilable \n",argv[i]);
            printf("Hence we are not adding that file into file linked list\n");
            i++;
            continue;
        }
        else if(empty ==FILE_EMPTY){
            printf("File : %s is not  avilable \n",argv[i]);
            printf("Hence we are not adding that file into file linked list\n");
            i++;
            continue;
        }
        else{
            int ret_val=to_create_list_of_files(f_head ,argv[i]);
            if(ret_val==SUCCESS){
                printf("Successfully inserted the file %s in file linked list\n",argv[i]);
            }
            else if(ret_val==REPEATATION){
                printf("The file %s is repeated .Do not add this file in file linked list\n",argv[i]);
            }
            else{
                printf("FAILURE\n");
            }
            i++;
            continue;
        }
        
    }
}

int isFileEmpty(char *filename){
    FILE *fptr=fopen(filename,"r");
    if(fptr==NULL){
        if(errno==ENOENT){
            return FILE_NOTAVAILABLE;
        }
    }
    else{
        fseek(fptr, 0, SEEK_END);
        if(ftell(fptr)==0){
            fclose(fptr);
            return FILE_EMPTY;
        }
        fclose(fptr);
    }
    return SUCCESS;
}

int to_create_list_of_files(Flist **f_head, char *name){
    Flist *newnode=malloc(sizeof(Flist));
    strncpy(newnode->file_name,name, FNAME_SIZE-1);
    newnode->file_name[FNAME_SIZE-1]='\0';
    newnode->link=NULL;
    if(*f_head==NULL){
        *f_head=newnode;
    }
    else{
    Flist *temp=*f_head;
    while(temp !=NULL){
        if (strcmp(temp->file_name, name) == 0) {
            free(newnode); 
            return REPEATATION;
        }
        temp=temp->link;
    }
    temp=*f_head;
    while(temp->link!= NULL){
        temp=temp->link;
    }
    temp->link=newnode;
    }
    return SUCCESS;
}