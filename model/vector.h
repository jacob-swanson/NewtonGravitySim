#ifndef VECTOR_H
#define VECTOR_H

#include <gmpxx.h>

class Vector
{
public:
    Vector();
    Vector(mpf_class x, mpf_class y, mpf_class z);

    mpf_class x();
    mpf_class y();
    mpf_class z();

    void setX(mpf_class x);
    void setY(mpf_class y);
    void setZ(mpf_class z);

    mpf_class  length();

    Vector normalized();
    void normalize();

    Vector& operator*=(mpf_class factor);
    Vector& operator/=(mpf_class divisor);
    Vector& operator*=(Vector& vector);
    Vector& operator+=(Vector& vector);
    Vector& operator-=(Vector& vector);

private:
    mpf_class x_;
    mpf_class y_;
    mpf_class z_;
};

#endif // VECTOR_H
