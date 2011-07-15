/*
 * ec.h
 *
 *  Created on: Jul 2, 2011
 *      Author: fatfredyy
 */

#ifndef EC_H_
#define EC_H_

#include "polarssl/bignum.h"
#include "polarssl/ec_domains.h"

#define AT_INFINITY 0
#define	AFFINE  1
#define	JACOBI_PROJECTIVE 2

struct ec_point_s;
struct ec_domain_s;

typedef struct ec_point_s ec_point;
typedef struct ec_domain_s ec_domain;

struct ec_point_s {

	ec_domain *domain;
	mpi x;
	mpi y;
	mpi z;
	unsigned char flags;

};

struct ec_domain_s {

	ec_point *generator;
	mpi order;
	int curve_name;
	mpi field;
	mpi a;
	mpi b;

};

typedef struct {

	ec_domain *domain;
	mpi k;

} ec_private_key;

typedef struct {

	const ec_domain *domain;
	ec_point *public_key;

} ec_public_key;

ec_point *ec_point_new();

int ec_point_cmp(ec_point *p1, ec_point *p2);

//Generate prive key

int generate_ec_private_key(ec_private_key *private_key);

int generate_ec_public_key(const ec_private_key *private_key,
		ec_public_key *public_key);

//point multiply

int convert_to_Jacobi(ec_point *point);

int convert_to_affine(ec_point *point);

int double_ec_point(ec_point *point);

#endif /* EC_H_ */
