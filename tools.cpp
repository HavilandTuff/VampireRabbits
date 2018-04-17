//Tools .cpp
#include "tools.hpp"

void Tools::sleep(int milisecond)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(milisecond));
}
