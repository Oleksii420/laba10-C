#include <stdio.h>

typedef struct book {
    char code[10];
    char author[50];
    char title[50];
} book;

typedef struct reader {
    char number[10];
    char name[50];
    char date[10];
} reader;

book input_book() {
    book b;
    printf("Введіть шифр книги: ");
    scanf("%s", b.code);
    printf("Введіть автора книги: ");
    scanf(" %[^\n]%*c", b.author);
    printf("Введіть назву книги: ");
    scanf(" %[^\n]%*c", b.title);
    return b;
}

reader input_reader() {
    reader r;
    printf("Введіть № читацького квитка: ");
    scanf("%s", r.number);
    printf("Введіть прізвище читача: ");
    scanf(" %[^\n]%*c", r.name);
    printf("Введіть дату замовлення: ");
    scanf("%s", r.date);
    return r;
}

void print_info(book b, reader r) {
    printf("\nІнформація про книгу:\n");
    printf("Шифр книги: %s\n", b.code);
    printf("Автор книги: %s\n", b.author);
    printf("Назва книги: %s\n", b.title);

    printf("\nІнформація про читача:\n");
    printf("№ читацького квитка: %s\n", r.number);
    printf("Прізвище читача: %s\n", r.name);
    printf("Дата замовлення: %s\n", r.date);
}

int main() {
    book myBook = input_book();
    reader myReader = input_reader();
    print_info(myBook, myReader);
    return 0;
}
