#include "services/SoftwareEngineerService.hpp"

#include<iostream>
#include<memory>
#include<vector>
#include<functional>
#include<optional>
#include "entity/User.hpp"
#include "repositories/IUserRepository.hpp"
#include "dto/SoftwareEngineerCreateDto.hpp"
#include "dto/SoftwareEngineerDto.hpp"

CSoftwareEngineerService::CSoftwareEngineerService(IUserRepository* iUserRepository)
: m_iUserRepository(iUserRepository){}

void CSoftwareEngineerService::Add(SoftwareEngineerCreateDto stSoftwareEngineerCreateDto)
{
    m_iUserRepository->Add(ConvertToUser(stSoftwareEngineerCreateDto));
}

std::vector<SoftwareEngineerDto> CSoftwareEngineerService::GetAll() const
{
    std::vector<const CUser*> cUsers = this->m_iUserRepository->Find([](const CUser& cUser) {
        return cUser.GetRole() == ROLE::SOFTWARE_ENGINEER;
    });
    std::vector<SoftwareEngineerDto> stSoftwareEngineers;
    for(const CUser* cUser: cUsers)
    {
        stSoftwareEngineers.emplace_back(ConvertToDto(cUser));
    }
    return stSoftwareEngineers;
}

std::optional<SoftwareEngineerDto> CSoftwareEngineerService::GetById(int nId) const
{
    const CUser* cUser = this->m_iUserRepository->GetById(nId);
    if(cUser == nullptr || cUser->GetRole() != ROLE::SOFTWARE_ENGINEER)
    {
        return std::nullopt;
    }
    SoftwareEngineerDto stSoftwareEngineerDto = ConvertToDto(cUser);
    return stSoftwareEngineerDto;
}