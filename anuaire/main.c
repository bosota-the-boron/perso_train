#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 100
#define MAX_NAME_LENGTH 25
#define MAX_PHONE_LENGHT 10
#define MAX_LIST 36

typedef struct{
    char name[MAX_NAME_LENGTH];
    char number[MAX_PHONE_LENGHT];
} Contact; // definition de la structure
int contact_count = 0;

Contact list[MAX_CONTACTS]; // assignation a list

void add_contact(){
    int contact_number = 0;
    if(contact_number < 99){
       printf("Entrer contact name_number : ");
       scanf("%s",list[MAX_NAME_LENGTH].name);
       printf("name : %s \n",list[MAX_NAME_LENGTH].name);
       contact_number++;
    }else{
        printf("List full ! Remove contact\n");
    }
}

void see_contact(){
    int i;
    for(i = 0; i != 100; i++){
        printf("'%s'\n",list[i].name);
    }
}


int menu(int* out){
    
    int i_menu = 0;
    int close = 0;
    printf("Choose an option :\n");
    printf("1. Add contact\n2. Search contact\n3. Look all contact\n4. Quit\n");
    scanf("%d", &i_menu);

    switch(i_menu){
        case 1:
            //add_contact
            add_contact();
            break;
        case 2:
            see_contact();
            //Search_contact
            break;
        case 3:
            //see_contact
            break;
        case 4:
            close = 1;
            break;
    }
    if(close == 1){
        *out = 1;
        return 0;
    }
    return 0;
}

int main(){
    int out = 0;
    while(out != 1)
        menu(&out);
}
