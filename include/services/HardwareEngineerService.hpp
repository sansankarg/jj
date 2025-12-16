#ifndef HARDWARE_ENGINEER_REPOSITORY_HPP
#define HARDWARE_ENGINEER_REPOSITORY_HPP

#include<iostream>
#include<memory>
#include<vector>
#include<functional>
#include<optional>
#include "entity/User.hpp"
#include "repositories/IUserRepository.hpp"
#include "dto/HardwareEngineerCreateDto.hpp"
#include "dto/HardwareEngineerDto.hpp"

/// @brief Repostiory provide function to do CRUD on hardware engineer data.
class CHardwareEngineerService
{
    public:
    /// @brief Creates a new instance of the hardware engineer repository.
    /// @param cUserDbContext 
    CHardwareEngineerService(IUserRepository* iUserRepository);

    /// @brief Add a new hardware engineer user to the database.
    /// @param stHardwareEngineerCreateDto Hardware engineer dto with new all the required information.
    void Add(HardwareEngineerCreateDto stHardwareEngineerCreateDto);

    /// @brief Retrieves all the hardware engineer users.
    /// @return vector of all the hardware engineer users.
    std::vector<HardwareEngineerDto> GetAll() const;

    /// @brief Retrieve the hardware engineer user with specified id.
    /// @param nId Id of the hardware engineer user to retrieve.
    /// @return Hardware engineer user with the specified id.
    std::optional<HardwareEngineerDto> GetById(int nId) const;
    
    private:
    /// @brief Data context to update.
    IUserRepository* m_iUserRepository;

    /// @brief Convert create hardware engineer dto to user object.
    /// @param stHardwareEngineerCreateDto Create dto of hardware engineer user.
    /// @return User object created using the given create dto of hardware engineer dto.
    CUser ConvertToUser(HardwareEngineerCreateDto stHardwareEngineerCreateDto)
    {
        std::unique_ptr<HardwareEngineerProfile> cRoleData 
            = std::make_unique<HardwareEngineerProfile>(stHardwareEngineerCreateDto.nHardwareUnitCount);

        return CUser(
            0,   // placeholder ID,
            stHardwareEngineerCreateDto.strPassword,
            stHardwareEngineerCreateDto.strName,
            ROLE::HARDWARE_ENGINEER,
            stHardwareEngineerCreateDto.ePosition,
            stHardwareEngineerCreateDto.nSalary,
            std::move(cRoleData)
        );
    }

    /// @brief Convert hardware engineer user instance to hardware engineer dto.
    /// @param ptrHardwareEngineerUser User instance of hardware engineer user.
    /// @return Hardware engineer dto created using the given user object of hardware engineer dto.
    HardwareEngineerDto ConvertToDto(const CUser* ptrHardwareEngineerUser) const
    {
        HardwareEngineerProfile* profile = ptrHardwareEngineerUser->GetRoleProfile<HardwareEngineerProfile>();

        return HardwareEngineerDto{
            ptrHardwareEngineerUser->GetId(),
            ptrHardwareEngineerUser->GetName(),
            ptrHardwareEngineerUser->GetPosition(),
            ptrHardwareEngineerUser->GetSalary(),
            profile->GetHardwareUnitCount()
        };  
    }
};

#endif