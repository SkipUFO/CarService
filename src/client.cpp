#include "client.h"

Client::Client(QString fio, QList<CarDefinition> cars, QObject *parent) : QObject(parent)
{
    m_fio = fio;
    CarDefinition car;
    foreach (car, cars) {
        addCar(car);
    }
}

Client::Client(const Client &other) : QObject(other.parent())
{
    m_fio = other.m_fio;
    m_cars << other.m_cars;
}

Client::Client(Client &other) : QObject(other.parent())
{
    m_fio = other.m_fio;
    m_cars << other.m_cars;
}


Client& Client::operator =(const Client& other)
{
    m_fio = other.m_fio;
    m_cars.clear();
    m_cars << other.m_cars;
    return *this;
}

Client::~Client()
{
    m_cars.clear();
}

void Client::setFio(QString fio)
{
    m_fio = fio;
}

QString Client::fio()
{
    return m_fio;
}

void Client::addCar(CarDefinition carDefinition)
{
    Car car(carDefinition);
    m_cars.append(car);
}

void Client::addCar(int brand, QString stateRegistrationNumber)
{
    Car car(brand, stateRegistrationNumber);
    m_cars.append(car);
}

void Client::addCars(QList<CarDefinition> cars)
{
    CarDefinition carDefinition;
    foreach(carDefinition, cars)
        addCar(carDefinition);
}

int Client::carCount()
{
    return m_cars.size();
}

Car* Client::car(int index)
{
    if (index < carCount())
        return &m_cars[index];
    return NULL;
}

Car* Client::car(CarDefinition carDefinition)
{
    for(int i = 0; i < m_cars.size(); i++)
        if ((m_cars[i].brand() == carDefinition.brand)&&(m_cars[i].stateRegistrationNumber() == carDefinition.stateRegistrationNumber))
            return &m_cars[i];

    return NULL;
}

Car* Client::car(int brand, QString stateRegistrationNumber)
{
    for(int i = 0; i < m_cars.size(); i++)
        if ((m_cars[i].brand() == brand)&&(m_cars[i].stateRegistrationNumber() == stateRegistrationNumber))
            return &m_cars[i];

    return NULL;
}

void Client::deleteCar(CarDefinition carDefinition)
{
    for(int i = 0; i < m_cars.size(); i++)
        if ((m_cars[i].brand() == carDefinition.brand)&&(m_cars[i].stateRegistrationNumber() == carDefinition.stateRegistrationNumber)) {
            m_cars.removeAt(i);
            return;
        }
}

void Client::deleteCar(int brand, QString stateRegistrationNumber)
{
    for(int i = 0; i < m_cars.size(); i++)
        if ((m_cars[i].brand() == brand)&&(m_cars[i].stateRegistrationNumber() == stateRegistrationNumber)) {
            m_cars.removeAt(i);
            return;
        }
}

void Client::deleteCars()
{
    m_cars.clear();
}
