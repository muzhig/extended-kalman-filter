/*
 * Kalman.cpp
 *
 *  Created on: Aug 31, 2013
 *      Author: muzhig
 */

#include <Kalman.h>
#include <Matrix.h>

ExtendedKalman::ExtendedKalman() {
	int N = getN();
	X = Matrix(N, 1); // column vector
	P = Matrix(N, N);
}

ExtendedKalman::~ExtendedKalman() {

}



void ExtendedKalman::predict() {
	{
		Matrix F;
		getF(F, X);
	//  X = F * X
		X.dotSelf(F, true);
	//	P = F * P * F.T + Q

		P.dotSelf(F, true).dotSelf(F.transpose());
	}
	{
		Matrix Q;
		getQ(Q);
		P += Q;
	}
}

void ExtendedKalman::correct(const Matrix& Z) {
	Matrix K(P);

	Matrix H;
	getH(H, X);
	K.dotSelf(H, true).dotSelf(H.transpose());

	{
		Matrix R;
		getR(R);
		K += R;
	}
	K.inverse();
	K.dotSelf(H.transpose(), true).dotSelf(P, true);
	// K = (P * H.T * (H * P * H.T)^-1)
	{
		Matrix xz(X);
		xz.dotSelf(H, true);
		xz -= Z;
		xz *= -1;
		xz.dotSelf(K, true);
		X += xz;
		// X = X + K * (Z - H * X)
	}

	K.dotSelf(H);
	K -= Matrix::identity(getN());
	K *= -1;
	P.dotSelf(K, true);
	// P = (I - K * H) * P

}
