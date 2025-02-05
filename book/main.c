#include <stdio.h>
#include <string.h>

#define MAX_TITLE_LENGTH 100
#define MAX_BOOK 100
#define MAX_AUTHOR_LENGTH 25
#define MAX_YEAR_LENGTH 8

typedef struct{
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    int  year;
} Book;

int book_count = 0;

Book library[MAX_BOOK];

int add_book(){
    printf("Enter book title : ");
    scanf("%s", library[book_count].title );
    printf("Enter author name : ");
    scanf("%s", library[book_count].author);
    printf("Enter year of publication : (dd/mm/yyyy)");
    scanf("%d", &library[book_count].year);
    book_count++;
    printf("you have %d book added\n", book_count);
    return 0;
}
int search_book() {

    char s_book[MAX_TITLE_LENGTH];
    int found = 0; // Variable pour indiquer si le livre a été trouvé


    printf("Search book by title: ");
    scanf("%s", s_book);


    // Parcourir tous les livres dans la bibliothèque

    for (int i = 0; i < book_count; i++) {
        // Comparer le titre recherché avec le titre du livre actuel
        if (strcmp(s_book, library[i].title) == 0) {
            printf("Book found:\n");
            printf("Name: %s || Author: %s || Year: %d\n", library[i].title, library[i].author, library[i].year);
            found = 1; // Indiquer que le livre a été trouvé
            break; // Sortir de la boucle après avoir trouvé le livre
        }
    }
    if (!found) {
        printf("Book not found.\n"); // Message si le livre n'est pas trouvé
    }
    return 0;
}


int see_book(){
    int i = 0;
    while(library[i].title != library[book_count].title){
        printf("Name :  %s || Author : %s || Year : %d\n", library[i].title, library[i].author, library[i].year);
        i++;
    }
    return 0;
}

int save_book(){
    FILE *fp = fopen("list.txt", "w"); 
    for(int i =0; i < book_count; i++){
           fprintf(fp, "Name :  %s || Author : %s || Year : %d\n", library[i].title, library[i].author, library[i].year);
     }
    fclose(fp);
    return 0;
}
int menu(int* out){
    int i_menu = 0 , close = 0;
    printf("Choose an option :\n");
    printf("1. Add book\n2. Search book\n3. See all books\n4. Save Book list\n5. Exit\n ");
    scanf("%d", &i_menu);
    
    switch(i_menu){
        case 1:
            add_book();
            break;
        case 2:
            search_book();
            break;
        case 3:
            see_book();
            break;
        case 4:
            save_book();
            break;
        case 5:
            close = 1;
            break;
        default:
            printf("Invalid choice\n");

    }
    if (close == 1){
        *out = 1;
        return 1;
    }
    return 0;
}

int main(){
    int out = 0;
    while(out != 1)
        menu(&out);
    return 0;
}
