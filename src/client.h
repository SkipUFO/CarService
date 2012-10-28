#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include "car.h"


/** \class Client
  \brief Класс управления данными клиента
  Добавление, редактирование ФИО. Добавление, редактирование, удаление автомобилей
  */

/** \struct ClientDefinition
  \brief Структура с клиентами
  */
struct ClientDefinition
{
    /** \brief ФИО клиента */
    QString fio;
    /** \brief Список описаний автомобилей */
    QList<CarDefinition> cars;
};

class Client : public QObject
{
    Q_OBJECT
private:
    /** \brief ФИО клиента */
    QString m_fio;
    /** \brief Список автомобилей клиента */
    QList<Car> m_cars;
public:
    /** \brief Конструктор класса
      \fn Client(QString fio = "", QList<CarDefinition> cars = QList<CarDefinition>(), QObject *parent = 0)
      \param QString fio ФИО клиента
      \param QList<CarDefinition> cars автомобили клиента
      */
    Client(QString fio = "", QList<CarDefinition> cars = QList<CarDefinition>(), QObject *parent = 0);
    /** \brief Конструктор класса
     \fn Client(const Client& other)
     \param const Client& other Ссылка на экземпляр класса Client
     */
    Client(const Client& other);
    /** \brief Конструктор класса
     \fn Client(Client& other)
     \param Client& other Ссылка на экземпляр класса Client
     */
    Client(Client& other);
    /** \brief Деструктор класса */
    ~Client();
    /** \brief Оператор присваивания */
    Client& operator =(const Client &other);
    /** \brief Setter ФИО клиента
      \fn void setFio(QString fio)
      \param QString fio ФИО клиента
      */
    void setFio(QString fio);
    /** \brief Getter ФИО клиента
      \fn QString fio()
      \return ФИО клиента
      */
    QString fio();
    /** \brief Функция добавления автомобиля
      \fn void addCar(CarDefinition carDefinition)
      \param CarDefinition carDefinition Описание автомобиля
      */
    void addCar(CarDefinition carDefinition);
    /** \brief Функция добавления автомобиля
      \fn void addCar(int brand, QString stateRegistrationNumber)
      \param int brand марка автомобиля
      \param QString stateRegistrationNumber государственный решистрационный номер
      */
    void addCar(int brand, QString stateRegistrationNumber);
    /** \brief Функция добавления автомобилей
      \fn void addCars(QList<CarDefinition> cars)
      \param QList<CarDefinition> cars Список автомобилей
      */
    void addCars(QList<CarDefinition> cars);
    /** \brief Функция, возвращающая количество автомобилей клиента
      \fn int carCount()
      \return Количество автомобилей
      */
    int carCount();
    /** \brief Функция, возвращающая объект автомобиль
      \fn Car* car(int index)
      \param int index Индекс записи
      \return Car экземпляр класса Car
      */
    Car* car(int index);
    /** \brief Функция, возвращающая объект автомобиль
      \fn Car* car(CarDefinition carDefinition)
      \param CarDefinition carDefinition Описание автомобиля
      \return Car экземпляр класса Car
      */
    Car* car(CarDefinition carDefinition);
    /** \brief Функция, возвращающая объект автомобиль
      \fn Car* car(int brand, QString stateRegistrationNumber)
      \param int brand марка автомобиля
      \param QString stateRegistrationNumber государственный регистрационный номер
      \return Car экземпляр класса Car
      */
    Car* car(int brand, QString stateRegistrationNumber);
    /** \brief Функция удаления автомобиля
      \fn void deleteCar(CarDefinition carDefinition)
      \param CarDefinition carDefinition Описание автомобиля
      */
    void deleteCar(CarDefinition carDefinition);
    /** \brief Функция удаления автомобиля
      \fn void deleteCar(int brand, QString stateRegistrationNumber)
      \param int brand марка автомобиля
      \param QString stateRegistrationNumber государственный регистрационный номер
      */
    void deleteCar(int brand, QString stateRegistrationNumber);
    /** \brief Функция удаления всех автомобилей
      \fn void deleteCars()
      */
    void deleteCars();
signals:
    
public slots:
    
};

#endif // CLIENT_H
