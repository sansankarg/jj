#ifndef SOFTWARE_ENGINEER_REPOSITORY_HPP
#define SOFTWARE_ENGINEER_REPOSITORY_HPP

#include<iostream>
#include<memory>
#include<vector>
#include<functional>
#include<optional>
#include "entity/User.hpp"
#include "repositories/IUserRepository.hpp"
#include "dto/SoftwareEngineerCreateDto.hpp"
#include "dto/SoftwareEngineerDto.hpp"

/// @brief Repostiory provide function to do CRUD on software engineer data.
class CSoftwareEngineerService
{
    public:
    /// @brief Creates a new instance of the software engineer repository.
    /// @param cUserDbContext 
    CSoftwareEngineerService(IUserRepository* iUserRepository);

    /// @brief Add a new software engineer user to the database.
    /// @param stSoftwareEngineerCreateDto Software engineer dto with new all the required information.
    void Add(SoftwareEngineerCreateDto stSoftwareEngineerCreateDto);
    
    /// @brief Retrieves all the software engineer users.
    /// @return vector of all the software engineer users.
    std::vector<SoftwareEngineerDto> GetAll() const;

    /// @brief Retrieve the software engineer user with specified id.
    /// @param nId Id of the software engineer user to retrieve.
    /// @return Software engineer user with the specified id.
    std::optional<SoftwareEngineerDto> GetById(int nId) const;
    
    private:
    /// @brief Data context to update.
    IUserRepository* m_iUserRepository;

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