#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

//returns the size of a character array using a pointer to the first element of the character array
int my_strlen(char *ptr){
    int offset = 0;
    int count = 0;
    while(*(ptr + offset) != '\0'){
        count++;
        offset++;
    }
    return count;
}

int main() {

	char buff[3];
    int count = 0;
	int fd = open("test.txt", O_RDONLY);
	int output = open("output.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	int key = 5;
	// ssize_t nrd;
 	int r;
    for ( ; (r = read(fd, &buff, 3)) > 0; count++){
        for(int x=0;x<3;x++){
        	if(buff[x] >= 'A' && buff[x] <= 'Z'){
        		buff[x] = (buff[x] - 'A' - key + 26) % 26 + 'A';
        	}else if(buff[x] >= 'a' && buff[x] <= 'z'){
        		buff[x] = (buff[x] - 'a' - key + 26) % 26 + 'a';
        	}
        	
        	printf("%c", buff[x]);
        }
        write(output, buff, r);
        key+=2;
        key%=26;
    }

    //printf("%s\n", );
 
    close(fd);
    close(output);
	//fscanf(fp, "%s", buff);
	// printf("%s\n", "Test");
	// printf("1 : %s\n", buff );

	//fgets(buff, 255, (FILE*)fp);
	// printf("%s\n", buff );

	// int key = 5;
	// int counter = 1;

	// for(int x=0;x<my_strlen(buff);x++){
	// 	if(counter!=3){
	// 		new[x] = ((buff[x] - key) % 26);
	// 		counter++;
	// 	}else{
	// 		counter = 1;
	// 		key+=2;
	// 		new[x] = ((buff[x] - key) % 26);
	// 		printf("Key: %d x: %d\n", key, x);
	// 	}
	// }


	// fputs(new, fp2);
	// printf("%s\n", new);

	// fclose(fp);
	// fclose(fp2);


	return(0);
}