#include "clients.h"

Clients::Clients(QList<ClientDefinition> clientDefinitions, QObject *parent) : QObject(parent)
{
    addClients(clientDefinitions);
}

Clients::~Clients()
{
    for(int i = 0; i < m_clients.size(); i++)
        m_clients[i].deleteCars();
    m_clients.clear();
}

void Clients::addClient(ClientDefinition clientDefinition)
{
    if (client(clientDefinition.fio) == NULL)
        m_clients << Client(clientDefinition.fio, clientDefinition.cars, this->parent());
    else
        client(clientDefinition.fio)->addCars(clientDefinition.cars);
}

void Clients::addClient(QString fio, QList<CarDefinition> cars)
{
    if (client(fio) == NULL)
        m_clients << Client(fio, cars, this->parent());
    else
        client(fio)->addCars(cars);
}

bool Clients::addClient(QDomDocument doc)
{
    return addClients(doc);
}

bool Clients::addClients(QDomDocument doc)
{
    QDomNodeList clientList = doc.elementsByTagName("client");
    for (int i = 0; i < clientList.size(); i++) {
        ClientDefinition client;
        client.fio = clientList.at(i).toElement().attribute("fio");
        QDomNodeList carList = clientList.at(i).toElement().elementsByTagName("car");
        for (int j = 0; j < carList.size(); j++) {
            CarDefinition car;
            car.brand = carList.at(j).toElement().attribute("brand", "0").toInt();
            car.stateRegistrationNumber = carList.at(j).toElement().attribute("stateRegistrationNumber");
            client.cars << car;
        }

        addClient(client);
    }

    return true;
}

bool Clients::deleteCars(QDomDocument doc)
{
    QDomNodeList clientList = doc.elementsByTagName("client");
    for (int i = 0; i < clientList.size(); i++) {
        QString fio = clientList.at(i).toElement().attribute("fio");
        QDomNodeList carList = clientList.at(i).toElement().elementsByTagName("car");
        for (int j = 0; j < carList.size(); j++) {
            CarDefinition car;
            car.brand = carList.at(j).toElement().attribute("brand", "0").toInt();
            car.stateRegistrationNumber = carList.at(j).toElement().attribute("stateRegistrationNumber");
            deleteCar(fio, car);
        }
    }

    return true;
}

bool Clients::allClientsData(QDomDocument doc)
{
    return true;
}

void Clients::addClients(QList<ClientDefinition> clients)
{
    ClientDefinition clientDefinition;
    foreach(clientDefinition, clients)
        addClient(clientDefinition);
}

void Clients::deleteClient(QString fio)
{
    for (int i = 0; i < m_clients.size(); i++)
        if (m_clients[i].fio() == fio)
            m_clients.removeAt(i);
}

int Clients::clientsCount()
{
    return m_clients.size();
}

Client* Clients::client(int index)
{
    if (index < m_clients.size())
        return &m_clients[index];
    return NULL;
}

Client* Clients::client(QString fio)
{
    for (int i = 0; i < m_clients.size(); i++)
        if (m_clients[i].fio() == fio)
            return &m_clients[i];
    return NULL;
}

void Clients::deleteCar(QString fio, int brand, QString stateRegistrationNumber)
{
    for(int i = 0; i < m_clients.size(); i++)
        if (m_clients[i].fio() == fio)
            m_clients[i].deleteCar(brand, stateRegistrationNumber);
}

void Clients::deleteCar(QString fio, CarDefinition carDefinition)
{
    deleteCar(fio, carDefinition.brand, carDefinition.stateRegistrationNumber);
}

QDomDocument Clients::request(QDomDocument doc)
{
    QDomDocument reply("reply");
    QDomElement elReply = reply.createElement("status");
    reply.appendChild(elReply);
    QDomNodeList nodeList = doc.elementsByTagName("request");
    if (nodeList.size() == 0) {
        elReply.setAttribute("status", NO_REQUEST_FUNCTION);
    } else {
        for (int i = 0; i < nodeList.size(); i++) {
            if (nodeList.at(i).attributes().contains("function")) {
                if (nodeList.at(i).toElement().attribute("function", "") == "addClient") {
                    if (addClient(doc))
                        elReply.setAttribute("status", REQUEST_COMPLETE);
                    else
                        elReply.setAttribute("status", REQUEST_INCOMPLETE);
                } else if (nodeList.at(i).toElement().attribute("function", "") == "addClients") {
                    if (addClient(doc))
                        elReply.setAttribute("status", REQUEST_COMPLETE);
                    else
                        elReply.setAttribute("status", REQUEST_INCOMPLETE);
                } else if (nodeList.at(i).toElement().attribute("function", "") == "addCar") {
                    if (addClient(doc))
                        elReply.setAttribute("status", REQUEST_COMPLETE);
                    else
                        elReply.setAttribute("status", REQUEST_INCOMPLETE);
                } else if (nodeList.at(i).toElement().attribute("function", "") == "deleteCars") {
                    if (deleteCars(doc))
                        elReply.setAttribute("status", REQUEST_COMPLETE);
                    else
                        elReply.setAttribute("status", REQUEST_INCOMPLETE);
                } else if (nodeList.at(i).toElement().attribute("function", "") == "allClientsData") {
                    if (allClientsData(doc))
                        elReply.setAttribute("status", REQUEST_COMPLETE);
                    else
                        elReply.setAttribute("status", REQUEST_INCOMPLETE);
                }

            } else {
                elReply.setAttribute("status", NO_REQUEST_FUNCTION);
            }
        }
    }
    return reply;
}
