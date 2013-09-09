#include "testvector.h"

TestVector::TestVector()
{
}

void TestVector::testVectorLength()
{
    Vector v(0,0,0);

    mpf_class got = v.length();
    mpf_class expected = 0;

    QVERIFY(got == expected);
}

void TestVector::testVectorLength2()
{
    Vector v(1,1,1);

    mpf_class got = v.length();
    mpf_class min = 1.731;
    mpf_class max = 1.733;

    QVERIFY((got > min) && (got < max));
}

void TestVector::testNormalized()
{
    Vector v(0,0,0);

    Vector norm = v.normalized();
    Vector expected(0,0,0);

    QVERIFY(norm == expected);
}

void TestVector::testNormalized2()
{
    Vector v(1,1,1);

    Vector norm = v.normalized();
    Vector min(0.576,0.576,0.576);
    Vector max(0.578,0.578,0.578);


    QVERIFY((norm.x() > min.x()) && (norm.x() < max.x()));
    QVERIFY((norm.y() > min.y()) && (norm.y() < max.y()));
    QVERIFY((norm.z() > min.z()) && (norm.z() < max.z()));
}

void TestVector::TestAdd()
{
    Vector v(1,1,1);
    Vector v2(1,1,1);

    Vector v3 = v + v2;
    Vector expected(2,2,2);

    QVERIFY(v3 == expected);
}

void TestVector::TestSub()
{
    Vector v(1,1,1);
    Vector v2(1,1,1);

    Vector v3 = v - v2;
    Vector expected(0,0,0);

    QVERIFY(v3 == expected);
}

void TestVector::TestMultiply()
{
    Vector v(1,1,1);

    Vector v2 = v*2;
    Vector expected(2,2,2);

    QVERIFY(v2 == expected);
}

void TestVector::TestDivide()
{
    Vector v(4,4,4);

    Vector v2 = v/2;
    Vector expected(2,2,2);

    QVERIFY(v2 == expected);
}

void TestVector::TestCompoundAdd()
{
    Vector v(1,1,1);

    Vector v2(1,1,1);
    v2 += v;
    Vector expected(2,2,2);

    QVERIFY(v2 == expected);
}

void TestVector::TestCompoundSub()
{
    Vector v(1,1,1);

    Vector v2(1,1,1);
    v2 -= v;
    Vector expected(0,0,0);

    QVERIFY(v2 == expected);
}

void TestVector::TestCompoundMultiply()
{
    Vector v(2,2,2);

    v *= 4;
    Vector expected(8,8,8);

    QVERIFY(v == expected);
}

void TestVector::TestCompoundDivide()
{
    Vector v(4,4,4);

    v /= 2;
    Vector expected(2,2,2);

    QVERIFY(v == expected);
}

void TestVector::TestEquals()
{
    Vector v(1,1,1);
    Vector v2(1,1,1);

    QVERIFY(v == v2);
}

void TestVector::TestNotEquals()
{
    Vector v(1,1,1);
    Vector v2(2,2,2);

    QVERIFY(v != v2);
}



