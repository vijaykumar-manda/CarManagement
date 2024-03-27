#include "Functionalities.h"

int main()
{

    CarContainer data;
    std::future<void> createThread = std::async(std::launch::async, createObjects, std::ref(data));
    createThread.get();

    try
    {
        std::future<CarContainer> findInstances = std::async(std::launch::async, FindAndReturnCarInstance, std::ref(data), ChassisType::LADDER, 2);
       
        std::future<bool> allAbove30 = std::async(std::launch::async, AllAbove30Capacity, std::ref(data));

        std::future<int> count = std::async(std::launch::async, CountOfEVCar, std::ref(data));

        std::future<std::optional<ChassisType>> chassisType = std::async(std::launch::async, FindChassisType, std::ref(data), 123);

        std::future<float> totalBattery = std::async(std::launch::async, TotalBatteryCapacity, std::ref(data));
        
        CarContainer result = findInstances.get();
        
        std::cout << "Car instances are :\n ";
        
        if (!result.empty())
        {
            for (auto &vehicle : result)
            {
                if (std::holds_alternative<ICEPointer>(vehicle))
                {
                    auto v = std::get<ICEPointer>(vehicle);
                    std::cout << *v << std::endl;
                }
                else
                {
                    auto v = std::get<EVPointer>(vehicle);
                    std::cout << *v << std::endl;
                }
            }
        }

        std::cout << "All above 30 capacity 0/1 :" << allAbove30.get() << std::endl;
        std::cout << "Count of EV Car : " << count.get() << std::endl;

        std::optional<ChassisType> chasis = chassisType.get();
        std::cout << "Chassis Type : ";
        if (chasis.has_value())
        {
            std::cout << static_cast<int>(chasis.value()) << std::endl;
        }
        std::cout << "Total battery of EVCar : " << totalBattery.get() << std::endl;
    }
    catch (NoDataFound &err)
    {
        std::cout << err.what() << std::endl;
    }
    catch (InValidInput &err)
    {
        std::cout << err.what() << std::endl;
    }
}