#ifndef VECTOR_H
#define VECTOR_H

#include <gmpxx.h>
#include <QString>

class Vector
{
public:
    Vector();
    Vector(QString x, QString y, QString z);
    Vector(mpf_class x, mpf_class y, mpf_class z);

    mpf_class x() const;
    mpf_class y() const;
    mpf_class z() const;

    void setX(QString x);
    void setY(QString y);
    void setZ(QString z);

    void setX(mpf_class x);
    void setY(mpf_class y);
    void setZ(mpf_class z);

    mpf_class  length() const;
    Vector normalized() const;

    Vector scaleByFactor(mpf_class factor) const;
    Vector add(Vector vector) const;
    Vector sub(Vector vector) const;

    QString toString() const;

private:
    mpf_class x_;
    mpf_class y_;
    mpf_class z_;
};

#endif // VECTOR_H
