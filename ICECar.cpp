#include "ICECar.h"
std::ostream &operator<<(std::ostream &os, const ICECar &rhs) {
    os << "_id: " << rhs._id
       << " _fuelType: " << static_cast<int>(rhs._fuelType)
       << " _fuelTankCapacity: " << rhs._fuelTankCapacity;
    return os;
}
ICECar::ICECar(int id, FuelType type, unsigned int tank)
    : _id(id), _fuelType(type), _fuelTankCapacity(tank)
{
}
