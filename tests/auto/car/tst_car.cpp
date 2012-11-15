#include <QtCore/QString>
#include <QtTest/QtTest>
#include "../../../src/car.h"

class CarTest : public QObject
{
    Q_OBJECT
    
public:
    CarTest();
    
private Q_SLOTS:
    void initTestCase();
    void cleanupTestCase();
    void testCaseCreateWithInitialValuesByBrandStateRegistrationNumber();
    void testCaseCreateWithInitialValuesByCarDefinition();
    void testCaseCreateWithoutInitialValues();
    void testCaseChangeBrand();
    void testCaseChangeStateRegistrationNumber();
    void testCaseChangeCarByCarDefinition();
    void testCaseChangeCarByBrandStateRegistrationNumber();
    void testCaseCreateByOtherCarObject();
    void testCaseCreateByOperatorAssignment();
};

CarTest::CarTest()
{
}

void CarTest::initTestCase()
{
}

void CarTest::cleanupTestCase()
{
}

void CarTest::testCaseCreateWithInitialValuesByBrandStateRegistrationNumber()
{
    Car car(1, "М936НН/96");
    QCOMPARE(car.brand(), 1);
    QCOMPARE(car.stateRegistrationNumber(), QString("М936НН/96"));
}

void CarTest::testCaseCreateWithInitialValuesByCarDefinition()
{
    CarDefinition carDefinition;
    carDefinition.brand = 1;
    carDefinition.stateRegistrationNumber = "М936НН/96";
    Car car(carDefinition);
    QCOMPARE(car.brand(), 1);
    QCOMPARE(car.stateRegistrationNumber(), QString("М936НН/96"));
}

void CarTest::testCaseCreateWithoutInitialValues()
{
    Car car;
    QCOMPARE(car.brand(), 0);
    QCOMPARE(car.stateRegistrationNumber(), QString(""));
}

void CarTest::testCaseChangeBrand()
{
    Car car;
    car.setBrand(2);
    QCOMPARE(car.brand(), 2);
}

void CarTest::testCaseChangeStateRegistrationNumber()
{
    Car car;
    car.setStateRegistrationNumber("М720НН/96");
    QCOMPARE(car.stateRegistrationNumber(), QString("М720НН/96"));
}

void CarTest::testCaseChangeCarByCarDefinition()
{
    Car car;
    car.setCar(1, "М936НН/96");
    QCOMPARE(car.brand(), 1);
    QCOMPARE(car.stateRegistrationNumber(), QString("М936НН/96"));
}

void CarTest::testCaseChangeCarByBrandStateRegistrationNumber()
{
    Car car;
    CarDefinition carDefinition;
    carDefinition.brand = 1;
    carDefinition.stateRegistrationNumber = "М936НН/96";
    car.setCar(carDefinition);
    QCOMPARE(car.car().brand, carDefinition.brand);
    QCOMPARE(car.car().stateRegistrationNumber, carDefinition.stateRegistrationNumber);
}

void CarTest::testCaseCreateByOtherCarObject()
{
    Car car1(1, "М936НН/96");
    Car car2(car1);
    QCOMPARE(car1.brand(), car2.brand());
    QCOMPARE(car1.stateRegistrationNumber(), car2.stateRegistrationNumber());
}

void CarTest::testCaseCreateByOperatorAssignment()
{
    Car car1(1, "М936НН/96");
    Car car2 = car1;
    //car2 = car1;
    QCOMPARE(car1.brand(), car2.brand());
    QCOMPARE(car1.stateRegistrationNumber(), car2.stateRegistrationNumber());
}

QTEST_APPLESS_MAIN(CarTest)

#include "tst_car.moc"
