#include "repositories/UserRepository.hpp"

#include<iostream>
#include<vector>
#include<memory>
#include<functional>
#include <algorithm>

#include "entity/User.hpp"

CUserRepository::CUserRepository()
{
    Users = std::vector<std::unique_ptr<CUser>>();
    this->nNextId = 0;
}


void CUserRepository::Add(CUser NewUser)
{
    if(NewUser.GetId() == 0)
    {
        NewUser.SetId(++nNextId);
    }
    Users.push_back(std::make_unique<CUser>(std::move(NewUser)));
}

std::vector<const CUser*> CUserRepository::Find(const std::function<bool(const CUser&)>& Expression) const
{
    std::vector<const CUser*> MatchedUsers;
    for (const auto& ptrUser : Users)
    {
        if(Expression(*ptrUser))
        {
            MatchedUsers.push_back(ptrUser.get());
        }
    }
    
    return MatchedUsers;
}

bool CUserRepository::Any(const std::function<bool(const CUser&)>& Expression) const
{
    for (const auto& ptrUser : Users)
    {
        if(Expression(*ptrUser))
        {
            return true;
        }
    }

    return false;
}

std::vector<const CUser*> CUserRepository::GetAll() const
{
    std::vector<const CUser*> result;
    for (const auto& cUserPtr : Users)
        result.push_back(cUserPtr.get());
    return result;
}

const CUser* CUserRepository::GetById(int nId) const
{
    for (const auto& ptrUser : Users){
        if (ptrUser->GetId() == nId)
        {
            return ptrUser.get(); 
        }
    }

    return nullptr;
}

void CUserRepository::UpdatePosition(int nId, POSITION ePosition)
{
    for (auto& ptrUser : Users)
    {
        if (ptrUser->GetId() == nId)
        {
            ptrUser->SetPosition(ePosition);
        }
    }
}

void CUserRepository::UpdateSalary(int nId, int nSalary)
{
    for (auto& ptrUser : Users)
    {
        if (ptrUser->GetId() == nId)
        {
            ptrUser->SetSalary(nSalary);
        }
    }
}

void CUserRepository::RemoveById(int nId)
{
    Users.erase(
        std::remove_if(Users.begin(), Users.end(),
            [nId](const std::unique_ptr<CUser>& u) { return u->GetId() == nId; }),
        Users.end()
    );
}