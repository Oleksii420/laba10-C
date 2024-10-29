#include <stdio.h>

#define N 5

typedef struct Employee {
    char name[50];
    char surname[50];
    char gender;
    int day;
    int month;
    int year;
} Employee;

int CalculateAge(int day, int month, int year, int currentDay, int currentMonth, int currentYear) {
    int age = currentYear - year;

    if (currentMonth < month || (currentMonth == month && currentDay < day)) {
        age--;
    }
    return age;
}

void findYoungerAverage(Employee e[], int count, int currentDay, int currentMonth, int currentYear) {
    int totalAge = 0;

    for(int i = 0; i < count; i++) {
        totalAge += CalculateAge(e[i].day, e[i].month, e[i].year, currentDay, currentMonth, currentYear);
    }
    double averageAge = (double)totalAge / count;

    printf("Employees whose age is less than the average:\n");

    for(int i = 0; i < count; i++) {
        int age = CalculateAge(e[i].day, e[i].month, e[i].year, currentDay, currentMonth, currentYear);
        if (age < averageAge) {
            printf("%s, %s, age: %d years\n", e[i].name, e[i].surname, age);
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

    findYoungerAverage(e, n, 28, 10, 2024);
    return 0;
}
