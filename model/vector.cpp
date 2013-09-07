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
    mpf_class length = this->length();

    mpf_class x = this->x_ / length;
    mpf_class y = this->y_ / length;
    mpf_class z = this->z_ / length;

    Vector result(x, y, z);
    return result;
}

Vector Vector::scaleByFactor(mpf_class factor) const
{
    mpf_class x = this->x_ * factor;
    mpf_class y = this->y_ * factor;
    mpf_class z = this->z_ * factor;

    Vector result(x, y, z);
    return result;
}

Vector Vector::add(Vector vector) const
{
    mpf_class x = this->x_ + vector.x();
    mpf_class y = this->y_ + vector.y();
    mpf_class z = this->z_ + vector.z();

    Vector result(x, y, z);
    return result;
}

Vector Vector::sub(Vector vector) const
{
    mpf_class x = this->x_ - vector.x();
    mpf_class y = this->y_ - vector.y();
    mpf_class z = this->z_ - vector.z();

    Vector result(x, y, z);
    return result;
}

QString Vector::toString() const
{
    mp_exp_t expx;
    QString xs = QString::fromStdString(this->x_.get_str(expx));
    xs += "e" + QString::number(expx - (int)xs.length());

    mp_exp_t expy;
    QString ys = QString::fromStdString(this->y_.get_str(expy));
    ys += "e" + QString::number(expy - (int)ys.length());

    mp_exp_t expz;
    QString zs = QString::fromStdString(this->z_.get_str(expz));
    zs += "e" + QString::number(expz - (int)zs.length());

    //QString result(xs + " " + ys + " " + zs);
    QString result(xs + " " + ys);
    return result;
}
