// Copyright (c) 2022 fsb3rke
//
// This software is released under the MIT License.
// https://opensource.org/licenses/MIT


#pragma once

#include <stdio.h>



#define MAGIC_DAY_NUMBERS 0, 3, 2, 5, 0, 3,\
                          5, 1, 4, 6, 2, 4


#define MONTHS "JANUARY", "FEBRUARY", "MARCH", "APRIL", "MAY",\
               "JUNE", "JULY", "AUGUST", "SEPTEMBER", "OCTOBER", "NOVEMBER", "DECEMBER"


// * Except month of february
#define CLASSIC_NUMBER_OF_MONTHS 31, 0, 31, 30, 31, 30,\
                                 31, 31, 30, 31, 30, 31




int dayNumber(int day, int month, int year) {
    if (month < 3) year--;
    static int t[12] = { MAGIC_DAY_NUMBERS };

    return (year + year / 4 - year / 100 + year / 400 + t[month - 1] + day) % 7;
}

char* monthName(int monthIndex) {
    // ! Months are starting from 0th index
    static char* months[12] = { MONTHS };
    char* currentMonth;

    if (monthIndex < 12 && monthIndex >= 0) currentMonth = months[monthIndex];
    return currentMonth;
}

int numberOfMonth(int monthIndex, int year) {
    // ! February is important for use year in this function
    // ! Why? Because we need to find 29th or 28th day in february.

    char* month;
    int classicNumberOfMonth[12] = { CLASSIC_NUMBER_OF_MONTHS };
    int number;


    if (monthIndex < 12 && monthIndex >= 0) month = monthName(monthIndex);
    
    if (month == "FEBRUARY") { // * month == "FEBRUARY" also called monthIndex equal to 1
        if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) number = 29;
        else number = 28;
    }
    else // * month == "JANUARY", "MARCH", "APRIL", "MAY", "JUNE", "JULY", "AUGUST", "SEPTEMBER", "OCTOBER", "NOVEMBER", "DECEMBER"
        number = classicNumberOfMonth[monthIndex];
    
    return number;
}