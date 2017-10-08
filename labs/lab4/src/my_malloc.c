#include "../include/my_system.h"

void* my_malloc(size_t size) {
	void *the_return = sbrk(0);
	void *request = sbrk(size);
	if (request == (void*) -1) {
		return NULL;
	} else {
		assert(the_return == request);
		return the_return;
	}
}