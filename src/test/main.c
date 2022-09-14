// Copyright (c) 2022 fsb3rke
//
// This software is released under the MIT License.
// https://opensource.org/licenses/MIT


#include "../calendar.h"

int main(void) {
    int date[3] = {14, 8, 2022};

    printf("DAY NUMBER: %d\n", dayNumber(1, 1, date[2]));
    printf("MONTH NAME: %s\n", monthName(date[1]));
    printf("NUMBER OF MONTH: %d\n", numberOfMonth(date[1], date[2]));
}
