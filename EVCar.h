#ifndef EVCAR_H
#define EVCAR_H

#include<iostream>
#include"ChassisType.h"

class EVCar
{
private:
    const int _id;
    const ChassisType _chassisType;
    float _batteryCapacity;
public:
    EVCar() = delete;
    EVCar(const EVCar&) = default;
    EVCar& operator=(const EVCar&) = delete;
    ~EVCar() = default;
    EVCar(EVCar&&) = delete;
    EVCar& operator=(EVCar&&) = delete;

    EVCar(int id, ChassisType type, float capaity);

    int id() const { return _id; }

    float batteryCapacity() const { return _batteryCapacity; }
    void setBatteryCapacity(float batteryCapacity) { _batteryCapacity = batteryCapacity; }

    ChassisType chassisType() const { return _chassisType; }

    friend std::ostream &operator<<(std::ostream &os, const EVCar &rhs);
};

#endif // EVCAR_H
