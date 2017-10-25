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
		char* the_current_string = malloc(sizeof(char));
		int the_current_string_size = 1;

		the_array[0] = "MEOW";
		

		for(int x=0;x<my_strlen(the_string);x++){
			if(the_string[x] == ' '){
				printf("TESTING THE FIRST INDEX ::%s \n", the_array[0]);

				//printf("ARRAY COUNTER :: %d STRING : %s\n", array_counter, the_current_string);
				the_array[array_counter] = the_current_string;

				array_counter++;
				hold_last_index = 0;
				the_current_string_size = 1;
				the_current_string = malloc(sizeof(char));
			}else{
				//just append to the current string by using realloc
				the_current_string = realloc(the_current_string, ++the_current_string_size);
				the_current_string[hold_last_index] = the_string[x];
				hold_last_index++;
				printf("%s\n", the_current_string);
			}
			//MAYBE I WANT TO CHANGE IT TO IF THERE ISNT A SPACE APPEND TO THE CURRENT STRING OF THE ARRAY INDEX,
			//AND IF THERE IS A SPACE THEN JUST UP THE INDEX OF THE ARRAY AND THEN HAVE THE NEW SPOT TO APPEND TO THE STRING
		}

		printf("CHEESE %s %d %d\n", the_array[0], array_counter, SIZE);


		the_array[array_counter] = the_current_string;
		the_array[SIZE] = NULL;
		return the_array;
	}else{
		return NULL;
	}


}
 
