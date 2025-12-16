#include "entity/HardwareEngineerData.hpp"

HardwareEngineerProfile::HardwareEngineerProfile(int nHarwareUnitCount)
    : m_nHardwareUnitCount(nHarwareUnitCount){ }

void HardwareEngineerProfile::SetHardwareUnitCount(int nHardwareUnitCount)
{
    this->m_nHardwareUnitCount = nHardwareUnitCount;
}
int HardwareEngineerProfile::GetHardwareUnitCount()
{
    return this->m_nHardwareUnitCount;
}