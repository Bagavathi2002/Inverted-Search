#include "inverted_search.h"
void update_database(Wlist *head[],Flist **f_head){
    char file_name[FNAME_SIZE];
    printf("Enter the filename\n");
    scanf("%s" ,file_name);

    int empty= isFileEmpty(file_name);
        if(empty==FILE_NOTAVAILABLE){
            printf("File : %s is not  avilable \n",file_name);
            printf("Hence we are not adding that file into file linked list\n");

        }
        else if(empty ==FILE_EMPTY){
            printf("File : %s is not  avilable \n",file_name);
            printf("Hence we are not adding that file into file linked list\n");

        }
        else{
            int ret_val=to_create_list_of_files(f_head ,file_name);
            if(ret_val==SUCCESS){
                printf("Successfully inserted the file %s in file linked list\n",file_name);
            }
            else if(ret_val==REPEATATION){
                printf("The file %s is repeated .Do not add this file in file linked list\n",file_name);
            }
            else{
                printf("FAILURE\n");
            }
        }
        while(*f_head){
            if(!strcmp((*f_head)->file_name ,file_name)){
                create_database(*f_head,head);
                break;
            }
            *f_head=(*f_head )->link;
}
}
