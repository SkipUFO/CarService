#include <QtCore/QString>
#include <QtTest/QtTest>
#include "../CarService/car.h"
#include "../CarService/client.h"
#include "../CarService/clients.h"

#define TEST

class ClientsTest : public QObject
{
    Q_OBJECT

public:
    ClientsTest();

private Q_SLOTS:
    void initTestCase();
    void cleanupTestCase();
    void testCaseCreateClientsWithoutInitialValues();
    void testCaseCreateClientsWithInitialValues();
    void testCaseAddClient();
    void testCaseAddClientByClientDefinition();
    void testCaseAddClients();
    void testCaseDeleteClient();
    void testCaseRequestAddClient();
    void testCaseRequestAddClients();
    void testCaseRequestAddClientCarOrCars();
    void testCaseRequestDeleteCars();
    void testCaseRequestDeleteClient();
    void testCaseRequestGetAllClientsData();
    void testCaseRequestGetClientData();
    void testCaseRequestUpdateClient();
    void testCaseRequestUpdateClientCar();
};

ClientsTest::ClientsTest()
{
}

void ClientsTest::initTestCase()
{
}

void ClientsTest::cleanupTestCase()
{
}

void ClientsTest::testCaseCreateClientsWithoutInitialValues()
{
    Clients clients;
    QCOMPARE(clients.clientsCount(), 0);    
}

void ClientsTest::testCaseCreateClientsWithInitialValues()
{
    QList<ClientDefinition> clientsDefinition;
    ClientDefinition clientDefinition;
    CarDefinition carDefinition;

    clientDefinition.fio = QString("Синицын И.М.");
    carDefinition.brand = 1;
    carDefinition.stateRegistrationNumber = QString("М936НН/96");
    clientDefinition.cars << carDefinition;
    carDefinition.brand = 2;
    carDefinition.stateRegistrationNumber = QString("С685АН/96");
    clientDefinition.cars << carDefinition;
    clientsDefinition << clientDefinition;

    clientDefinition.cars.clear();
    clientDefinition.fio = QString("Ногайдели М.А.");
    carDefinition.brand = 3;
    carDefinition.stateRegistrationNumber = QString("М720НН/96");
    clientDefinition.cars << carDefinition;
    clientsDefinition << clientDefinition;

    Clients clients(clientsDefinition);
    QCOMPARE(clients.clientsCount(), 2);
    QVERIFY(clients.client(QString("Синицын И.М.")) != NULL);
    QVERIFY(clients.client(QString("Синицын И.М."))->carCount() == 2);
    QVERIFY(clients.client(QString("Синицын И.М."))->car(1, "М936НН/96") != NULL);
    QVERIFY(clients.client(QString("Синицын И.М."))->car(2, "С685АН/96") != NULL);
    QVERIFY(clients.client(QString("Ногайдели М.А.")) != NULL);
    QVERIFY(clients.client(QString("Ногайдели М.А."))->carCount() == 1);
    QVERIFY(clients.client(QString("Ногайдели М.А."))->car(3, "М720НН/96") != NULL);
}

void ClientsTest::testCaseAddClient()
{
    Clients clients;
    QList<CarDefinition> cars;
    CarDefinition car;
    car.brand = 1;
    car.stateRegistrationNumber = QString("М936НН/96");
    cars << car;
    car.brand = 2;
    car.stateRegistrationNumber = QString("С685АН/96");
    cars << car;
    clients.addClient(QString("Синицын И.М."), cars);
    QCOMPARE(clients.clientsCount(), 1);
    QVERIFY(clients.client(QString("Синицын И.М.")) != NULL);
    QVERIFY(clients.client(QString("Синицын И.М."))->carCount() == 2);
    QVERIFY(clients.client(QString("Синицын И.М."))->car(1, "М936НН/96") != NULL);
    QVERIFY(clients.client(QString("Синицын И.М."))->car(2, "С685АН/96") != NULL);
}

