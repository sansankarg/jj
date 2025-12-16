#ifndef REPOSITORY_PROVIDER_HPP
#define REPOSITORY_PROVIDER_HPP

#include "repositories/IUserRepository.hpp"
#include "services/HardwareEngineerService.hpp"
#include "services/ManagementStaffService.hpp"
#include "services/SoftwareEngineerService.hpp"
#include "services/EmployeeService.hpp"
#include "services/AuthService.hpp"

class CServiceProvider
{
    public: 

    CServiceProvider(IUserRepository* iUserRepository);

    CHardwareEngineerService m_cHardwareEngineers;
    CSoftwareEngineerService m_cSoftwareEngineers;
    CManagementStaffService m_cManagementStaff;
    CEmployeeService m_cEmployee;
    AuthService m_cAuthService;
};

#endif