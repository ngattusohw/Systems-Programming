#include "../../include/my.h"
#include <stdio.h>

// Takes a string 
// Allocates a new vector (array of string ended by a NULL), 
// Splits apart the input string x at each space character 
// Returns the newly allocated array of strings
// Any number of ' ','\t', and '\n's can separate words.
// I.e. "hello \t\t\n class,\nhow are you?" -> {"hello", "class,", "how", "are","you?", NULL}

char** my_str2vect(char* the_string){
	if(the_string){
		int SIZE = 10; //need to figure out how big the char arr should be

		char** the_array = (char**) malloc(sizeof(char*) * SIZE);
		int array_counter = 0;
		int hold_last_index = 0;
		for(int x=0;x<my_strlen(the_string);x++){
			if(the_string[x] == ' '){
				char* the_string_to_place = (char*) malloc(sizeof(char) * (x-hold_last_index));
				int string_to_place_counter = 0;
				for(int y=hold_last_index;y<x;y++){
					the_string_to_place[string_to_place_counter] = the_string[y];
					string_to_place_counter++;
				}
				the_array[array_counter] = the_string_to_place;
				hold_last_index = x+1;
				string_to_place_counter = 0;
				array_counter++;
			}
		}

		the_array[SIZE] = NULL;
		return the_array;
	}else{
		return NULL;
	}


}
 
