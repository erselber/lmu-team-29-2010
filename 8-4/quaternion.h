#ifndef QUATERNION_H
#define QUATERNION_H


class Quaternion
{


public:
    Quaternion(float alpha, float vector[3]);


    void multiply(Quaternion *q1, Quaternion *q2);

    void quatToMatrix(float matrix[16]);

    void slerp(Quaternion *q1, Quaternion *q2, float t);

    float coords[4];

private:

    float *s;

};

#endif // QUATERNION_H
