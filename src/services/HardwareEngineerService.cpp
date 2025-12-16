#include "services/HardwareEngineerService.hpp"

#include<iostream>
#include<memory>
#include<vector>
#include<functional>
#include<optional>
#include "entity/User.hpp"
#include "repositories/IUserRepository.hpp"
#include "repositories/IUserRepository.hpp"
#include "dto/HardwareEngineerDto.hpp"

CHardwareEngineerService::CHardwareEngineerService(IUserRepository* iUserRepository)
: m_iUserRepository(iUserRepository) {}

void CHardwareEngineerService::Add(HardwareEngineerCreateDto stHardwareEngineerCreateDto)
{
    m_iUserRepository->Add(ConvertToUser(stHardwareEngineerCreateDto));
}

std::vector<HardwareEngineerDto> CHardwareEngineerService::GetAll() const
{
    std::vector<const CUser*> cUsers = this->m_iUserRepository->Find([](const CUser& cUser) {
        return cUser.GetRole() == ROLE::HARDWARE_ENGINEER;
    });
    std::vector<HardwareEngineerDto> stHardWareEngineers;
    for(const CUser* cUser: cUsers)
    {
        stHardWareEngineers.emplace_back(ConvertToDto(cUser));
    }
    return stHardWareEngineers;
}

std::optional<HardwareEngineerDto> CHardwareEngineerService::GetById(int nId) const
{
    const CUser* cUser = this->m_iUserRepository->GetById(nId);
    if(cUser == nullptr || cUser->GetRole() != ROLE::HARDWARE_ENGINEER)
    {
        return std::nullopt;
    }
    HardwareEngineerDto stHardwareEngineerDto = ConvertToDto(cUser);
    return stHardwareEngineerDto;
}