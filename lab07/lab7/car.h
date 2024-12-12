#ifndef CAR_H
#define CAR_H

#include <QString>

class Car {
public:
    Car(const QString& make, const QString& model, const QString& year, const QString& vin);

    QString make() const { return m_make; }
    QString model() const { return m_model; }
    int year() const { return m_year.toInt(); }
    QString yearString() const { return m_year; }
    QString vin() const { return m_vin; }

    bool isOlderThan(int year) const { return m_year.toInt() < year; }

private:
    QString m_make;
    QString m_model;
    QString m_year;
    QString m_vin;
};

#endif // CAR_H


