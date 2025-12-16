#ifndef EMPLOYEE_REPOSITORY_HPP
#define EMPLOYEE_REPOSITORY_HPP

#include<iostream>
#include<memory>
#include<vector>
#include<functional>
#include<optional>
#include "entity/User.hpp"
#include "repositories/IUserRepository.hpp"
#include "dto/EmployeeDto.hpp"

class CEmployeeService
{
    public:
    /// @brief Creates a new instance of the hardware engineer repository.
    /// @param cUserDbContext 
    CEmployeeService(IUserRepository* iUserRepository);

    /// @brief Retrieves the matched employee users with the specified expression.
    /// @param Expression Expression used to match with the employee users.
    /// @return Vector of matched employee users.
    std::vector<EmployeeDto> Find(const std::function<bool(const EmployeeDto&)>& Expression) const;

    /// @brief Determines whether any employee users matches with the specified expression.
    /// @param Expression Expression used to match with the employee users.
    /// @return true of a matched employee user found; false otherwise.
    bool Any(const std::function<bool(const EmployeeDto&)>& Expression) const;

    /// @brief Retrieves all the employee users.
    /// @return vector of all the employee users.
    std::vector<EmployeeDto> GetAll() const;

    /// @brief Retrieve the employee user with specified id.
    /// @param nId Id of the employee user to retrieve.
    /// @return Hardware engineer user with the specified id.
    std::optional<EmployeeDto> GetById(int nId) const;

    /// @brief Update the target employee user with new position.
    void UpdatePosition(int nId, POSITION ePosition);

    /// @brief Update the target employee user with new salary.
    void UpdateSalary(int nId, int nSalary);

    /// @brief Removes the employee user with specified employee user id.
    /// @param nId Id to of the employee user to remove.
    bool RemoveById(int nId);

    private:
    /// @brief Data context to update.
    IUserRepository* m_iUserRepository;

    /// @brief Convert employee user instance to hardware engineer dto.
    /// @param ptrHardwareEngineerUser User instance of employee user.
    /// @return Employee dto created using the given user object of hardware engineer dto.
    EmployeeDto ConvertToDto(const CUser* ptrEmployeeUser) const
    {
        return EmployeeDto{
            ptrEmployeeUser->GetId(),
            ptrEmployeeUser->GetName(),
            ptrEmployeeUser->GetRole(),
            ptrEmployeeUser->GetPosition(),
            ptrEmployeeUser->GetSalary()
        };  
    }
};

#endif