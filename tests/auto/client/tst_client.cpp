#include <QtCore/QString>
#include <QtTest/QtTest>
#include "../../../src/client.h"

class ClientTest : public QObject
{
    Q_OBJECT

public:
    ClientTest();

private Q_SLOTS:
    void initTestCase();
    void cleanupTestCase();
    void testCaseCreateClientWithoutInitialValues();
    void testCaseCreateClientWithInitialValues();
    void testCaseCreateClientWithInitialValuesSomeCars();
    void testCaseDeleteCarsByName();
    void testCaseDeleteCars();
    void testCaseCreateByOtherClientObject();
    void testCaseCreateByOperatorAssignment();
    void testCaseAddCars();
};

ClientTest::ClientTest()
{
}

void ClientTest::initTestCase()
{
}

void ClientTest::cleanupTestCase()
{
}

void ClientTest::testCaseCreateClientWithoutInitialValues()
{
    Client client;
    QVERIFY(client.fio() == "");
    QVERIFY(client.carCount() == 0);
}
void ClientTest::testCaseCreateClientWithInitialValues()
{
    QList<CarDefinition> cars;
    CarDefinition car;
    car.brand = 1;
    car.stateRegistrationNumber = QString("М936НН/96");
    cars << car;
    Client client(QString("Синицын И.М."), cars);
    QCOMPARE(client.fio(), QString("Синицын И.М."));
    QVERIFY(client.fio() != QString("Синицын И.А."));
    QCOMPARE(client.carCount(), 1);
    QVERIFY(client.car(0) != NULL);
    QVERIFY(client.car(car) != NULL);
    QVERIFY(client.car(car.brand, car.stateRegistrationNumber) != NULL);
}

void ClientTest::testCaseCreateClientWithInitialValuesSomeCars()
{
    QList<CarDefinition> cars;
    CarDefinition car;
    car.brand = 1;
    car.stateRegistrationNumber = QString("М936НН/96");
    cars << car;
    car.brand = 2;
    car.stateRegistrationNumber = QString("С685АН/96");
    cars << car;
    Client client(QString("Синицын И.М."), cars);
    QCOMPARE(client.fio(), QString("Синицын И.М."));
    QCOMPARE(client.carCount(), 2);
    QVERIFY(client.car(cars.at(0)) != NULL);
    QVERIFY(client.car(cars.at(1)) != NULL);
}

void ClientTest::testCaseDeleteCarsByName()
{
    QList<CarDefinition> cars;
    CarDefinition car;
    car.brand = 1;
    car.stateRegistrationNumber = QString("М936НН/96");
    cars << car;
    car.brand = 2;
    car.stateRegistrationNumber = QString("С685АН/96");
    cars << car;
    Client client(QString("Синицын И.М."), cars);
    QCOMPARE(client.fio(), QString("Синицын И.М."));
    QCOMPARE(client.carCount(), 2);
    client.deleteCar(cars.at(0));
    QCOMPARE(client.carCount(), 1);
    QVERIFY(client.car(cars.at(1)) != NULL);
    client.deleteCar(cars.at(1).brand, cars.at(1).stateRegistrationNumber);
    QCOMPARE(client.carCount(), 0);
}

void ClientTest::testCaseDeleteCars()
{
    QList<CarDefinition> cars;
    CarDefinition car;
    car.brand = 1;
    car.stateRegistrationNumber = QString("М936НН/96");
    cars << car;
    car.brand = 2;
    car.stateRegistrationNumber = QString("С685АН/96");
    cars << car;
    Client client(QString("Синицын И.М."), cars);
    QCOMPARE(client.fio(), QString("Синицын И.М."));
    QCOMPARE(client.carCount(), 2);
    client.deleteCars();
    QCOMPARE(client.carCount(), 0);
}

void ClientTest::testCaseCreateByOtherClientObject()
{
    QList<CarDefinition> cars;
    CarDefinition car;
    car.brand = 1;
    car.stateRegistrationNumber = QString("М936НН/96");
    cars << car;
    car.brand = 2;
    car.stateRegistrationNumber = QString("С685АН/96");
    cars << car;
    Client client1(QString("Синицын И.М."), cars);
    Client client2(client1);
    QCOMPARE(client1.fio(), client2.fio());
    QCOMPARE(client1.carCount(), client2.carCount());
    for(int i = 0; i < client1.carCount(); i++)
        QVERIFY(client2.car(client1.car(i)->brand(), client1.car(i)->stateRegistrationNumber()));
}

void ClientTest::testCaseCreateByOperatorAssignment()
{
    QList<CarDefinition> cars;
    CarDefinition car;
    car.brand = 1;
    car.stateRegistrationNumber = QString("М936НН/96");
    cars << car;
    car.brand = 2;
    car.stateRegistrationNumber = QString("С685АН/96");
    cars << car;
    Client client1(QString("Синицын И.М."), cars);
    Client client2 = client1;
    QCOMPARE(client1.fio(), client2.fio());
    QCOMPARE(client1.carCount(), client2.carCount());
    for(int i = 0; i < client1.carCount(); i++)
        QVERIFY(client2.car(client1.car(i)->brand(), client1.car(i)->stateRegistrationNumber()));
}

void ClientTest::testCaseAddCars()
{
    Client client(QString("Синицын И.М."));
    QList<CarDefinition> cars;
    CarDefinition car;
    car.brand = 1;
    car.stateRegistrationNumber = QString("М936НН/96");
    cars << car;
    car.brand = 2;
    car.stateRegistrationNumber = QString("С685АН/96");
    cars << car;
    client.addCars(cars);
    QCOMPARE(client.fio(), QString("Синицын И.М."));
    QCOMPARE(client.carCount(), 2);
    QVERIFY(client.car(cars.at(0)) != NULL);
    QVERIFY(client.car(cars.at(1)) != NULL);
}

QTEST_APPLESS_MAIN(ClientTest)

#include "tst_client.moc"

