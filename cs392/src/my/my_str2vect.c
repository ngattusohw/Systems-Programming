// Takes a string 
// Allocates a new vectoror (array of string ended by a NULL), 
// Splits apart the input string x at each space character 
// Returns the newly allocated array of strings
// Any number of ' ','\t', and '\n's can separate words.
// I.e. "hello \t\t\n class,\nhow are you?" -> {"hello", "class,", "how", "are","you?", NULL}
#include "my.h"

#define TRUTH_STATEMENT(chr) ((chr) == ' ' || (chr) == '\t' || (chr) == '\n')

static char **str2vect(char **vector, int vectorlen, char *str) {
    
    int curr_len = 0;
    while(!TRUTH_STATEMENT(*str) && *str != '\0'){
        ++str;
        ++curr_len;
    }

    if(curr_len > 0){
        char *word = (char*) malloc(curr_len + 1);
        my_strncpy(word, str-curr_len, curr_len);
        
        vector = realloc(vector, (vectorlen + 1) * sizeof(char *));
	    vector[vectorlen-1] = word;
	    vector[vectorlen] = NULL;

        ++vectorlen;
    }

    while(TRUTH_STATEMENT(*str) && *str != '\0'){
        ++str;
    }

    if(*str == '\0'){
        return vector;
    }

    return str2vect(vector, vectorlen, str);
}

char **my_str2vect(char *str) {
    char *s = str;
    char **vector = { NULL };
    if(!str) return vector;
    return str2vect(vector, 1, s);
}

