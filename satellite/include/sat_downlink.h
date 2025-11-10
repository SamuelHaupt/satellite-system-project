#ifndef SAT_DOWNLINK_H
#define SAT_DOWNLINK_H

#include <vector>
#include <iostream>
#include <cstdint>


class SatDownlink {
public:
    SatDownlink();

    int send(const std::vector<uint8_t>& bits);
};



#endif