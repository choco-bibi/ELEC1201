/* 3.2.c */
/* encipher */

////  3.2 Manipulating Strings    ////

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define OFFSET 10

void encipher(const char *p, char *c, const unsigned int offset){
	int i, j=0;
	for (i=0; p[i];i++){
		if(isalpha (p[i])){
			c[j++] = ((toupper (p[i])) - 65 +offset) %26 +65;
		}
	c[j] = '\0';
	}
}

void decipher(const char *c, char *b, const unsigned int offset){
	int i, j=0;
	for (i=0; c[i];i++){
		if(isalpha (c[i])){
			b[j++] = ((toupper (c[i])) - 65 -offset +26) %26 +65;
		}
	b[j] = '\0';
	}
}

int main (){
	char p[500] = {"Testing secret cipher functions"};
	char c[500];
	char b[500];

	printf ( "Inserted text: %s \n", p);
	encipher (p, c, OFFSET);
	printf ("ciphered text: %s \n", c);
	decipher (c, b, OFFSET);
	printf ("deciphered text: %s \n", b);

	return 0;
}

// trying out new formatting?  Saves space but I don't really like how it looks. hmph.
// these functions are pretty self explanatory
