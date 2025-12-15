#include "entity/user.hpp"

#include<iostream>

#include "entity/RoleProfile.hpp"

CUser::CUser(
    int nId,
    std::string strPassword,
    std::string strName,
    ROLE eRole,
    POSITION ePosition,
    int nSalary,
    std::unique_ptr<CRoleProfile>  cRoleProfile)
    :m_nId(nId),
    m_strPassword(strPassword),
    m_strName(strName),
    m_eRole(eRole),
    m_ePosition(ePosition),
    m_nSalary(nSalary),
    m_cRoleData(std::move(cRoleProfile)) 
    {}

void CUser::SetId(int nId)
{
    this->m_nId = nId;
}

int CUser::GetId() const
{
    return this->m_nId;
}
    
void CUser::SetPassword(std::string strPassword)
{
    this->m_strPassword = strPassword;
}

std::string CUser::GetPassword() const
{
    return this->m_strPassword;
}

void CUser::SetName(std::string strName)
{
    this->m_strName = strName;
}

std::string CUser::GetName() const
{
    return this->m_strName;
}

void CUser::SetRole(ROLE eRole)
{
    this->m_eRole = eRole;
}

ROLE CUser::GetRole() const
{
    return this->m_eRole;
}

void CUser::SetPosition(POSITION ePosition)
{
    this->m_ePosition = ePosition;
}

POSITION CUser::GetPosition() const
{
    return this->m_ePosition;
}

void CUser::SetSalary(int nSalary)
{
    this->m_nSalary = nSalary;
}

int CUser::GetSalary() const
{
    return this->m_nSalary;
}

