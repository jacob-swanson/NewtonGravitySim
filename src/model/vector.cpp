#include "vector.h"

Vector::Vector()
{
    this->x_ = 0;
    this->y_ = 0;
    this->z_ = 0;
}

Vector::Vector(QString x, QString y, QString z)
{
    this->x_ = x.toStdString();
    this->y_ = y.toStdString();
    this->z_ = z.toStdString();
}

Vector::Vector(mpf_class x, mpf_class y, mpf_class z)
{
    this->x_ = x;
    this->y_ = y;
    this->z_ = z;
}

mpf_class Vector::x() const
{
    return this->x_;
}

mpf_class Vector::y() const
{
    return this->y_;
}

mpf_class Vector::z() const
{
    return this->z_;
}

void Vector::setX(QString x)
{
    this->x_ = x.toStdString();
}

void Vector::setY(QString y)
{
    this->y_ = y.toStdString();
}

void Vector::setZ(QString z)
{
    this->z_ = z.toStdString();
}

void Vector::setX(mpf_class x)
{
    this->x_ = x;
}

void Vector::setY(mpf_class y)
{
    this->y_ = y;
}

void Vector::setZ(mpf_class z)
{
    this->z_ = z;
}

mpf_class Vector::length() const
{
    // Calculate sqrt(x^2 + y^2 + z^2)

    mpf_class x;
    mpf_pow_ui(x.get_mpf_t(), this->x_.get_mpf_t(), 2);

    mpf_class y;
    mpf_pow_ui(y.get_mpf_t(), this->y_.get_mpf_t(), 2);

    mpf_class z;
    mpf_pow_ui(z.get_mpf_t(), this->z_.get_mpf_t(), 2);

    mpf_class total = x + y + z;

    mpf_class length;
    mpf_sqrt(length.get_mpf_t(), total.get_mpf_t());

    return length;
}

Vector Vector::normalized() const
{
    // Calculate V/|V|

    mpf_class length = this->length();

    mpf_class x = this->x_ / length;
    mpf_class y = this->y_ / length;
    mpf_class z = this->z_ / length;

    Vector result(x, y, z);
    return result;
}

Vector Vector::scaleByFactor(mpf_class factor) const
{
    // Scale me by a factor
    mpf_class x = this->x_ * factor;
    mpf_class y = this->y_ * factor;
    mpf_class z = this->z_ * factor;

    Vector result(x, y, z);
    return result;
}

Vector Vector::add(Vector vector) const
{
    // Add a Vector to me
    mpf_class x = this->x_ + vector.x();
    mpf_class y = this->y_ + vector.y();
    mpf_class z = this->z_ + vector.z();

    Vector result(x, y, z);
    return result;
}

Vector Vector::sub(Vector vector) const
{
    // Subtract a Vector from me
    mpf_class x = this->x_ - vector.x();
    mpf_class y = this->y_ - vector.y();
    mpf_class z = this->z_ - vector.z();

    Vector result(x, y, z);
    return result;
}
