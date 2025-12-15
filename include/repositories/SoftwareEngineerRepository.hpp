#ifndef SOFTWARE_ENGINEER_REPOSITORY_HPP
#define SOFTWARE_ENGINEER_REPOSITORY_HPP

#include<iostream>
#include<memory>
#include<vector>
#include<functional>
#include<optional>
#include "entity/User.hpp"
#include "contexts/IUserDbContext.hpp"
#include "dto/SoftwareEngineerCreateDto.hpp"
#include "dto/SoftwareEngineerUpdateDto.hpp"
#include "dto/SoftwareEngineerDto.hpp"

/// @brief Repostiory provide function to do CRUD on software engineer data.
class CSoftwareEngineerRepository
{
    public:
    /// @brief Creates a new instance of the software engineer repository.
    /// @param cUserDbContext 
    CSoftwareEngineerRepository(IUserDbContext* cUserDbContext);

    /// @brief Add a new software engineer user to the database.
    /// @param stSoftwareEngineerCreateDto Software engineer dto with new all the required information.
    void Add(SoftwareEngineerCreateDto stSoftwareEngineerCreateDto);

    /// @brief Retrieves the matched software engineer users with the specified expression.
    /// @param Expression Expression used to match with the software engineer users.
    /// @return Vector of matched software engineer users.
    std::vector<SoftwareEngineerDto> Find(const std::function<bool(const SoftwareEngineerDto&)>& Expression) const;

    /// @brief Determines whether any software engineer users matches with the specified expression.
    /// @param Expression Expression used to match with the software engineer users.
    /// @return true of a matched software engineer user found; false otherwise.
    bool Any(const std::function<bool(const SoftwareEngineerDto&)>& Expression) const;

    /// @brief Retrieves all the software engineer users.
    /// @return vector of all the software engineer users.
    std::vector<SoftwareEngineerDto> GetAll() const;

    /// @brief Retrieve the software engineer user with specified id.
    /// @param nId Id of the software engineer user to retrieve.
    /// @return Software engineer user with the specified id.
    std::optional<SoftwareEngineerDto> GetById(int nId) const;

    /// @brief Update the target software engineer user with new detail.
    /// @param stUpdatedSoftwareEngineerDto New data to update(Id specified is used to update the target software engineer user).
    bool Update(const SoftwareEngineerUpdateDto& stUpdatedSoftwareEngineerDto);
    
    /// @brief Removes the software engineer user with specified software engineer user id.
    /// @param nId Id to of the software engineer user to remove.
    bool RemoveById(int nId);
    
    private:
    /// @brief Data context to update.
    IUserDbContext* m_cUserDbContext;

    /// @brief Convert create software engineer dto to user object.
    /// @param stSoftwareEngineerCreateDto Create dto of software engineer user.
    /// @return User object created using the given create dto of software engineer dto.
    CUser ConvertToUser(SoftwareEngineerCreateDto stSoftwareEngineerCreateDto)
    {
        return CUser(
            0,   // placeholder ID,
            stSoftwareEngineerCreateDto.strPassword,
            stSoftwareEngineerCreateDto.strName,
            ROLE::SOFTWARE_ENGINEER,
            stSoftwareEngineerCreateDto.ePosition,
            stSoftwareEngineerCreateDto.nSalary
        );
    }

    /// @brief Convert update software engineer dto to user object.
    /// @param stSoftwareEngineerUpdateDto Update dto of software engineer user.
    /// @return User object created using the given update dto of software engineer dto.
    CUser ConvertToUser(SoftwareEngineerUpdateDto stSoftwareEngineerUpdateDto)
    {
        return CUser(
            stSoftwareEngineerUpdateDto.nId,
            stSoftwareEngineerUpdateDto.strPassword,
            stSoftwareEngineerUpdateDto.strName,
            ROLE::SOFTWARE_ENGINEER,
            stSoftwareEngineerUpdateDto.ePosition,
            stSoftwareEngineerUpdateDto.nSalary
        );
    }

    /// @brief Convert software engineer user instance to software engineer dto.
    /// @param ptrSoftwareEngineerUser User instance of software engineer user.
    /// @return Software engineer dto created using the given user object of software engineer dto.
    SoftwareEngineerDto ConvertToDto(const CUser* ptrSoftwareEngineerUser) const
    {
        return SoftwareEngineerDto{
            ptrSoftwareEngineerUser->GetId(),
            ptrSoftwareEngineerUser->GetName(),
            ptrSoftwareEngineerUser->GetPosition(),
            ptrSoftwareEngineerUser->GetSalary(),
        };  
    }
};

#endif