#ifndef ICECAR_H
#define ICECAR_H

#include<iostream>
#include"FuelType.h"

class ICECar
{
private:
    const int _id;
    const FuelType _fuelType;
    unsigned int _fuelTankCapacity;

public:
    ICECar() = delete;
    ICECar(const ICECar&) = default;
    ICECar& operator=(const ICECar&) = delete;
    ~ICECar() = default;
    ICECar(ICECar&&) = delete;
    ICECar& operator=(ICECar&&) = delete;

    ICECar(int id, FuelType type, unsigned int tank);

    int id() const { return _id; }

    FuelType fuelType() const { return _fuelType; }

    unsigned int fuelTankCapacity() const { return _fuelTankCapacity; }
    void setFuelTankCapacity(unsigned int fuelTankCapacity) { _fuelTankCapacity = fuelTankCapacity; }

    friend std::ostream &operator<<(std::ostream &os, const ICECar &rhs);
};
#endif // ICECAR_H
