#include "Plant.h"

const std::array<std::string, 5> Plant::plantTypeNames = 
{
    "Hornflower",
    "Bombflower",
    "Coinflower",
    "Healflower"
};

size_t Plant::max_hp_ = 0;