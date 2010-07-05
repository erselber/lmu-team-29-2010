#ifndef QUATERNION_H
#define QUATERNION_H


class Quaternion
{


public:
    Quaternion(double alpha, float vector[3]);


    void multiply(Quaternion *q1, Quaternion *q2);

    void quatToMatrix(float matrix[16]);

    float coords[4];

private:

    float *s;

};

#endif // QUATERNION_H
