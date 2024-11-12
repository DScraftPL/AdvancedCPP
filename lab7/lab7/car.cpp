#include "car.h"

Car::Car(const QString& make, const QString& model, const QString& year, const QString& vin)
    : m_make(make), m_model(model), m_year(year), m_vin(vin) {}
