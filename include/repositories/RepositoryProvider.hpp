#ifndef REPOSITORY_PROVIDER_HPP
#define REPOSITORY_PROVIDER_HPP

#include "contexts/IUserDbContext.hpp"
#include "repositories/HardwareEngineerRepository.hpp"
#include "repositories/ManagementStaffRepostitory.hpp"
#include "repositories/SoftwareEngineerRepository.hpp"
#include "repositories/EmployeeRepository.hpp"

class CRepositoryProvider
{
    public: 

    CRepositoryProvider(IUserDbContext* ctx);

    CHardwareEngineerRepository m_cHardwareEngineers;
    CSoftwareEngineerRepository m_cSoftwareEngineers;
    CManagementStaffRepository m_cManagementStaff;
    CEmployeeRepository m_cEmployee;
};

#endif