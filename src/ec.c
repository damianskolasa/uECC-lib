/*
 * ec.c
 *
 *  Created on: 11-07-2011
 *      Author: damiank
 */

#include "bn/bn.h"
#include <stdio.h>


int main(void){

	BIGNUM *a = BN_new();
	BIGNUM *b = BN_new();
	BIGNUM *c = BN_new();
	BN_init(a);
	BN_init(b);
	BN_init(c);



	printf("%d\n", BN_dec2bn(&a, "350"));
	printf("%s\n", BN_bn2dec(a));

	printf("%d\n", BN_dec2bn(&b, "2"));
	printf("%s\n", BN_bn2dec(b));

	printf("%d\n", BN_mo(c, a, b, NULL));

	printf("%s\n", BN_bn2dec(c));

	BN_free(a);
	BN_free(b);
	BN_free(c);


	return 0;

}
