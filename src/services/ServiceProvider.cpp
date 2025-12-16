#include "services/ServiceProvider.hpp"

CServiceProvider::CServiceProvider(IUserRepository* iUserRepository)
        : m_cHardwareEngineers(iUserRepository),
        m_cSoftwareEngineers(iUserRepository),
        m_cManagementStaff(iUserRepository),
        m_cEmployee(iUserRepository),
        m_cAuthService(iUserRepository)
        {}