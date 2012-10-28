#ifndef CAR_H
#define CAR_H

#include <QObject>

/** \class Car
  \brief Класс Автомобиль
  Класс управляет добавлением, удалением, редактированием информацией об автомобилях
  */

/** \struct CarDefinition
  \brief Структура автомобиля
  */
struct CarDefinition
{
    /** \brief Ссылка на марку автомобиля */
    int brand;
    /** \brief Государственный регистрационный номер */
    QString stateRegistrationNumber;
};

class Car : public QObject
{
    Q_OBJECT
private:
    /** \brief Ссылка на марку автомобиля */
    int m_brand;
    /** \brief Государственный регистрационный номер */
    QString m_stateRegistrationNumber;
public:
    /** \brief Конструктор класса
    \fn Car(int brand = 0, QString stateRegistrationNumber = "", QObject *parent = 0)
    \param int brand Ссылка на марку автомобиля
    \param QString stateRegistationNumber Государственный регистрационный номер
    */
    Car(int brand = 0, QString stateRegistrationNumber = "", QObject *parent = 0);
    /** \brief Конструктор класса
    \fn Car(CarDefinition carDefinition, QObject *parent = 0)
    \param CarDefinition carDefinition Описание автомобиля
    */
    Car(CarDefinition carDefinition, QObject *parent = 0);
    /** \brief Конструктор класса
      \fn Car(const Car &other)
      \param const Car &other Ссылка на экземпляр класса Car
      */
    Car(const Car &other);
    /** \brief Конструктор класса
      \fn Car(Car &other)
      \param Car &other Ссылка на экземпляр класса Car
      */
    Car(Car &other);
    /** \brief Деструктор класса */
    ~Car();
    /** \brief Оператор присваивания */
    Car& operator =(const Car &other);
    /** \brief Setter марки автомобиля
      \fn void setBrand(int brand)
      \param int brand Ссылка на марку автомобиля
      */
    void setBrand(int brand);
    /** \brief Getter марки автомобиля
      \fn int brand()
      \return int Ссылка на марку автомобиля
      */
    int brand();
    /** \brief Setter государственного регистрационного номера
      \fn void setStateRegistrationNumber(QString stateRegistrationNumber)
      \param QString stateRegistrationNumber Государственный регистрационный номер
      */
    void setStateRegistrationNumber(QString stateRegistrationNumber);
    /** \brief Getter государственного регистрационного номера
      \fn QString stateRegistrationNumber()
      \return QString Государственный регистрационный номер
      */
    QString stateRegistrationNumber();
    /** \brief Setter автомобиля
      \fn void setCar(CarDefinition carDefinition)
      \param CarDefinition carDefinition Описание автомобиля
      */
    void setCar(CarDefinition carDefinition);
    /** \brief Setter автомобиля
      \fn void setCar(int brand, QString stateRegistrationNumber)
      \param int Ссылка на марку автомобиля
      \param QString Государственный регистрационный номер
      */
    void setCar(int brand, QString stateRegistrationNumber);
    /** \brief Getter автомобиля
      \fn CarDefinition car()
      \return CarDefinition carDefinition Описание автомобиля
      */
    CarDefinition car();

signals:
    
public slots:
    
};

#endif // CAR_H
