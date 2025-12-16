#include "services/AuthService.hpp"

#include<optional>
#include "dto/LoginRequestDto.hpp"
#include "dto/AuthSession.hpp"

AuthService::AuthService(IUserRepository* iUserRepository) 
    :m_iUserRepository(iUserRepository){}

std::optional<AuthSessionDto> AuthService::Authenticate(LoginRequestDto stLoginRequestDto)
{
    if(this->m_iUserRepository
            ->Any([stLoginRequestDto](const CUser& cUser)
            {
                return cUser.GetId() == stLoginRequestDto.nId && cUser.GetPassword() == stLoginRequestDto.strPassword;
            }))
            {
                const CUser* cUser = this->m_iUserRepository->GetById(stLoginRequestDto.nId);
                return AuthSessionDto{
                    cUser->GetId(),
                    cUser->GetRole()
                };
            }        
    return std::nullopt;
}