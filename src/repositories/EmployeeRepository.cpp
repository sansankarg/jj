#include "repositories/EmployeeRepository.hpp"

#include<iostream>
#include<memory>
#include<vector>
#include<functional>
#include<optional>
#include "entity/User.hpp"
#include "contexts/IUserDbContext.hpp"
#include "dto/EmployeeDto.hpp"

CEmployeeRepository::CEmployeeRepository(IUserDbContext* cUserDbContext)
: m_cUserDbContext(cUserDbContext) {}

std::vector<EmployeeDto> CEmployeeRepository::Find(const std::function<bool(const EmployeeDto&)>& Expression) const
{        
    std::vector<const CUser*> Users = this->m_cUserDbContext->GetAll();
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

bool CEmployeeRepository::Any(const std::function<bool(const EmployeeDto&)>& Expression) const
{
    std::vector<const CUser*> Users = this->m_cUserDbContext->GetAll();
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

std::vector<EmployeeDto> CEmployeeRepository::GetAll() const
{
    std::vector<const CUser*> cUsers = this->m_cUserDbContext->GetAll();
    std::vector<EmployeeDto> stEmployeeDtos;
    for(const CUser* cUser: cUsers)
    {
        stEmployeeDtos.emplace_back(ConvertToDto(cUser));
    }
    return stEmployeeDtos;
}

std::optional<EmployeeDto> CEmployeeRepository::GetById(int nId) const
{
    const CUser* cUser = this->m_cUserDbContext->GetById(nId);
    if(cUser == nullptr)
    {
        return std::nullopt;
    }
    EmployeeDto stEmployeeDto = ConvertToDto(cUser);
    return stEmployeeDto;
}