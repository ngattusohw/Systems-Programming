#include "../../include/my.h"


int get_spaces(char* the_string);

int get_spaces(char* the_string){
	int spaces=1;
	for(int x=0;x<my_strlen(the_string);x++){
		if(the_string[x] == ' '){
			spaces++;
		}
	}
	return spaces;
}


//try using the libmy stuff instead, also fixing the realloc stuff

// Takes a string 
// Allocates a new vector (array of string ended by a NULL), 
// Splits apart the input string x at each space character 
// Returns the newly allocated array of strings
// Any number of ' ','\t', and '\n's can separate words.
// I.e. "hello \t\t\n class,\nhow are you?" -> {"hello", "class,", "how", "are","you?", NULL}

char** my_str2vect(char* the_string){
	if(the_string){
		int SIZE = 1; //need to figure out how big the char arr should be

		char** the_array = (char**) calloc(SIZE,sizeof(char*));
		int array_counter = 0;
		char* the_current_string = calloc(1,sizeof(char));
		int the_current_string_size = 0;		
		int iterator = 0;
		while(the_string[iterator] && the_string[iterator]!='\0'){
			if(the_string[iterator] == ' ' || the_string[iterator] == '\t' || the_string[iterator] == '\n'){
				if(the_current_string_size!=0){
					array_counter++;
					the_array = realloc(the_array,array_counter);
					the_current_string[the_current_string_size] = '\0';
					the_array[array_counter-1] = my_strdup(the_current_string);
					the_current_string = calloc(1,sizeof(char));
					the_current_string_size=0;
				}
			}else{
				the_current_string = realloc(the_current_string, sizeof(char) * (the_current_string_size + 1));
				the_current_string[the_current_string_size] = the_string[iterator];
				the_current_string_size++;

			}
			iterator++;
		}

		the_array[array_counter] = "NULL";

		return the_array;

	}else{
		return NULL;
	}
}
 
