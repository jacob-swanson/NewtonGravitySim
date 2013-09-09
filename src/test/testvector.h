#ifndef TESTVECTOR_H
#define TESTVECTOR_H

#include <QtTest>
#include "../model/vector.h"

class TestVector : public QObject
{
    Q_OBJECT
public:
    TestVector();

private slots:
    void testVectorLength();
    void testVectorLength2();
    void testNormalized();
    void testNormalized2();
    void TestAdd();
    void TestSub();
    void TestMultiply();
    void TestDivide();
    void TestCompoundAdd();
    void TestCompoundSub();
    void TestCompoundMultiply();
    void TestCompoundDivide();
    void TestEquals();
    void TestNotEquals();


};

#endif // TESTVECTOR_H
