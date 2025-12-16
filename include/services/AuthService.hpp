#ifndef AUTH_SERVICE_HPP
#define AUTH_SERVICE_HPP

#include<optional>
#include "repositories/IUserRepository.hpp"
#include "dto/LoginRequestDto.hpp"
#include "dto/AuthSession.hpp"

class AuthService
{
    public:
    AuthService(IUserRepository* iUserRepository);

    std::optional<AuthSessionDto> Authenticate(LoginRequestDto stLoginRequestDto);

    IUserRepository* m_iUserRepository;
};

#endif