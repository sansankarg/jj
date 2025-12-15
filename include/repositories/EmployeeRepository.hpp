#ifndef EMPLOYEE_REPOSITORY_HPP
#define EMPLOYEE_REPOSITORY_HPP

#include<iostream>
#include<memory>
#include<vector>
#include<functional>
#include<optional>
#include "entity/User.hpp"
#include "contexts/IUserDbContext.hpp"
#include "dto/EmployeeDto.hpp"

class CEmployeeRepository
{
    public:
    /// @brief Creates a new instance of the hardware engineer repository.
    /// @param cUserDbContext 
    CEmployeeRepository(IUserDbContext* cUserDbContext);

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

    private:
    /// @brief Data context to update.
    IUserDbContext* m_cUserDbContext;

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