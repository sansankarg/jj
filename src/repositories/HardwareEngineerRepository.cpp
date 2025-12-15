#include "repositories/HardwareEngineerRepository.hpp"

#include<iostream>
#include<memory>
#include<vector>
#include<functional>
#include<optional>
#include "entity/User.hpp"
#include "contexts/IUserDbContext.hpp"
#include "dto/HardwareEngineerCreateDto.hpp"
#include "dto/HardwareEngineerUpdateDto.hpp"
#include "dto/HardwareEngineerDto.hpp"

CHardwareEngineerRepository::CHardwareEngineerRepository(IUserDbContext* cUserDbContext)
: m_cUserDbContext(cUserDbContext) {}

void CHardwareEngineerRepository::Add(HardwareEngineerCreateDto stHardwareEngineerCreateDto)
{
    m_cUserDbContext->Add(ConvertToUser(stHardwareEngineerCreateDto));
}

std::vector<HardwareEngineerDto> CHardwareEngineerRepository::Find(const std::function<bool(const HardwareEngineerDto&)>& Expression) const
{        
    std::vector<const CUser*> Users = this->m_cUserDbContext->Find([](const CUser& cUser) {
        return cUser.GetRole() == ROLE::HARDWARE_ENGINEER;
    });
    std::vector<HardwareEngineerDto> MatchedUsers;
    for(const CUser* cUser: Users)
    {
        const HardwareEngineerDto stHardwareEngineerDto = ConvertToDto(cUser);
        if(Expression(stHardwareEngineerDto))
        {
            MatchedUsers.emplace_back(stHardwareEngineerDto);
        }
    }
    return MatchedUsers;
}

bool CHardwareEngineerRepository::Any(const std::function<bool(const HardwareEngineerDto&)>& Expression) const
{
    std::vector<const CUser*> Users = this->m_cUserDbContext->Find([](const CUser& cUser) {
        return cUser.GetRole() == ROLE::HARDWARE_ENGINEER;
    });
    std::vector<HardwareEngineerDto> MatchedUsers;
    for(const CUser* cUser: Users)
    {
        const HardwareEngineerDto stHardwareEngineerDto = ConvertToDto(cUser);
        if(Expression(stHardwareEngineerDto))
        {
            return true;
        }
    }
    return false;
}

std::vector<HardwareEngineerDto> CHardwareEngineerRepository::GetAll() const
{
    std::vector<const CUser*> cUsers = this->m_cUserDbContext->Find([](const CUser& cUser) {
        return cUser.GetRole() == ROLE::HARDWARE_ENGINEER;
    });
    std::vector<HardwareEngineerDto> stHardWareEngineers;
    for(const CUser* cUser: cUsers)
    {
        stHardWareEngineers.emplace_back(ConvertToDto(cUser));
    }
    return stHardWareEngineers;
}

std::optional<HardwareEngineerDto> CHardwareEngineerRepository::GetById(int nId) const
{
    const CUser* cUser = this->m_cUserDbContext->GetById(nId);
    if(cUser == nullptr || cUser->GetRole() != ROLE::HARDWARE_ENGINEER)
    {
        return std::nullopt;
    }
    HardwareEngineerDto stHardwareEngineerDto = ConvertToDto(cUser);
    return stHardwareEngineerDto;
}

bool CHardwareEngineerRepository::Update(const HardwareEngineerUpdateDto& stUpdatedHardwareEngineerDto)
{
    if (!this->m_cUserDbContext->Any(
        [stUpdatedHardwareEngineerDto](const CUser& cUser)
        {
            return cUser.GetId() == stUpdatedHardwareEngineerDto.nId &&
                cUser.GetRole() == ROLE::HARDWARE_ENGINEER;
        }
    ))
    {
        return false;
    }
    
    this->m_cUserDbContext->UpdateUser(ConvertToUser(stUpdatedHardwareEngineerDto));
    return true;
}

bool CHardwareEngineerRepository::RemoveById(int nId)
{
    if (!this->m_cUserDbContext->Any(
        [nId](const CUser& cUser)
        {
            return cUser.GetId() == nId &&
                cUser.GetRole() == ROLE::HARDWARE_ENGINEER;
        }
    ))
    {
        return false;
    }

    this->m_cUserDbContext->RemoveById(nId);
    return true;
}