void ClientsTest::testCaseAddClientByClientDefinition()
{
    Clients clients;
    CarDefinition car;
    ClientDefinition clientDefinition;
    car.brand = 1;
    car.stateRegistrationNumber = QString("М936НН/96");
    clientDefinition.cars << car;
    car.brand = 2;
    car.stateRegistrationNumber = QString("С685АН/96");
    clientDefinition.cars << car;
    clientDefinition.fio = QString("Синицын И.М.");
    clients.addClient(clientDefinition);
    QCOMPARE(clients.clientsCount(), 1);
    QVERIFY(clients.client(QString("Синицын И.М.")) != NULL);
    QVERIFY(clients.client(QString("Синицын И.М."))->carCount() == 2);
    QVERIFY(clients.client(QString("Синицын И.М."))->car(1, "М936НН/96") != NULL);
    QVERIFY(clients.client(QString("Синицын И.М."))->car(2, "С685АН/96") != NULL);
}

void ClientsTest::testCaseAddClients()
{
    Clients clients;
    QList<ClientDefinition> clientsDefinition;
    ClientDefinition clientDefinition;
    CarDefinition carDefinition;

    clientDefinition.fio = QString("Синицын И.М.");
    carDefinition.brand = 1;
    carDefinition.stateRegistrationNumber = QString("М936НН/96");
    clientDefinition.cars << carDefinition;
    carDefinition.brand = 2;
    carDefinition.stateRegistrationNumber = QString("С685АН/96");
    clientDefinition.cars << carDefinition;
    clientsDefinition << clientDefinition;

    clientDefinition.cars.clear();
    clientDefinition.fio = QString("Ногайдели М.А.");
    carDefinition.brand = 3;
    carDefinition.stateRegistrationNumber = QString("М720НН/96");
    clientDefinition.cars << carDefinition;
    clientsDefinition << clientDefinition;

    clients.addClients(clientsDefinition);

    QCOMPARE(clients.clientsCount(), 2);
    QVERIFY(clients.client(QString("Синицын И.М.")) != NULL);
    QVERIFY(clients.client(QString("Синицын И.М."))->carCount() == 2);
    QVERIFY(clients.client(QString("Синицын И.М."))->car(1, "М936НН/96") != NULL);
    QVERIFY(clients.client(QString("Синицын И.М."))->car(2, "С685АН/96") != NULL);
    QVERIFY(clients.client(QString("Ногайдели М.А.")) != NULL);
    QVERIFY(clients.client(QString("Ногайдели М.А."))->carCount() == 1);
    QVERIFY(clients.client(QString("Ногайдели М.А."))->car(3, "М720НН/96") != NULL);
}

void ClientsTest::testCaseDeleteClient()
{
    Clients clients;
    QList<ClientDefinition> clientsDefinition;
    ClientDefinition clientDefinition;
    CarDefinition carDefinition;

    clientDefinition.fio = QString("Синицын И.М.");
    carDefinition.brand = 1;
    carDefinition.stateRegistrationNumber = QString("М936НН/96");
    clientDefinition.cars << carDefinition;
    carDefinition.brand = 2;
    carDefinition.stateRegistrationNumber = QString("С685АН/96");
    clientDefinition.cars << carDefinition;
    clientsDefinition << clientDefinition;

    clientDefinition.cars.clear();
    clientDefinition.fio = QString("Ногайдели М.А.");
    carDefinition.brand = 3;
    carDefinition.stateRegistrationNumber = QString("М720НН/96");
    clientDefinition.cars << carDefinition;
    clientsDefinition << clientDefinition;

    clients.addClients(clientsDefinition);

    clients.deleteClient(clientsDefinition.at(0).fio);
    QVERIFY(clients.client(QString("Ногайдели М.А.")) != NULL);
    QVERIFY(clients.client(QString("Ногайдели М.А."))->carCount() == 1);
    QVERIFY(clients.client(QString("Ногайдели М.А."))->car(3, "М720НН/96") != NULL);
}

void ClientsTest::testCaseRequestAddClient() {
    QString xml =
            "<?xml version=\"1.0\" encoding=\"utf-8\"?><!DOCTYPE clients_request> \
             <request function=\"addClient\"> \
                <data> \
                    <client fio=\"Синицын И.М.\"> \
                        <car brand=\"1\" stateRegistrationNumber=\"М936НН/96\"/> \
                    </client> \
                </data> \
             </request>";
    QDomDocument doc;
    doc.setContent(xml);

    Clients clients;
    clients.request(doc);

    QVERIFY(clients.clientsCount() == 1);
    QVERIFY(clients.client(QString("Синицын И.М.")) != NULL);
    QVERIFY(clients.client(QString("Синицын И.М."))->carCount() == 1);
    QVERIFY(clients.client(QString("Синицын И.М."))->car(1, "М936НН/96") != NULL);

}

