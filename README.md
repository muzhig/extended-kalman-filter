Extended Kalman Filter
======================

C++ implementation of EKF.
Arduino compatible.

Depency: [LineArduino](https://github.com/muzhig/linearduino "linear algebra library for arduino") 

You must implement functions declared in KalmanParams.h to define your matricies.

Functions *getF* and *getH* have an additional parameter - vector *z* (one-column matrix) of current state.
