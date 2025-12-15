#ifndef IUSER_REPOSITORY
#define IUSER_REPOSITORY

#include<iostream>
#include<vector>
#include<memory>
#include<functional>
#include "entity/User.hpp"

/// @brief It represents a session with the database and act as a bridge between app domain and the database.
class IUserDbContext
{
    public:

    /// @brief Destroy/release the resources user by the db context
    virtual ~IUserDbContext() = default;

    /// @brief Add a new user to the database.
    /// @param NewUser New user to add.
    virtual void Add(CUser NewUser)= 0;

    /// @brief Retrieves the matched users with the specified expression.
    /// @param Expression Expression used to match with the users.
    /// @return Vector of matched users.
    virtual std::vector<const CUser*> Find(const std::function<bool(const CUser&)>& Expression) const = 0;

    /// @brief Determines whether any users matehes with the specified expression.
    /// @param Expression Expression used to match with the users.
    /// @return true of a matched user found; false otherwise.
    virtual bool Any(const std::function<bool(const CUser&)>& Expression) const = 0;

    /// @brief Retrieves all the users.
    /// @return vector of all the users.
    virtual std::vector<const CUser*> GetAll() const = 0;

    /// @brief Retrieve the user with specified id.
    /// @param nId Id of the user to retrieve.
    /// @return User with the specified id.
    virtual const CUser* GetById(int nId) const = 0;

    /// @brief Update the target user with new detail.
    /// @param updatedUser New data to update(Id specified is used to update the target user).
    virtual void UpdateUser(CUser updatedUser) = 0;

    /// @brief Removes the user with specified user id.
    /// @param nId Id to of the user to remove.
    virtual void RemoveById(int nId) = 0;
};

#endif