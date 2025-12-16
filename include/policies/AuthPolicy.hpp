#ifndef AUTH_POLICY_HPP
#define AUTH_POLICY_HPP

#include "enums/Action.hpp"
#include "dto/AuthSession.hpp"

class AuthPolicy
{
    public:
    AuthPolicy() = default;
    ~AuthPolicy() = default;

    bool IsAllowed(ACTION eAction, AuthSessionDto stAuthSessionDto);
};

#endif