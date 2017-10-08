#include "../include/my_system.h"



int main(){

	int *num =(int*) my_malloc(sizeof (int));
	*num = 3;

	printf("%d\n", *num);
	return 0;
}


  // void *
  //    brk(const void *addr);

  //    void *
  //    sbrk(int incr);