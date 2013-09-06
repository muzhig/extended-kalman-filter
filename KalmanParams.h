#ifndef KALMAN_PARAMS_H_
#define KALMAN_PARAMS_H_

#include <Matrix.h>

void getQ(Matrix& Q);
void getR(Matrix& E);
void getH(Matrix& H, Matrix& z);
void getF(Matrix& F, Matrix& z);
int getN();

#endif
