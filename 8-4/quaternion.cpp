#define PI 3.14159

#include "quaternion.h"
#include "math.h"

Quaternion::Quaternion(float alpha, float vector[3])
{

    alpha = (2.0*PI/(360.0*2.0))* alpha;

    coords[0] = 1.0;

    float magnitude = sqrt(vector[0]*vector[0] +
                           vector[1]*vector[1] +
                           vector[2]*vector[2]);


    if (magnitude < 0.000000000000000000000000000000000000000000000001)
        return;


    if(magnitude != 0)
    {
        vector[0] /= magnitude;
        vector[1] /= magnitude;
        vector[2] /= magnitude;
    }


    float c = cos(alpha);
    float s = sin(alpha);
    coords[0] = c;
    coords[1] = vector[0] * s;
    coords[2] = vector[1] * s;
    coords[3] = vector[2] * s;
}



void Quaternion::multiply(Quaternion *q1, Quaternion *q2)
{

    q1->coords[0] = q1->coords[0] * q2->coords[0]
                        - q1->coords[1] * q2->coords[1]
                        - q1->coords[2] * q2->coords[2]
                        - q1->coords[3] * q2->coords[3];
    q1->coords[1] = q1->coords[0] * q2->coords[1]
                        + q1->coords[1] * q2->coords[0]
                        + q1->coords[2] * q2->coords[3]
                        - q1->coords[3] * q2->coords[2];
    q1->coords[2] = q1->coords[0] * q2->coords[2]
                        - q1->coords[1] * q2->coords[3]
                        + q1->coords[2] * q2->coords[0]
                        + q1->coords[3] * q2->coords[1];
    q1->coords[3] = q1->coords[0] * q2->coords[3]
                        + q1->coords[1] * q2->coords[2]
                        - q1->coords[2] * q2->coords[1]
                        + q1->coords[3] * q2->coords[0];

}



void Quaternion::quatToMatrix(float matrix[16]){
    float sqw = coords[0]*coords[0];
    float sqx = coords[1]*coords[1];
    float sqy = coords[2]*coords[2];
    float sqz = coords[3]*coords[3];

    // invs (inverse square length) is only required if quaternion is not already normalised
    float invs = 1 / (sqx + sqy + sqz + sqw);
    matrix[0] = ( sqx - sqy - sqz + sqw)*invs ;
    matrix[5] = (-sqx + sqy - sqz + sqw)*invs ;
    matrix[10] = (-sqx - sqy + sqz + sqw)*invs ;

    float tmp1 = coords[1]*coords[2];
    float tmp2 = coords[3]*coords[0];
    matrix[4] = 2.0 * (tmp1 + tmp2)*invs ;
    matrix[1] = 2.0 * (tmp1 - tmp2)*invs ;

    tmp1 = coords[1]*coords[3];
    tmp2 = coords[2]*coords[0];
    matrix[8] = 2.0 * (tmp1 - tmp2)*invs ;
    matrix[2] = 2.0 * (tmp1 + tmp2)*invs ;

    tmp1 = coords[2]*coords[3];
    tmp2 = coords[1]*coords[0];
    matrix[9] = 2.0 * (tmp1 + tmp2)*invs ;
    matrix[6] = 2.0 * (tmp1 - tmp2)*invs ;
}

void Quaternion::slerp(Quaternion *q1, Quaternion *q2, float t)
{

    float cosHalfTheta = q1->coords[0] * q2->coords[0] + q1->coords[1] * q2->coords[1] + q1->coords[2] * q2->coords[2] + q1->coords[3] * q2->coords[3];
            // if qa=qb or qa=-qb then theta = 0 and we can return qa
            if (fabs(cosHalfTheta) >= 1.0)
            {
                this->coords[0] = q1->coords[0];
                this->coords[1] = q1->coords[1];
                this->coords[2] = q1->coords[2];
                this->coords[3] = q1->coords[3];
            }
            else
            {
                float halfTheta = acos(cosHalfTheta);
                float sinHalfTheta = sqrt(1.0 - cosHalfTheta*cosHalfTheta);
                // Calculate temporary values.

                // if theta = 180 degrees then result is not fully defined
                // we could rotate around any axis normal to qa or qb
                if (fabs(sinHalfTheta) < 0.001){ // fabs is floating point absolute

                    this->coords[0] = q1->coords[0]*0.5 + q2->coords[0]*0.5;
                    this->coords[1] = q1->coords[1]*0.5 + q2->coords[1]*0.5;
                    this->coords[2] = q1->coords[2]*0.5 + q2->coords[2]*0.5;
                    this->coords[3] = q1->coords[3]*0.5 + q2->coords[3]*0.5;
                }
                else
                {
                    float ratioA = sin((1 - t) * halfTheta) / sinHalfTheta;
                    float ratioB = sin(t * halfTheta) / sinHalfTheta;
                    //calculate Quaternion.

                    this->coords[0] = q1->coords[0]*ratioA + q2->coords[0]*ratioB;
                    this->coords[1] = q1->coords[1]*ratioA + q2->coords[1]*ratioB;
                    this->coords[2] = q1->coords[2]*ratioA + q2->coords[2]*ratioB;
                    this->coords[3] = q1->coords[3]*ratioA + q2->coords[3]*ratioB;
                }
            }


}

