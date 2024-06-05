#include <stdio.h>

char yuefen[12][4] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};


int LeapYear(int year) {
    return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}
int zeller(int year, int month, int day) {
    if (month < 3) {
        month += 12;
        year--;
    }
    int h = (day + 2 * month + 3 * (month + 1) / 5 + year + year / 4 - year / 100 + year / 400) % 7;
    return h;
}

void printCalendar(int year) {
    char weekDays[7][4] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
    int daysofMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (LeapYear(year)) {
        daysofMonth[1] = 29;
    }
    for (int month = 0; month < 12; month++) {
        printf("\n\n      %s %d\n", yuefen[month], year);
        printf("Sun Mon Tue Wed Thu Fri Sat\n");

        int firstDay = zeller(year, month + 1, 1);
        int dayCount = 0;

        for (int i = 0; i < firstDay; i++) {
            printf("    ");
            dayCount++;
        }
        for (int day = 1; day <= daysofMonth[month]; day++) {
            printf("%3d ", day);
            dayCount++;
            if (dayCount % 7 == 0) {
                printf("\n");
            }
        }
        if (dayCount % 7 != 0) {
            printf("\n");
        }

        printf("\n");
    }
}

int main() {
    int year;
    printf("Enter a year: ");
    scanf("%d", &year);
    printCalendar(year);
    return 0;
}
