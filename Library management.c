#include <stdio.h>
#include <string.h>

// Nested struct for Author details
struct Author {
    char name[50];
    char nationality[30];
};

// Struct for Book, containing nested Author struct
struct Book {
    int id;
    char title[50];
    float price;
    struct Author author; // Nested struct
};

// Struct for Library, holding an array of Books
struct Library {
    struct Book books[100];
    int count;
};

// Function to add a book to the library
void addBook(struct Library *lib) {
    if (lib->count < 100) {
        printf("Enter Book ID: ");
        scanf("%d", &lib->books[lib->count].id);
        
        printf("Enter Book Title: ");
        getchar(); // Consume newline
        fgets(lib->books[lib->count].title, 50, stdin);
        lib->books[lib->count].title[strcspn(lib->books[lib->count].title, "\n")] = 0;
        
        printf("Enter Author Name: ");
        fgets(lib->books[lib->count].author.name, 50, stdin);
        lib->books[lib->count].author.name[strcspn(lib->books[lib->count].author.name, "\n")] = 0;
        
        printf("Enter Author Nationality: ");
        fgets(lib->books[lib->count].author.nationality, 30, stdin);
        lib->books[lib->count].author.nationality[strcspn(lib->books[lib->count].author.nationality, "\n")] = 0;
        
        printf("Enter Price: ");
        scanf("%f", &lib->books[lib->count].price);
        
        lib->count++;
        printf("Book added successfully!\n\n");
    } else {
        printf("Library is full!\n\n");
    }
}

// Function to display all books
void displayBooks(struct Library lib) {
    printf("\n--- Library Inventory ---\n");
    if (lib.count == 0) {
        printf("No books in library.\n");
        return;
    }
    for (int i = 0; i < lib.count; i++) {
        printf("ID: %d\n", lib.books[i].id);
        printf("Title: %s\n", lib.books[i].title);
        printf("Author: %s (%s)\n", lib.books[i].author.name, lib.books[i].author.nationality);
        printf("Price: $%.2f\n", lib.books[i].price);
        printf("------------------------\n");
    }
}

// Function to search books by author name
void searchByAuthor(struct Library lib) {
    char authorName[50];
    int found = 0;
    
    printf("Enter Author Name to search: ");
    getchar();
    fgets(authorName, 50, stdin);
    authorName[strcspn(authorName, "\n")] = 0;
    
    printf("\n--- Search Results ---\n");
    for (int i = 0; i < lib.count; i++) {
        if (strcmp(lib.books[i].author.name, authorName) == 0) {
            printf("Found: %s by %s\n", lib.books[i].title, lib.books[i].author.name);
            found = 1;
        }
    }
    if (!found) {
        printf("No books found for author: %s\n", authorName);
    }
}

int main() {
    struct Library lib = {0};
    int choice;
    
    while (1) {
        printf("\n1. Add Book\n2. Display All Books\n3. Search by Author\n4. Exit\nChoose: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addBook(&lib);
                break;
            case 2:
                displayBooks(lib);
                break;
            case 3:
                searchByAuthor(lib);
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}   
