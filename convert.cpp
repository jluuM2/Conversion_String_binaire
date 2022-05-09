#include <stddef.h>

unsigned char hexchr2bin(const char hex)
{
	unsigned char result;

	if (hex >= '0' && hex <= '9') {
		result = hex - '0';
	} else if (hex >= 'A' && hex <= 'F') {
		result = hex - 'A' + 10;
	} else if (hex >= 'a' && hex <= 'f') {
		result = hex - 'a' + 10;
	} else {
		return 0;
	}
	return result;
}



void hexStringToBin(unsigned char *out,const char * hexPrivate) {
    for (int i=0; i<32; i++){
	out[i] = hexchr2bin(hexPrivate[2*i])<<4 | hexchr2bin(hexPrivate[2*i+1]);
    }
}


char *binToHexString(char *out,const unsigned char *bin, size_t len)
{
    size_t  i;

    if (bin == NULL || len == 0)
	return NULL;

    for (i=0; i<len; i++) {
	out[i*2]   = "0123456789abcdef"[bin[i] >> 4];
	out[i*2+1] = "0123456789abcdef"[bin[i] & 0x0F];
    }
    out[len*2] = '\0';

    return out;
}



