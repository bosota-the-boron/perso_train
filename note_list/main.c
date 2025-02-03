#include <stdio.h>

int add_note() {
    // Demander à l'utilisateur d'insérer une note
    int note = 0;
    printf("Insert your note: ");
    scanf("%d", &note);
    return note;
}

int average_grade(int* list_case, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += list_case[i];
    }
    return sum / size;
}

int menu(int* out, int* list_case, int* note_count) {
    int i = 0;
    int close = 0;
    printf("Choose an option:\n");
    printf("1. Add note\n2. Average grade\n3. Show notes\n4. Exit\n");
    scanf("%d", &i);
    
    switch (i) {
        case 1:
            if (*note_count < 10) {  // Limite à 10 notes
                list_case[*note_count] = add_note();
                (*note_count)++;
            } else {
                printf("Note limit reached.\n");
            }
            break;
        case 2:
            if (*note_count > 0) {
                int avg = average_grade(list_case, *note_count);
                printf("Average grade: %d\n", avg);
            } else {
                printf("No notes to calculate average.\n");
            }
            break;
        case 3:
            printf("Notes: ");
            for (int i = 0; i < *note_count; i++) {
                printf("%d ", list_case[i]);
            }
            printf("\n");
            break;
        case 4:
            close = 1;
            break;
        default:
            printf("Invalid choice\n");
            break;
    }
    
    if (close == 1) {
        *out = 4; // Change the value of out to 4 to exit the loop
        return 0;
    }
    return 0;
}

int main(void) {
    int out = 0;
    int list_case[10]; // Tableau pour stocker jusqu'à 10 notes
    int note_count = 0; // Compteur de notes

    while (out != 4) {
        menu(&out, list_case, &note_count);
    }

    return 0;
}

