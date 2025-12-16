#ifndef MANAGEMENT_STAFF_REPOSITORY_HPP
#define MANAGEMENT_STAFF_REPOSITORY_HPP

#include<iostream>
#include<memory>
#include<vector>
#include<functional>
#include<optional>
#include "entity/User.hpp"
#include "repositories/IUserRepository.hpp"
#include "dto/ManagementStaffCreateDto.hpp"
#include "dto/ManagementStaffDto.hpp"

/// @brief Repostiory provide function to do CRUD on management staff data.
class CManagementStaffService
{
    public:
    /// @brief Creates a new instance of the management staff repository.
    /// @param cUserDbContext 
    CManagementStaffService(IUserRepository* iUserRepository);

    /// @brief Add a new management staff user to the database.
    /// @param stManagementStaffCreateDto Management staff dto with new all the required information.
    void Add(ManagementStaffCreateDto stManagementStaffCreateDto);
    
    /// @brief Retrieves all the management staff users.
    /// @return vector of all the management staff users.
    std::vector<ManagementStaffDto> GetAll() const;

    /// @brief Retrieve the management staff user with specified id.
    /// @param nId Id of the management staff user to retrieve.
    /// @return Management staff user with the specified id.
    std::optional<ManagementStaffDto> GetById(int nId) const;
    
    private:
    /// @brief Data context to update.
    IUserRepository* m_iUserRepository;

    /// @brief Convert create management staff dto to user object.
    /// @param stManagementStaffCreateDto Create dto of management staff user.
    /// @return User object created using the given create dto of management staff dto.
    CUser ConvertToUser(ManagementStaffCreateDto stManagementStaffCreateDto)
    {
        return CUser(
            0,   // placeholder ID,
            stManagementStaffCreateDto.strPassword,
            stManagementStaffCreateDto.strName,
            ROLE::MANAGEMENT_STAFF,
            stManagementStaffCreateDto.ePosition,
            stManagementStaffCreateDto.nSalary
        );
    }

    /// @brief Convert management staff user instance to management staff dto.
    /// @param ptrManagementStaffUser User instance of management staff user.
    /// @return Management staff dto created using the given user object of management staff dto.
    ManagementStaffDto ConvertToDto(const CUser* ptrManagementStaffUser) const
    {
        return ManagementStaffDto{
            ptrManagementStaffUser->GetId(),
            ptrManagementStaffUser->GetName(),
            ptrManagementStaffUser->GetPosition(),
            ptrManagementStaffUser->GetSalary(),
        };  
    }
};

#endif