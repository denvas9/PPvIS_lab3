#include "map.h"

std::istream& operator >> (std::istream& in, Map& userMap)
{
    in >> userMap.userLength >> userMap.userWidth >> userMap.userHungerTime >>
        userMap.userBirthTime >> userMap.HPreduce;
    return in;
}
std::ostream& operator << (std::ostream& out, Map& userMap)
{
    out << userMap.userLength << " " << userMap.userWidth << " " << userMap.userHungerTime << " " <<
        userMap.userBirthTime << " " << userMap.HPreduce << std::endl;
    return out;
}