#include<stdio.h>
#include <stdlib.h>
char* StringCopy(const char* source) {
	 if (source == NULL ) { // important to check if pointer valid
		 return NULL;
	 }
	int len = 0;
	while (source[len] != '\0') {
		len++;
	}
	if(len == 0) {
		return NULL;
	}
	char* copy = malloc((len + 1) * sizeof(char));
	if (copy == NULL) {
		return NULL;
	}
	for(int i = 0; i <= len; i++) {
		copy[i] = source[i];
	}
	return copy;
}
int main() {
	char arr[] = "Hello";//arr -> first element
	char * arr1 = "";
	char* copy = StringCopy(&arr[2]);
	printf("Copied String: %s\n", copy);
	free (copy);
	copy = NULL;
}
