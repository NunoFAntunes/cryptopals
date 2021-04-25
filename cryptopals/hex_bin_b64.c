#include <stdio.h>
#include <string.h>


void hex2binary(unsigned const char hex[]){
	int length = strlen(hex);
	char binAddress[length*4+1];//+1 for NUL
	int i, j;
	for (j = i = 0; i < strlen(hex); i++, j += 4){
        switch(hex[i]){
	        case '0': strcpy(binAddress + j, "0000"); break;
	        case '1': strcpy(binAddress + j, "0001"); break;
	        case '2': strcpy(binAddress + j, "0010"); break;
	        case '3': strcpy(binAddress + j, "0011"); break;
	        case '4': strcpy(binAddress + j, "0100"); break;
	        case '5': strcpy(binAddress + j, "0101"); break;
	        case '6': strcpy(binAddress + j, "0110"); break;
	        case '7': strcpy(binAddress + j, "0111"); break;
	        case '8': strcpy(binAddress + j, "1000"); break;
	        case '9': strcpy(binAddress + j, "1001"); break;
	        case 'a': strcpy(binAddress + j, "1010"); break;
	        case 'b': strcpy(binAddress + j, "1011"); break;
	        case 'c': strcpy(binAddress + j, "1100"); break;
	        case 'd': strcpy(binAddress + j, "1101"); break;
	        case 'e': strcpy(binAddress + j, "1110"); break;
	        case 'f': strcpy(binAddress + j, "1111"); break;
	        default:
	            printf("invalid character %c\n", hex[i]);
	            strcpy(binAddress + j, "0000"); break;
        }
	}
	printf("%s\n", binAddress);
}

long hex2b64(unsigned const char *hex){
	long ret = 0
	while (*hex) {
      ret = (ret << 4) | hextable[*hex++];
   }
   return ret; 
}

int main(void){
	hex2binary("49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d");

    //printf("%s\n", binAddress);
    return 0;
}
