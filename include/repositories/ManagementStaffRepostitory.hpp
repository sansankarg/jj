#ifndef MANAGEMENT_STAFF_REPOSITORY_HPP
#define MANAGEMENT_STAFF_REPOSITORY_HPP

#include<iostream>
#include<memory>
#include<vector>
#include<functional>
#include<optional>
#include "entity/User.hpp"
#include "contexts/IUserDbContext.hpp"
#include "dto/ManagementStaffCreateDto.hpp"
#include "dto/ManagementStaffUpdateDto.hpp"
#include "dto/ManagementStaffDto.hpp"

/// @brief Repostiory provide function to do CRUD on management staff data.
class CManagementStaffRepository
{
    public:
    /// @brief Creates a new instance of the management staff repository.
    /// @param cUserDbContext 
    CManagementStaffRepository(IUserDbContext* cUserDbContext);

    /// @brief Add a new management staff user to the database.
    /// @param stManagementStaffCreateDto Management staff dto with new all the required information.
    void Add(ManagementStaffCreateDto stManagementStaffCreateDto);

    /// @brief Retrieves the matched management staff users with the specified expression.
    /// @param Expression Expression used to match with the management staff users.
    /// @return Vector of matched management staff users.
    std::vector<ManagementStaffDto> Find(const std::function<bool(const ManagementStaffDto&)>& Expression) const;

    /// @brief Determines whether any management staff users matches with the specified expression.
    /// @param Expression Expression used to match with the management staff users.
    /// @return true of a matched management staff user found; false otherwise.
    bool Any(const std::function<bool(const ManagementStaffDto&)>& Expression) const;

    /// @brief Retrieves all the management staff users.
    /// @return vector of all the management staff users.
    std::vector<ManagementStaffDto> GetAll() const;

    /// @brief Retrieve the management staff user with specified id.
    /// @param nId Id of the management staff user to retrieve.
    /// @return Management staff user with the specified id.
    std::optional<ManagementStaffDto> GetById(int nId) const;

    /// @brief Update the target management staff user with new detail.
    /// @param stUpdatedManagementStaffDto New data to update(Id specified is used to update the target management staff user).
    bool Update(const ManagementStaffUpdateDto& stUpdatedManagementStaffDto);
    
    /// @brief Removes the management staff user with specified management staff user id.
    /// @param nId Id to of the management staff user to remove.
    bool RemoveById(int nId);
    
    private:
    /// @brief Data context to update.
    IUserDbContext* m_cUserDbContext;

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

    /// @brief Convert update management staff dto to user object.
    /// @param stManagementStaffUpdateDto Update dto of management staff user.
    /// @return User object created using the given update dto of management staff dto.
    CUser ConvertToUser(ManagementStaffUpdateDto stManagementStaffUpdateDto)
    {
        return CUser(
            stManagementStaffUpdateDto.nId,
            stManagementStaffUpdateDto.strPassword,
            stManagementStaffUpdateDto.strName,
            ROLE::MANAGEMENT_STAFF,
            stManagementStaffUpdateDto.ePosition,
            stManagementStaffUpdateDto.nSalary
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