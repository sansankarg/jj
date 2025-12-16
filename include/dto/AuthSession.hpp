#ifndef AUTH_SESSION_HPP
#define AUTH_SESSION_HPP

#include<iostream>
#include "enums/Role.hpp"

struct AuthSessionDto
{
    const int nId;
    ROLE eRole;
};

#endif