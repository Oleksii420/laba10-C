#include <stdio.h>
#define N 5
#define MALE_PENSION_AGE 65
#define FEMALE_PENSION_AGE 60

typedef struct Employee {
    char name[50];
    char surname[50];
    int day;
    int month;
    int year;
    char gender;
} Employee;

int CalculateAge(int day, int month, int year, int currentDay, int currentMonth, int currentYear) {
    int age = currentYear - year;
    if (currentMonth < month || (currentMonth == month && currentDay < day)) {
        age--;
    }
    return age;
}

void findPensioners(Employee e[], int count, int currentDay, int currentMonth, int currentYear) {
    for (int i = 0; i < count; i++) {
        int age = CalculateAge(e[i].day, e[i].month, e[i].year, currentDay, currentMonth, currentYear);

        if ((e[i].gender == 'M' && age >= MALE_PENSION_AGE) ||
            (e[i].gender == 'F' && age >= FEMALE_PENSION_AGE)) {
            printf("%s %s, age: %d years, gender: %c\n", e[i].name, e[i].surname, age, e[i].gender);
            }
    }
}

int main() {
    Employee e[N];
    int n = N;

    for (int i = 0; i < n; i++) {
        printf("Enter data for employee %d\n", i + 1);
        printf("Surname: ");
        scanf("%s", e[i].surname);
        printf("Name: ");
        scanf("%s", e[i].name);
        printf("Gender (M/F): ");
        scanf(" %c", &e[i].gender);
        printf("Birthday: ");
        scanf("%d", &e[i].day);
        printf("Birth month: ");
        scanf("%d", &e[i].month);
        printf("Year of birth: ");
        scanf("%d", &e[i].year);
    }

    findPensioners(e, n, 28, 10, 2024);

    return 0;
}
