#include <stdio.h>
#include <stdlib.h>
#include <string.h>


const char* hex2binary(unsigned const char hex[]){
	int length = strlen(hex);
	char *binAddress = malloc((length*4+1)*sizeof(char));
	if (binAddress == NULL) {
  		fprintf(stderr, "malloc failed\n");
  		return NULL;
	}
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
	return (char *)binAddress;
}

static char encoding_table[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
                                'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
                                'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
                                'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f',
                                'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
                                'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
                                'w', 'x', 'y', 'z', '0', '1', '2', '3',
                                '4', '5', '6', '7', '8', '9', '+', '/'};
static char *decoding_table = NULL;
static int mod_table[] = {0, 2, 1};


char *base64_encode(const unsigned char *data,
                    size_t input_length,
                    size_t *output_length) {

    *output_length = 4 * ((input_length + 2) / 3);

    char *encoded_data = malloc(*output_length);
    if (encoded_data == NULL) return NULL;

    for (int i = 0, j = 0; i < input_length;) {

        uint32_t octet_a = i < input_length ? (unsigned char)data[i++] : 0;
        uint32_t octet_b = i < input_length ? (unsigned char)data[i++] : 0;
        uint32_t octet_c = i < input_length ? (unsigned char)data[i++] : 0;

        uint32_t triple = (octet_a << 0x10) + (octet_b << 0x08) + octet_c;

        encoded_data[j++] = encoding_table[(triple >> 3 * 6) & 0x3F];
        encoded_data[j++] = encoding_table[(triple >> 2 * 6) & 0x3F];
        encoded_data[j++] = encoding_table[(triple >> 1 * 6) & 0x3F];
        encoded_data[j++] = encoding_table[(triple >> 0 * 6) & 0x3F];
    }

    for (int i = 0; i < mod_table[input_length % 3]; i++)
        encoded_data[*output_length - 1 - i] = '=';

    return encoded_data;
}

long binary2b64(unsigned const char *bin){
	int length = strlen(bin);
	if(length%24 != 0){
		fprintf(stderr, "Binary string has the wrong size\n");
  		return NULL;
	}
	char *hexAddress = malloc((length/24*4+1)*sizeof(char));
	if (hexAddress == NULL) {
  		fprintf(stderr, "malloc failed\n");
  		return NULL;
	}
	int i, j;
	for (j = i = 0; i < strlen(bin); i+=3, j+=4){
}

int main(void){
	const char* addr = hex2binary("49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d");
    printf("%s\n", addr);
    int *output_length=malloc(sizeof(int));
    unsigned char* hex = base64_encode(addr, strlen(addr), output_length);
    printf("%s\n", hex);
    return 0;
}
