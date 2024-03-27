#include"EVCar.h"
std::ostream &operator<<(std::ostream &os, const EVCar &rhs) {
    os << "_id: " << rhs._id
       << " _chassisType: " << static_cast<int>(rhs._chassisType)
       << " _batteryCapacity: " << rhs._batteryCapacity;
    return os;
}

EVCar::EVCar(int id, ChassisType type, float capaity)
    : _id(id), _chassisType(type), _batteryCapacity(capaity)
{
}
