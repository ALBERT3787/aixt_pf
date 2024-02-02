// Project Name: Aixt project, https://gitlab.com/fermarsan/aixt-project.git
// File Name: uart.c
// Author: Fernando Martínez Santa
// Date: 2023
// License: MIT
//
// Description: input and printing functions.
#include <stdio.h>
#include <string.h>

#define print(STR)      printf("%s", STR)
#define println(STR)    printf("%s\n", STR)

// #define OUT = os__input(IN) 

// char *input(char *msg) {
//     printf("%s", msg);
//     scanf("%s", &__temp_str[0]);
//     return __temp_str;
// }