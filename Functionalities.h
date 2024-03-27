#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include"EVCar.h"
#include"ICECar.h"
#include"NoDataFound.h"
#include"InValidInput.h"
#include<memory>
#include<vector>
#include<variant>
#include<thread>
#include<mutex>
#include<future>
#include<algorithm>
#include<numeric>
#include<optional>

using ICEPointer = std::shared_ptr<ICECar>;
using EVPointer = std::shared_ptr<EVCar>;

using CarPointer = std::variant<ICEPointer, EVPointer>;
using CarContainer = std::vector<CarPointer>;

void createObjects(CarContainer& data);

CarContainer FindAndReturnCarInstance(CarContainer& data, std::variant<ChassisType,FuelType> type, int n);

bool AllAbove30Capacity(CarContainer& data);

int CountOfEVCar(CarContainer& data);

std::optional<ChassisType> FindChassisType(CarContainer& data, int id);

float TotalBatteryCapacity(CarContainer& data);

void DisplayNthInstanceOfDataCgit iontainer(CarContainer& data, int n);

#endif // FUNCTIONALITIES_H
