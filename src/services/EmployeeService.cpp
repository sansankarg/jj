#include "services/EmployeeService.hpp"

#include<iostream>
#include<memory>
#include<vector>
#include<functional>
#include<optional>
#include "entity/User.hpp"
#include "repositories/IUserRepository.hpp"
#include "dto/EmployeeDto.hpp"

CEmployeeService::CEmployeeService(IUserRepository* iUserRepository)
: m_iUserRepository(iUserRepository) {}

std::vector<EmployeeDto> CEmployeeService::Find(const std::function<bool(const EmployeeDto&)>& Expression) const
{        
    std::vector<const CUser*> Users = this->m_iUserRepository->GetAll();
    std::vector<EmployeeDto> MatchedUsers;
    for(const CUser* cUser: Users)
    {
        const EmployeeDto stEmployeeDto = ConvertToDto(cUser);
        if(Expression(stEmployeeDto))
        {
            MatchedUsers.emplace_back(stEmployeeDto);
        }
    }
    return MatchedUsers;
}

bool CEmployeeService::Any(const std::function<bool(const EmployeeDto&)>& Expression) const
{
    std::vector<const CUser*> Users = this->m_iUserRepository->GetAll();
    std::vector<EmployeeDto> MatchedUsers;
    for(const CUser* cUser: Users)
    {
        const EmployeeDto stEmployeeDto = ConvertToDto(cUser);
        if(Expression(stEmployeeDto))
        {
            return true;
        }
    }
    return false;
}

std::vector<EmployeeDto> CEmployeeService::GetAll() const
{
    std::vector<const CUser*> cUsers = this->m_iUserRepository->GetAll();
    std::vector<EmployeeDto> stEmployeeDtos;
    for(const CUser* cUser: cUsers)
    {
        stEmployeeDtos.emplace_back(ConvertToDto(cUser));
    }
    return stEmployeeDtos;
}

std::optional<EmployeeDto> CEmployeeService::GetById(int nId) const
{
    const CUser* cUser = this->m_iUserRepository->GetById(nId);
    if(cUser == nullptr)
    {
        return std::nullopt;
    }
    EmployeeDto stEmployeeDto = ConvertToDto(cUser);
    return stEmployeeDto;
}

void CEmployeeService::UpdatePosition(int nId, POSITION ePosition){
    this->m_iUserRepository->UpdatePosition(nId, ePosition);
}

void CEmployeeService::UpdateSalary(int nId, int nSalary) {
    this->m_iUserRepository->UpdateSalary(nId, nSalary);
}

bool CEmployeeService::RemoveById(int nId)
{
    if (!this->m_iUserRepository->Any(
        [nId](const CUser& cUser)
        {
            return cUser.GetId() == nId;
        }
    ))
    {
        return false;
    }

    this->m_iUserRepository->RemoveById(nId);
    return true;
}