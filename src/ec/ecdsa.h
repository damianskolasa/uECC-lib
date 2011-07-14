/*
 * ecdsa.h
 *
 *  Created on: Jul 2, 2011
 *      Author: fatfredyy
 */

#ifndef ECDSA_H_
#define ECDSA_H_

#include "polarssl/bignum.h"

typedef struct {

	mpi r;
	mpi s;

} ec_signature;

#endif /* ECDSA_H_ */
