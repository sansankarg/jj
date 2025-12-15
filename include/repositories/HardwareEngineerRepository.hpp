#ifndef HARDWARE_ENGINEER_REPOSITORY_HPP
#define HARDWARE_ENGINEER_REPOSITORY_HPP

#include<iostream>
#include<memory>
#include<vector>
#include<functional>
#include<optional>
#include "entity/User.hpp"
#include "contexts/IUserDbContext.hpp"
#include "dto/HardwareEngineerCreateDto.hpp"
#include "dto/HardwareEngineerUpdateDto.hpp"
#include "dto/HardwareEngineerDto.hpp"

/// @brief Repostiory provide function to do CRUD on hardware engineer data.
class CHardwareEngineerRepository
{
    public:
    /// @brief Creates a new instance of the hardware engineer repository.
    /// @param cUserDbContext 
    CHardwareEngineerRepository(IUserDbContext* cUserDbContext);

    /// @brief Add a new hardware engineer user to the database.
    /// @param stHardwareEngineerCreateDto Hardware engineer dto with new all the required information.
    void Add(HardwareEngineerCreateDto stHardwareEngineerCreateDto);

    /// @brief Retrieves the matched hardware engineer users with the specified expression.
    /// @param Expression Expression used to match with the hardware engineer users.
    /// @return Vector of matched hardware engineer users.
    std::vector<HardwareEngineerDto> Find(const std::function<bool(const HardwareEngineerDto&)>& Expression) const;

    /// @brief Determines whether any hardware engineer users matches with the specified expression.
    /// @param Expression Expression used to match with the hardware engineer users.
    /// @return true of a matched hardware engineer user found; false otherwise.
    bool Any(const std::function<bool(const HardwareEngineerDto&)>& Expression) const;

    /// @brief Retrieves all the hardware engineer users.
    /// @return vector of all the hardware engineer users.
    std::vector<HardwareEngineerDto> GetAll() const;

    /// @brief Retrieve the hardware engineer user with specified id.
    /// @param nId Id of the hardware engineer user to retrieve.
    /// @return Hardware engineer user with the specified id.
    std::optional<HardwareEngineerDto> GetById(int nId) const;

    /// @brief Update the target hardware engineer user with new detail.
    /// @param stUpdatedHardwareEngineerDto New data to update(Id specified is used to update the target hardware engineer user).
    bool Update(const HardwareEngineerUpdateDto& stUpdatedHardwareEngineerDto);
    
    /// @brief Removes the hardware engineer user with specified hardware engineer user id.
    /// @param nId Id to of the hardware engineer user to remove.
    bool RemoveById(int nId);
    
    private:
    /// @brief Data context to update.
    IUserDbContext* m_cUserDbContext;

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

    /// @brief Convert update hardware engineer dto to user object.
    /// @param stHardwareEngineerUpdateDto Update dto of hardware engineer user.
    /// @return User object created using the given update dto of hardware engineer dto.
    CUser ConvertToUser(HardwareEngineerUpdateDto stHardwareEngineerUpdateDto)
    {
        std::unique_ptr<HardwareEngineerProfile> cRoleData 
            = std::make_unique<HardwareEngineerProfile>(stHardwareEngineerUpdateDto.nHardwareUnitCount);

        return CUser(
            stHardwareEngineerUpdateDto.nId,
            stHardwareEngineerUpdateDto.strPassword,
            stHardwareEngineerUpdateDto.strName,
            ROLE::HARDWARE_ENGINEER,
            stHardwareEngineerUpdateDto.ePosition,
            stHardwareEngineerUpdateDto.nSalary,
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