#include<stdio.h>
#include <stdlib.h>
char* StringCopy(const char* source) {
	int len = 0;
	while (source[len] != '\0') {
		len++;
	}

	if(len == 0) {
		return NULL;
	}

	char* copy = (char*)malloc((len + 1) * sizeof(char));
	if (copy == NULL) {
		return NULL;
	}

	for(int i = 0; i <= len; i++) {
		copy[i] = source[i];
	}

	return copy;

}


int main() {
	char arr[] = "Hello";
	char* copy = StringCopy(arr);

	printf("Copied String: %s\n", copy);
}
