#include "services/ManagementStaffService.hpp"

#include<iostream>
#include<memory>
#include<vector>
#include<functional>
#include<optional>
#include "entity/User.hpp"
#include "repositories/IUserRepository.hpp"
#include "dto/ManagementStaffCreateDto.hpp"
#include "dto/ManagementStaffDto.hpp"

CManagementStaffService::CManagementStaffService(IUserRepository* iUserRepository)
: m_iUserRepository(iUserRepository) {}

void CManagementStaffService::Add(ManagementStaffCreateDto stManagementStaffCreateDto)
{
    m_iUserRepository->Add(ConvertToUser(stManagementStaffCreateDto));
}

std::vector<ManagementStaffDto> CManagementStaffService::GetAll() const
{
    std::vector<const CUser*> cUsers = this->m_iUserRepository->Find([](const CUser& cUser) {
        return cUser.GetRole() == ROLE::MANAGEMENT_STAFF;
    });
    std::vector<ManagementStaffDto> stManagementStaffs;
    for(const CUser* cUser: cUsers)
    {
        stManagementStaffs.emplace_back(ConvertToDto(cUser));
    }
    return stManagementStaffs;
}

std::optional<ManagementStaffDto> CManagementStaffService::GetById(int nId) const
{
    const CUser* cUser = this->m_iUserRepository->GetById(nId);
    if(cUser == nullptr || cUser->GetRole() != ROLE::MANAGEMENT_STAFF)
    {
        return std::nullopt;
    }
    ManagementStaffDto stManagementStaffDto = ConvertToDto(cUser);
    return stManagementStaffDto;
}