void ClientsTest::testCaseRequestAddClients() {

    QString xml =
            "<?xml version=\"1.0\" encoding=\"utf-8\"?><!DOCTYPE clients_request> \
             <request function=\"addClient\"> \
                <data> \
                    <client fio=\"Синицын И.М.\"> \
                        <car brand=\"1\" stateRegistrationNumber=\"М936НН/96\"/> \
                    </client> \
                    <client fio=\"Ногайдели М.А.\"> \
                        <car brand=\"1\" stateRegistrationNumber=\"М720НН/96\"/> \
                    </client> \
                </data> \
             </request>";
    QDomDocument doc;
    doc.setContent(xml);

    Clients clients;
    clients.request(doc);

    QVERIFY(clients.clientsCount() == 2);
    QVERIFY(clients.client(QString("Синицын И.М.")) != NULL);
    QVERIFY(clients.client(QString("Ногайдели М.А.")) != NULL);

    QVERIFY(clients.client(QString("Синицын И.М."))->carCount() == 1);
    QVERIFY(clients.client(QString("Синицын И.М."))->car(1, "М936НН/96") != NULL);

    QVERIFY(clients.client(QString("Ногайдели М.А."))->carCount() == 1);
    QVERIFY(clients.client(QString("Ногайдели М.А."))->car(1, "М720НН/96") != NULL);
}


void ClientsTest::testCaseRequestAddClientCarOrCars()
{
    QString xml =
            "<?xml version=\"1.0\" encoding=\"utf-8\"?><!DOCTYPE clients_request> \
             <request function=\"addClient\"> \
                <data> \
                    <client fio=\"Синицын И.М.\"> \
                        <car brand=\"1\" stateRegistrationNumber=\"М936НН/96\"/> \
                        <car brand=\"2\" stateRegistrationNumber=\"С685АН/96\"/> \
                    </client> \
                </data> \
             </request>";
    QDomDocument doc;
    doc.setContent(xml);

    Clients clients;
    clients.request(doc);

    xml =       "<?xml version=\"1.0\" encoding=\"utf-8\"?><!DOCTYPE clients_request> \
                 <request function=\"addCar\"> \
                    <data> \
                        <client fio=\"Синицын И.М.\"> \
                            <car brand=\"2\" stateRegistrationNumber=\"С685МН/96\"/> \
                        </client> \
                    </data> \
                 </request>";
    doc.setContent(xml);
    clients.request(doc);

    QVERIFY(clients.clientsCount() == 1);
    QVERIFY(clients.client(QString("Синицын И.М.")) != NULL);
    QVERIFY(clients.client(QString("Синицын И.М."))->carCount() == 3);
    QVERIFY(clients.client(QString("Синицын И.М."))->car(1, "М936НН/96") != NULL);
    QVERIFY(clients.client(QString("Синицын И.М."))->car(2, "С685АН/96") != NULL);
    QVERIFY(clients.client(QString("Синицын И.М."))->car(2, "С685МН/96") != NULL);

    xml =       "<?xml version=\"1.0\" encoding=\"utf-8\"?><!DOCTYPE clients_request> \
                 <request function=\"addCar\"> \
                    <data> \
                        <client fio=\"Синицын И.М.\"> \
                            <car brand=\"2\" stateRegistrationNumber=\"С685НН/96\"/> \
                            <car brand=\"3\" stateRegistrationNumber=\"С686НН/96\"/> \
                        </client> \
                    </data> \
                 </request>";
    doc.setContent(xml);
    clients.request(doc);

    QVERIFY(clients.clientsCount() == 1);
    QVERIFY(clients.client(QString("Синицын И.М.")) != NULL);
    QVERIFY(clients.client(QString("Синицын И.М."))->carCount() == 5);
    QVERIFY(clients.client(QString("Синицын И.М."))->car(1, "М936НН/96") != NULL);
    QVERIFY(clients.client(QString("Синицын И.М."))->car(2, "С685АН/96") != NULL);
    QVERIFY(clients.client(QString("Синицын И.М."))->car(2, "С685МН/96") != NULL);
    QVERIFY(clients.client(QString("Синицын И.М."))->car(2, "С685НН/96") != NULL);
    QVERIFY(clients.client(QString("Синицын И.М."))->car(3, "С686НН/96") != NULL);

};

