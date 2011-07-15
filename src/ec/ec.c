/*
 * ec.c
 *
 *  Created on: Jul 2, 2011
 *      Author: fatfredyy
 */

#include "ec.h"
#include "tfm.h"
#include <stdlib.h>

#define ciL    ((int) sizeof(t_int))    /* chars in limb  */
#define biL    (ciL << 3)               /* bits  in limb  */
#define biH    (ciL << 2)               /* half limb size */

/*
 * Convert between bits/chars and number of limbs
 */
#define BITS_TO_LIMBS(i)  (((i) + biL - 1) / biL)

ec_point *ec_point_new() {
	ec_point *point = NULL;
	point = malloc(sizeof(ec_point));
	point->flags = AFFINE | AT_INFINITY;
	return point;
}

int convert_to_Jacobi(ec_point *point) {
	point->flags &= JACOBI_PROJECTIVE;

	return 0;

}

int convert_to_affine(ec_point *point);

int double_ec_point(ec_point *point) {
	fp_int A, B, C, D, X3, Y3, Z3;

	return 0;
}

int ec_point_cmp(ec_point *p1, ec_point *p2) {

	return 0;
}

int generate_ec_public_key(const ec_private_key *private_key,
		ec_public_key *public_key) {
	ec_point point;
	point.flags = AFFINE;

	return 0;
}

int generate_ec_private_key(ec_private_key *private_key) {



	return -1;

}

int ec_generate_public_key(const ec_private_key *private_key,
		ec_public_key *public_key) {

	return 0;

}
