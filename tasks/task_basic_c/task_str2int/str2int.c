#include <assert.h>
#include "str2int.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>
// если строка пустая или состоит из одного символа, который не цифра

int str_size(const char * str){
	int i = 0;
	const char * strc = str;
	while (*strc) {i++; strc++;}
	return i;
}

int access(const char * str){
	const char * strc = str;
	if (str_size(strc) == 0) return 0;
	else if (str_size(strc) == 1){
		if (*strc < '0' || *strc > '9') return 0;
	}	
	return 1;
}

// проверка, если число превосходит тип int

int more_than_int(const char * str, int sign){
	const char * strc = str;
	if (str_size(strc) < 10) return 0;
	else if (str_size(strc) == 10){
		if (sign == -1){
			char * int_min = "2147483648";
			while (*int_min >= *strc) {strc++; int_min++;}
			if (*int_min == '8') return 0;
			else return 1;
		}
		else {
			char * int_max = "2147483647";
			while (*int_max >= *strc) {strc++; int_max++;}
			if (*int_max == '7') return 0;
			else return 1;
		}
	}
	else return 1;
}

int str2int(const char *str) {
    assert(str[0] != '\0');
    assert(access(str) != 0);
    int sign = 1;
    int num = 0;  
    if (str[0] == '-' || str[0] == '+'){
    	sign = (*str == '-') ? -1 : 1;
	str++;
    } 
    while (*str == ' ') str++;

    assert(more_than_int(str, sign) != 1);

    while (*str){
    	if (*str >= '0' && *str <= '9') num = num*10 + (*str - '0');
	else assert(*str >= '0' && *str <= '9');
	str++;
    }
    return num * sign;
}
