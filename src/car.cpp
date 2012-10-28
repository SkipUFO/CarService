#include "car.h"

Car::Car(int brand, QString stateRegistrationNumber, QObject *parent) : QObject(parent)
{
    m_brand = brand;
    m_stateRegistrationNumber = stateRegistrationNumber;
}
Car::Car(CarDefinition carDefinition, QObject *parent) : QObject(parent)
{
    m_brand = carDefinition.brand;
    m_stateRegistrationNumber = carDefinition.stateRegistrationNumber;
}

Car::Car(const Car &other) : QObject(other.parent())
{
    m_brand = other.m_brand;
    m_stateRegistrationNumber = other.m_stateRegistrationNumber;
}

Car::Car(Car &other) : QObject(other.parent())
{
    m_brand = other.m_brand;
    m_stateRegistrationNumber = other.m_stateRegistrationNumber;
}

Car::~Car()
{
    m_brand = 0;
    m_stateRegistrationNumber = "";
}

Car& Car::operator =(const Car &other)
{
    m_brand = other.m_brand;
    m_stateRegistrationNumber = other.m_stateRegistrationNumber;
    return *this;
}

void Car::setBrand(int brand)
{
    m_brand = brand;
}

int Car::brand()
{
    return m_brand;
}

void Car::setStateRegistrationNumber(QString stateRegistrationNumber)
{
    m_stateRegistrationNumber = stateRegistrationNumber;
}

QString Car::stateRegistrationNumber()
{
    return m_stateRegistrationNumber;
}

void Car::setCar(CarDefinition carDefinition)
{
    m_brand = carDefinition.brand;
    m_stateRegistrationNumber = carDefinition.stateRegistrationNumber;
}

void Car::setCar(int brand, QString stateRegistrationNumber)
{
    m_brand = brand;
    m_stateRegistrationNumber = stateRegistrationNumber;
}

CarDefinition Car::car()
{
    CarDefinition carDefinition;
    carDefinition.brand = m_brand;
    carDefinition.stateRegistrationNumber = stateRegistrationNumber();
    return carDefinition;
}

