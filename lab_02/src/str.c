#include "str.h"

char * _strcpy(char * destination, const char * source){
	char *ret = destination;
	while( *source ){
		*destination++ = *source++;
	}
	*destination = 0;
	return ret;
}

char * _strcat(char * destination, const char * source){
	char *ret = destination;
	while( *destination ){
		destination++;
	}
	while( *source ){
		*destination++ = *source++;
	}
	*destination = 0;
	return ret;
}

int _strcmp(const char * str1, const char * str2){
	while( *str1++ && *str2++);
	return *str1 - *str2;
}

size_t _strlen(const char * str){
	size_t ret = 0;
	while( *str++ ) ret++;
	return ret;
}