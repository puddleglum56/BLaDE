#ifndef BONDED_BONDED_H
#define BONDED_BONDED_H

// Forward definitions
class System;

void getforce_bond(System *system,bool calcEnergy);

/*
void getforce_angle(struct_md* md);

void getforce_dih(struct_md* md);

__global__ void getforce_bonded_d();
__global__ void gethessian_bonded_d(struct_bias bias);
*/

#endif
