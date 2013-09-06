Extended Kalman Filter
======================

C++ implementation of EKF.
Arduino compatible.

Depency: [LineArduino](https://github.com/muzhig/linearduino "linear algebra library") 

You must implement functions declared in KalmanParams.h to define your matricies.

In functions *getF* and *getH* you will get additional parameter - vector z (one-column matrix) of current state.
