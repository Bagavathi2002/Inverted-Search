#include "inverted_search.h"

int main(int argc, char *argv[])
{
	system("clear");
	Wlist *head[27]={NULL};
	if(argc <= 1){
		printf("Enter the valid no .arg\n");
		printf("./slist.exe file1.txt file2.txt......\n");
		return 1;
	}


	Flist *f_head=NULL;

	file_validation_n_file_list(&f_head,argv);
	if(f_head ==NULL){
		printf("NO file added to FLL\n");
		printf("Hence the process got terminated\n");
		return 1;
	}
	int choice;
	char x;
while(1){
printf("Select your choice among following options: \n");
printf("1.Create DATABASE\n");
printf("2.Display DATABASE\n");
printf("3.Search\n");
printf("4.updata DATABASE\n");
printf("5.Save DATABASE\n");
printf("6.Exit the Program\n");
printf("Enter your choice __ \n");

scanf("%d",&choice);
switch(choice)
{
	case 1:
	create_database(f_head,head);
	break;
	case 2:
	display_database(head);
	break;
	case 3:
	char word[WORD_SIZE];
	printf("Enter the word\n");
	scanf("%s", word);
	int index=tolower(word[0]) % 97;
	search(head[index] ,word);
	break;
	case 4:
	update_database( head, &f_head);
	break;
	case 5:
	save_database(head);
	break;
	case 6:
	return 0;
	default:
	printf("Invalid input\n");
	break;
}
printf("Do you want to continue  ? \n Enter y/Y to continue and n/N to discontinue  : ");
scanf(" %c",&x);
if(x =='n' || x =='N'){
	return 0;
}
else if(x=='y' || x =='Y'){
	printf("CONTINUE TO MAIN MENU \n");
}
else{
	printf("Invalid input");
}
}
}


