#include "repositories/SoftwareEngineerRepository.hpp"

#include<iostream>
#include<memory>
#include<vector>
#include<functional>
#include<optional>
#include "entity/User.hpp"
#include "contexts/IUserDbContext.hpp"
#include "dto/SoftwareEngineerCreateDto.hpp"
#include "dto/SoftwareEngineerUpdateDto.hpp"
#include "dto/SoftwareEngineerDto.hpp"

CSoftwareEngineerRepository::CSoftwareEngineerRepository(IUserDbContext* cUserDbContext)
: m_cUserDbContext(cUserDbContext){}

void CSoftwareEngineerRepository::Add(SoftwareEngineerCreateDto stSoftwareEngineerCreateDto)
{
    m_cUserDbContext->Add(ConvertToUser(stSoftwareEngineerCreateDto));
}

std::vector<SoftwareEngineerDto> CSoftwareEngineerRepository::Find(const std::function<bool(const SoftwareEngineerDto&)>& Expression) const
{        
    std::vector<const CUser*> Users = this->m_cUserDbContext->Find([](const CUser& cUser) {
        return cUser.GetRole() == ROLE::SOFTWARE_ENGINEER;
    });
    std::vector<SoftwareEngineerDto> MatchedUsers;
    for(const CUser* cUser: Users)
    {
        const SoftwareEngineerDto stSoftwareEngineerDto = ConvertToDto(cUser);
        if(Expression(stSoftwareEngineerDto))
        {
            MatchedUsers.emplace_back(stSoftwareEngineerDto);
        }
    }
    return MatchedUsers;
}

bool CSoftwareEngineerRepository::Any(const std::function<bool(const SoftwareEngineerDto&)>& Expression) const
{
    std::vector<const CUser*> Users = this->m_cUserDbContext->Find([](const CUser& cUser) {
        return cUser.GetRole() == ROLE::SOFTWARE_ENGINEER;
    });
    std::vector<SoftwareEngineerDto> MatchedUsers;
    for(const CUser* cUser: Users)
    {
        const SoftwareEngineerDto stSoftwareEngineerDto = ConvertToDto(cUser);
        if(Expression(stSoftwareEngineerDto))
        {
            return true;
        }
    }
    return false;
}

std::vector<SoftwareEngineerDto> CSoftwareEngineerRepository::GetAll() const
{
    std::vector<const CUser*> cUsers = this->m_cUserDbContext->Find([](const CUser& cUser) {
        return cUser.GetRole() == ROLE::SOFTWARE_ENGINEER;
    });
    std::vector<SoftwareEngineerDto> stSoftwareEngineers;
    for(const CUser* cUser: cUsers)
    {
        stSoftwareEngineers.emplace_back(ConvertToDto(cUser));
    }
    return stSoftwareEngineers;
}

std::optional<SoftwareEngineerDto> CSoftwareEngineerRepository::GetById(int nId) const
{
    const CUser* cUser = this->m_cUserDbContext->GetById(nId);
    if(cUser == nullptr || cUser->GetRole() != ROLE::SOFTWARE_ENGINEER)
    {
        return std::nullopt;
    }
    SoftwareEngineerDto stSoftwareEngineerDto = ConvertToDto(cUser);
    return stSoftwareEngineerDto;
}

bool CSoftwareEngineerRepository::Update(const SoftwareEngineerUpdateDto& stUpdatedSoftwareEngineerDto)
{
    if (!this->m_cUserDbContext->Any(
        [stUpdatedSoftwareEngineerDto](const CUser& cUser)
        {
            return cUser.GetId() == stUpdatedSoftwareEngineerDto.nId &&
                cUser.GetRole() == ROLE::SOFTWARE_ENGINEER;
        }
    ))
    {
        return false;
    }

    this->m_cUserDbContext->UpdateUser(ConvertToUser(stUpdatedSoftwareEngineerDto));
    return true;
}

bool CSoftwareEngineerRepository::RemoveById(int nId)
{
    if (!this->m_cUserDbContext->Any(
        [nId](const CUser& cUser)
        {
            return cUser.GetId() == nId &&
                cUser.GetRole() == ROLE::SOFTWARE_ENGINEER;
        }
    ))
    {
        return false;
    }

    this->m_cUserDbContext->RemoveById(nId);
    return true;
}