#ifndef HARDWAREDATA_HPP
#define HARDWAREDATA_HPP

#include "entity/RoleProfile.hpp"

/// @brief Represents the profile data specific to the hardware engineer role.
class HardwareEngineerProfile : public CRoleProfile
{
    public:
    HardwareEngineerProfile(int nHarwareUnitCount);
    void SetHardwareUnitCount(int nHardwareUnitCount);
    int GetHardwareUnitCount();

    private:
    int m_nHardwareUnitCount;
};

#endif