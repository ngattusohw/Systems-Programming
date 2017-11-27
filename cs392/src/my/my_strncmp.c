#include "../../include/my.h"

/*
	Same as my_strcmp except:
 Only compares n chars or until the end of a string
 */

int my_strncmp(char*a, char *b, int n){
	int i = 0;
    int flag = 0;    
    while (flag == 0 && i<n)
    {
        if (a[i] > b[i])
        {
            flag = 1;
        }
        else if (a[i] < b[i])
        {
            flag = -1;
        }

        if (a[i] == '\0')
        {
            break;
        }

        i++;
    }
    return flag;
}
