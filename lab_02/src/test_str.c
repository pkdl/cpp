#include "test_str.h"
#include "str.h"
#include <stdio.h>

void test_strcpy(){
	char *s = "test strcpy\0";
	char dest[100];
	_strcpy(dest, s);
	printf("%s\n", dest);
}

void test_strcat(){
	char s1[100] = "test \0";
	char *s2 = "strcat\0";
	_strcat(s1, s2);
	printf("%s\n", s1);
}

void test_strcmp(){
	printf("test strcmp: %i\n", _strcmp("abcde", "abcd"));
}

void test_strlen(){
	printf("test strlen: %i\n", _strlen("qwe"));
}		