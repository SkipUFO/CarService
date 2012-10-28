#ifndef CLIENTS_H
#define CLIENTS_H

#include <QObject>
#include <QDomDocument>
#include "client.h"

#define NO_REQUEST_FUNCTION 1
#define REQUEST_COMPLETE 2
#define REQUEST_INCOMPLETE 3

/** \class Clients
  \brief Класс управления клиентами
  Добавление, удаление, редактирование клиентов. Получение полного списка клиентов, получение
  списка клиентов с автомобилями, получение списка зарегистрированных в системе автомобилей. Поиск
  клиента, поиск автомобиля
  */

class Clients : public QObject
{
    Q_OBJECT
private:
    /** \brief Список клиентов */
    QList<Client> m_clients;
    /** \brief Функция добавления клиента
      \fn bool addClient(QDomDocument doc)
      \param QDomDocument doc Описание клиента
      \return bool true, если xml обработан, false, если возникла какая-либо ошибка
      \note Формат xml-файла
      <request function = "addClient">
        <data>
          <client fio = "...">
            <car brand = "..." stateRegistrationNumber = "..." />
            <car brand = "..." stateRegistrationNumber = "..." />
            ...
          </client>
        </data>
      </request>
      */
    bool addClient(QDomDocument doc);
    /** \brief Функция добавления клиентов
      \fn void addClients(QDomDocument doc)
      \param QDomDocument Описание клиентов
      \note Формат xml-файла
      <request function = "addClient">
        <data>
          <client fio = "...">
            <car brand = "..." stateRegistrationNumber = "..." />
            <car brand = "..." stateRegistrationNumber = "..." />
            ...
          </client>
          <client fio = "...">
          ...
          </client>
          ...
        </data>
      </request>
      */
    bool addClients(QDomDocument doc);
    /** \brief Функция добавления клиента
      \fn bool deleteCars(QDomDocument doc)
      \param QDomDocument doc Описание клиента
      \return bool true, если xml обработан, false, если возникла какая-либо ошибка
      \note Формат xml-файла
      <request function = "deleteCars">
        <data>
          <client fio = "...">
            <car brand = "..." stateRegistrationNumber = "..." />
          </client>
        </data>
      </request>
      */
    bool deleteCars(QDomDocument doc);

public:
    /** \brief Конструктор класса
      \fn Clients(QList<ClientDefinition> clientDefinitions = QList<ClientDefinition>(), QObject *parent = 0)
      \param Список клиентов
      */
    explicit Clients(QList<ClientDefinition> clientDefinitions = QList<ClientDefinition>(), QObject *parent = 0);
    /** \brief Деструктор класса */
    ~Clients();
    /** \brief Функция добавления клиента
      \fn void addClient(QString fio, QList<CarDefinition> cars)
      \param QString fio ФИО клиента
      \param QList<CarDefinition> cars Список автомобилей клиента
      */
    void addClient(QString fio, QList<CarDefinition> cars);
    /** \brief Функция добавления клиента
      \fn void addClient(ClientDefinition clientDefinition)
      \param ClientDefinition clientDefinition Описание клиента
      \param QList<CarDefinition> cars Список автомобилей клиента
      */
    void addClient(ClientDefinition clientDefinition);
    /** \brief Функция добавления клиентов
      \fn void addClients(QList<ClientDefinition> clients)
      \param QList<ClientDefinition> clients Список клиентов с автомобилями
      */
    void addClients(QList<ClientDefinition> clients);    
    /** \brief Функция удаления клиентов
      \fn void deleteClient(QString fio)
      \param QString fio ФИО клиента
      */
    void deleteClient(QString fio);
    /** \brief Функция возвращает количество клиентов
      \fn int clientsCount()
      \return int Количество клиентов
      */
    int clientsCount();
    /** \brief Функция возвращает клиента
      \fn Client* client(int index)
      \param int index Индекс записи
      \return Client* Экземпляр класса клиент
      */
    Client* client(int index);
    /** \brief Функция возвращает клиента
      \fn Client* client(QString fio)
      \param QString fio ФИО клиента
      \return Client* Экземпляр класса клиент
      */
    Client* client(QString fio);
    /** \brief Функция добавления автомобиля
      \fn void addCar(QString fio, int brand, QString stateRegistrationNumber)
      \param QString fio ФИО клиента
      \param int brand Марка автомобиля
      \param QString stateRegistrationNumber Государственный регистрационный номер
      */
    void addCar(QString fio, int brand, QString stateRegistrationNumber);
    /** \brief Функция добавления автомобиля
      \fn void addCar(QString fio, CarDefinition carDefinition)
      \param QString fio ФИО клиента
      \param CarDefinition carDefinition Описание автомобиля
      */
    void addCar(QString fio, CarDefinition carDefinition);
    /** \brief Функция добавления автомобилей
      \fn void addCars(QString fio, QList<CarDefinition> carDefinitions)
      \param QString fio ФИО клиента
      \param QList<CarDefinition> carDefinitions Описание автомобилей
      */
    void addCars(QString fio, QList<CarDefinition> carDefinitions);
    /** \brief Функция удаления автомобиля
      \fn void deleteCar(QString fio, int brand, QString stateRegistrationNumber)
      \param QString fio ФИО клиента
      \param int brand Марка автомобиля
      \param QString stateRegistrationNumber Государственный регистрационный номер
      */
    void deleteCar(QString fio, int brand, QString stateRegistrationNumber);
    /** \brief Функция удаления автомобиля
      \fn void deleteCar(QString fio, CarDefinition carDefinition)
      \param QString fio ФИО клиента
      \param CarDefinition carDefinition Описание автомобиля
      */
    void deleteCar(QString fio, CarDefinition carDefinition);
    /** \brief Функция обработки входящих запросов
      \fn QDomDocument request(QDomDocument doc)
      \param QDomDocument doc Входящий запрос в виде xml
      \return QDomDocument Исходящий запрос в виде xml
      */
    QDomDocument request(QDomDocument doc);
signals:
    
public slots:
    
};

#endif // CLIENTS_H
