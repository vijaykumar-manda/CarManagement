#include "Functionalities.h"

void createObjects(CarContainer &data)
{

    data.emplace_back(
        std::make_shared<EVCar>(123, ChassisType::LADDER, 34));

    data.emplace_back(
        std::make_shared<EVCar>(123, ChassisType::LADDER, 23.0f));

    data.emplace_back(
        std::make_shared<EVCar>(456, ChassisType::TUBULAR, 45.0f));
    data.emplace_back(
        std::make_shared<EVCar>(789, ChassisType::LADDER, 32.0f));
    data.emplace_back(
        std::make_shared<ICECar>(1212, FuelType::PETROL, 56));
    data.emplace_back(
        std::make_shared<ICECar>(6767, FuelType::DIESEL, 100));
    data.emplace_back(
        std::make_shared<ICECar>(8989, FuelType::PETROL, 78));
    data.emplace_back(
        std::make_shared<EVCar>(9000, ChassisType::TUBULAR, 23));
}

CarContainer FindAndReturnCarInstance(CarContainer &data, std::variant<ChassisType, FuelType> type, int n)
{
    // return null if not found
    if (data.empty())
    {
        throw NoDataFound("No data found");
    }
    if (n < 0 || n > data.size())
    {
        throw InValidInput("N is not invalid");
    }

    CarContainer result;

    int count{0};
    for (auto &car : data)
    {
        if (std::holds_alternative<ChassisType>(type))
        {
            if (std::holds_alternative<ICEPointer>(car))
            {
                result.emplace_back(car);
                count++;
                if (count == n)
                {
                    break;
                }
            }
        }
        else
        {
            if (std::holds_alternative<EVPointer>(car))
            {
                result.emplace_back(car);
                count++;
                if (count == n)
                {
                    break;
                }
            }
        }
    }

    return result;
}

bool AllAbove30Capacity(CarContainer &data)
{
    // return null if not found
    if (data.empty())
    {
        throw NoDataFound("No data found");
    }

    // find if all are above 30
    bool answer{true};
    for (auto &car : data)
    {
        if (std::holds_alternative<ICEPointer>(car))
        {
            auto temp = std::get<ICEPointer>(car);
            if (temp.get()->fuelTankCapacity() < 30)
            {
                answer = false;
                break;
            }
        }
    }
    return answer;
}

int CountOfEVCar(CarContainer &data)
{

    // return null if not found
    if (data.empty())
    {
        throw NoDataFound("No data found");
    }

    // find count
    int count = std::accumulate(data.begin(), data.end(), 0,
                                [](int total, const CarPointer &car)
                                {
                                    if (std::holds_alternative<EVPointer>(car))
                                    {
                                        total++;
                                    }
                                    return total;
                                });
    return count;
}

std::optional<ChassisType> FindChassisType(CarContainer &data, int id)
{

    // return null if not found
    if (data.empty())
    {
        throw NoDataFound("No data found");
    }
    ChassisType answer;

    auto ptr = std::find_if(data.begin(), data.end(),
                            [id, &answer](const CarPointer &car)
                            {
                                if (std::holds_alternative<EVPointer>(car))
                                {
                                    auto tempcar = std::get<EVPointer>(car);
                                    if (tempcar->id() == id)
                                    {
                                        answer = (tempcar.get()->chassisType());
                                        return true;
                                    }
                                    return false;
                                }
                                return false;
                            });

    if (ptr == data.end())
    {
        return std::nullopt;
    }

    return answer;
}

float TotalBatteryCapacity(CarContainer &data)
{
    // return null if not found
    if (data.empty())
    {
        throw NoDataFound("No data found");
    }
    // else find total capacity
    float totalCapacity{0.0f};
    for (auto &car : data)
    {
        if (std::holds_alternative<EVPointer>(car))
        {
            auto tempcar = std::get<EVPointer>(car);
            totalCapacity += tempcar->batteryCapacity();
        }
    }
    return totalCapacity;
}


