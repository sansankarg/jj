#ifndef USER_HPP
#define USER_HPP

#include<iostream>
#include<memory>

#include "enums/Positon.hpp"
#include "enums/Role.hpp"
#include "entity/RoleProfile.hpp"
#include "entity/HardwareEngineerData.hpp"

/// @brief Represents a user.
class CUser
{
    public:
    CUser(
        int nId,
        std::string strPassword,
        std::string strName,
        ROLE eRole,
        POSITION ePosition,
        int nSalary,
        std::unique_ptr<CRoleProfile>  cRoleProfile = nullptr);

    void SetId(int nId);

    int GetId() const;
    
    void SetPassword(std::string strName);

    std::string GetPassword() const;

    void SetName(std::string strName);

    std::string GetName() const;

    void SetRole(ROLE eRole);

    ROLE GetRole() const;

    void SetPosition(POSITION ePosition);

    POSITION GetPosition() const;

    void SetSalary(int nSalary);

    int GetSalary() const;

    template<typename T, typename... Args>
    void SetRoleProfile(Args&&... args)
    {
        m_cRoleData = std::make_unique<T>(std::forward<Args>(args)...);
    }

    template<typename T>
    T* GetRoleProfile() const
    {
        return dynamic_cast<T*>(m_cRoleData.get());
    }

    private:
    int m_nId;
    std::string m_strPassword;
    std::string m_strName;
    ROLE m_eRole;
    POSITION m_ePosition;
    int m_nSalary;
    std::unique_ptr<CRoleProfile> m_cRoleData;

};

#endif