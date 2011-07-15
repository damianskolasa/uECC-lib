/*
 * ec.c
 *
 *  Created on: Jul 2, 2011
 *      Author: fatfredyy
 */

#include "ec.h"
#include "polarssl/bignum.h"
#include "polarssl/havege.h"
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
	mpi_lset(&point->z, 1);
}

int convert_to_affine(ec_point *point);

int double_ec_point(ec_point *point) {
	mpi A, B, C, D, X3, Y3, Z3;

	mpi_init(&A, &B, &C, &D, &X3, &Y3, &Z3, NULL);

	mpi_mul_mpi(&A, &point->y, &point->y);
	mpi_mod_mpi(&A, &A, &point->domain->order);
	//A = Y1^2 (mod p)

	mpi_mul_mpi(&B, &point->x, &A);
	mpi_mul_int(&B, &B, 4);
	mpi_mod_mpi(&B, &B, &point->domain->order);
	//B = 4*X1*A

	mpi_mul_mpi(&C, &A, &A);
	mpi_mul_int(&C, &C, 8);
	mpi_mod_mpi(&C, &C, &point->domain->order);
	//C = 8*A^2

	mpi_mul_mpi(&D, &point->x, &point->x);
	mpi_mul_int(&D, &point->x, 3);

	mpi


	mpi_free(&A, &B, &C, &D, &X3, &Y3, &Z3, NULL);

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
	int ret;
	havege_state hs;
	mpi *rand_k = NULL;
	unsigned char *p;
	unsigned int i;

	havege_init(&hs);

	printf("ciL: %d biL: %d bcount: %d chcount: %d\n", ciL, biL,
			BITS_TO_LIMBS(239), BITS_TO_LIMBS(239) * ciL);

	rand_k = &(private_key->k);

	mpi_init(rand_k, NULL);

	MPI_CHK( mpi_grow(rand_k, BITS_TO_LIMBS(239)));

	do {
		MPI_CHK( mpi_lset(rand_k, 0));

		p = (unsigned char *) rand_k->p;
		for (i = 0; i < BITS_TO_LIMBS(239) * ciL; i++)
			*p++ = (unsigned char) havege_rand(&hs);

	} while (mpi_cmp_int(rand_k, 0));

	return 1;
	cleanup: mpi_free(rand_k, NULL);
	return -1;

}

int ec_generate_public_key(const ec_private_key *private_key,
		ec_public_key *public_key) {

	return 0;

}
