#include "repositories/ManagementStaffRepostitory.hpp"

#include<iostream>
#include<memory>
#include<vector>
#include<functional>
#include<optional>
#include "entity/User.hpp"
#include "contexts/IUserDbContext.hpp"
#include "dto/ManagementStaffCreateDto.hpp"
#include "dto/ManagementStaffUpdateDto.hpp"
#include "dto/ManagementStaffDto.hpp"

CManagementStaffRepository::CManagementStaffRepository(IUserDbContext* cUserDbContext)
: m_cUserDbContext(cUserDbContext) {}

void CManagementStaffRepository::Add(ManagementStaffCreateDto stManagementStaffCreateDto)
{
    m_cUserDbContext->Add(ConvertToUser(stManagementStaffCreateDto));
}

std::vector<ManagementStaffDto> CManagementStaffRepository::Find(const std::function<bool(const ManagementStaffDto&)>& Expression) const
{        
    std::vector<const CUser*> Users = this->m_cUserDbContext->Find([](const CUser& cUser) {
        return cUser.GetRole() == ROLE::MANAGEMENT_STAFF;
    });
    std::vector<ManagementStaffDto> MatchedUsers;
    for(const CUser* cUser: Users)
    {
        const ManagementStaffDto stManagementStaffDto = ConvertToDto(cUser);
        if(Expression(stManagementStaffDto))
        {
            MatchedUsers.emplace_back(stManagementStaffDto);
        }
    }
    return MatchedUsers;
}

bool CManagementStaffRepository::Any(const std::function<bool(const ManagementStaffDto&)>& Expression) const
{
    std::vector<const CUser*> Users = this->m_cUserDbContext->Find([](const CUser& cUser) {
        return cUser.GetRole() == ROLE::MANAGEMENT_STAFF;
    });
    std::vector<ManagementStaffDto> MatchedUsers;
    for(const CUser* cUser: Users)
    {
        const ManagementStaffDto stManagementStaffDto = ConvertToDto(cUser);
        if(Expression(stManagementStaffDto))
        {
            return true;
        }
    }
    return false;
}

std::vector<ManagementStaffDto> CManagementStaffRepository::GetAll() const
{
    std::vector<const CUser*> cUsers = this->m_cUserDbContext->Find([](const CUser& cUser) {
        return cUser.GetRole() == ROLE::MANAGEMENT_STAFF;
    });
    std::vector<ManagementStaffDto> stManagementStaffs;
    for(const CUser* cUser: cUsers)
    {
        stManagementStaffs.emplace_back(ConvertToDto(cUser));
    }
    return stManagementStaffs;
}

std::optional<ManagementStaffDto> CManagementStaffRepository::GetById(int nId) const
{
    const CUser* cUser = this->m_cUserDbContext->GetById(nId);
    if(cUser == nullptr || cUser->GetRole() != ROLE::MANAGEMENT_STAFF)
    {
        return std::nullopt;
    }
    ManagementStaffDto stManagementStaffDto = ConvertToDto(cUser);
    return stManagementStaffDto;
}

bool CManagementStaffRepository::Update(const ManagementStaffUpdateDto& stUpdatedManagementStaffDto)
{
    if (!this->m_cUserDbContext->Any(
        [stUpdatedManagementStaffDto](const CUser& cUser)
        {
            return cUser.GetId() == stUpdatedManagementStaffDto.nId &&
                cUser.GetRole() == ROLE::MANAGEMENT_STAFF;
        }
    ))
    {
        return false;
    }

    this->m_cUserDbContext->UpdateUser(ConvertToUser(stUpdatedManagementStaffDto));
    return true;
}

bool CManagementStaffRepository::RemoveById(int nId)
{
    if (!this->m_cUserDbContext->Any(
        [nId](const CUser& cUser)
        {
            return cUser.GetId() == nId &&
                cUser.GetRole() == ROLE::MANAGEMENT_STAFF;
        }
    ))
    {
        return false;
    }

    this->m_cUserDbContext->RemoveById(nId);
    return true;
}