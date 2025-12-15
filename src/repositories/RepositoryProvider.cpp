#include "repositories/RepositoryProvider.hpp"

CRepositoryProvider::CRepositoryProvider(IUserDbContext* ctx)
        : m_cHardwareEngineers(ctx),
        m_cSoftwareEngineers(ctx),
        m_cManagementStaff(ctx),
        m_cEmployee(ctx)
        {}