#ifndef VECTOR_H
#define VECTOR_H

#include <gmpxx.h>
#include <QString>

class Vector
{
public:
    /**
     * @brief Vector Create a Vector at (0, 0, 0)
     */
    Vector();

    /**
     * @brief Vector Create a Vector with the given values as strings
     * @param x
     * @param y
     * @param z
     */
    Vector(QString x, QString y, QString z);

    /**
     * @brief Vector Create a Vector with the given values
     * @param x
     * @param y
     * @param z
     */
    Vector(mpf_class x, mpf_class y, mpf_class z);

    /**
     * @brief Vector Create a Vector with the given values as doubles
     * @param x
     * @param y
     * @param z
     */
    Vector(double x, double y, double z);

    /**
     * @brief x Get the x component
     * @return
     */
    mpf_class x() const;

    /**
     * @brief y Get the y component
     * @return
     */
    mpf_class y() const;

    /**
     * @brief z Get the z component
     * @return
     */
    mpf_class z() const;

    /**
     * @brief setX Set the x component as a string
     * @param x
     */
    void setX(QString x);

    /**
     * @brief setY Set the y component as a string
     * @param y
     */
    void setY(QString y);

    /**
     * @brief setZ Set the z component as a string
     * @param z
     */
    void setZ(QString z);

    /**
     * @brief setX Set the x component
     * @param x
     */
    void setX(mpf_class x);

    /**
     * @brief setY Set the y component
     * @param y
     */
    void setY(mpf_class y);

    /**
     * @brief setZ Set the z component
     * @param z
     */
    void setZ(mpf_class z);

    /**
     * @brief length Get the length of the Vector defined as sqrt(x^2, y^2, z^2)
     * @return
     */
    mpf_class  length() const;

    /**
     * @brief normalize Get a normalized copy of the Vector defined as V/|V|
     * @return
     */
    Vector normalized() const;

    // Arithmetic Operators
    Vector operator+(const Vector& right) const;
    Vector operator-(const Vector& right) const;
    Vector operator*(const mpf_class& factor) const;
    Vector operator/(const mpf_class& factor) const;

    // Compound Operators
    Vector& operator+=(const Vector& right);
    Vector& operator-=(const Vector& right);
    Vector& operator*=(const mpf_class& right);
    Vector& operator/=(const mpf_class& right);

    // Compairson Operators
    bool operator==(const Vector& right) const;
    bool operator!=(const Vector& right) const;


private:
    mpf_class x_;
    mpf_class y_;
    mpf_class z_;

    /**
     * @brief multiplyByFactor Return the Vector that has been multiplied by a factor
     * @param factor
     * @return
     */
    Vector multiplyByFactor(const mpf_class& factor) const;

    /**
     * @brief divideByFactor Return the Vector that has been divided by a factor
     * @param factor
     * @return
     */
    Vector divideByFactor(const mpf_class& factor) const;

    /**
     * @brief add Return the Vector that has been added to
     * @param vector
     * @return
     */
    Vector add(const Vector& vector) const;

    /**
     * @brief sub Return the vector that has been subtracted from
     * @param vector
     * @return
     */
    Vector sub(const Vector& vector) const;

};

#endif // VECTOR_H