void ClientsTest::testCaseRequestDeleteCars()
{
    QString xml =
            "<?xml version=\"1.0\" encoding=\"utf-8\"?><!DOCTYPE clients_request> \
             <request function=\"addClient\"> \
                <data> \
                    <client fio=\"Синицын И.М.\"> \
                        <car brand=\"1\" stateRegistrationNumber=\"М936НН/96\"/> \
                        <car brand=\"2\" stateRegistrationNumber=\"С685АН/96\"/> \
                    </client> \
                </data> \
             </request>";
    QDomDocument doc;
    doc.setContent(xml);

    Clients clients;
    clients.request(doc);

    xml = "<?xml version=\"1.0\" encoding=\"utf-8\"?><!DOCTYPE clients_request> \
                 <request function=\"deleteCars\"> \
                    <data> \
                        <client fio=\"Синицын И.М.\"> \
                            <car brand=\"1\" stateRegistrationNumber=\"М936НН/96\"/> \
                        </client> \
                    </data> \
                 </request>";

    doc.setContent(xml);
    clients.request(doc);

    QVERIFY(clients.clientsCount() == 1);
    QVERIFY(clients.client(QString("Синицын И.М.")) != NULL);
    QVERIFY(clients.client(QString("Синицын И.М."))->carCount() == 1);
    QVERIFY(clients.client(QString("Синицын И.М."))->car(2, "С685АН/96") != NULL);

};

void ClientsTest::testCaseRequestDeleteClient()
{
    QString xml = "<?xml version=\"1.0\" encoding=\"utf-8\"?><!DOCTYPE clients_request> \
                 <request function=\"addClient\"> \
                    <data> \
                        <client fio=\"Синицын И.М.\"> \
                            <car brand=\"2\" stateRegistrationNumber=\"С685НН/96\"/> \
                            <car brand=\"3\" stateRegistrationNumber=\"С686НН/96\"/> \
                        </client> \
                    </data> \
                 </request>";
    QDomDocument doc;
    doc.setContent(xml);

    Clients clients;
    clients.request(doc);

    xml = "<?xml version=\"1.0\" encoding=\"utf-8\"?><!DOCTYPE clients_request> \
                     <request function=\"deleteClient\"> \
                        <data> \
                            <client fio=\"Синицын И.М.\"> \
                                <car brand=\"2\" stateRegistrationNumber=\"С685НН/96\"/> \
                            </client> \
                        </data> \
                     </request>";

};

void ClientsTest::testCaseRequestGetAllClientsData()
{
    QString xml =
            "<!DOCTYPE clients_request> \
             <request function=\"addClient\"> \
                <data> \
                    <client fio=\"Синицын И.М.\"> \
                        <car brand=\"1\" stateRegistrationNumber=\"М936НН/96\"/> \
                    </client> \
                    <client fio=\"Ногайдели М.А.\"> \
                        <car brand=\"1\" stateRegistrationNumber=\"М720НН/96\"/> \
                    </client> \
                </data> \
             </request>";
    QDomDocument doc;
    doc.setContent(xml);

    Clients clients;
    clients.request(doc);

    xml = "<?xml version=\"1.0\" encoding=\"utf-8\"?><!DOCTYPE clients_request> \
            <request function=\"allClientsData\"";
    doc.setContent(xml);


    QVERIFY(clients.request(doc) == xml);
};

void ClientsTest::testCaseRequestGetClientData() {};
void ClientsTest::testCaseRequestUpdateClient() {};
void ClientsTest::testCaseRequestUpdateClientCar() {};

QTEST_APPLESS_MAIN(ClientsTest)

#include "tst_clientstest.moc"

