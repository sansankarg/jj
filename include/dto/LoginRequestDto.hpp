#ifndef LOGIN_REQUEST_DTO
#define LOGIN_REQUEST_DTO

#include<iostream>

struct LoginRequestDto
{
    LoginRequestDto(int nId, std::string strPassword)
        :nId(nId), strPassword(strPassword) {}
    ~LoginRequestDto()  = default;

    const int nId;
    const std::string strPassword;
};

#endif