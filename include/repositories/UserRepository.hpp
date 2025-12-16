#ifndef CUSER_REPOSITORY
#define CUSER_REPOSITORY

#include<iostream>
#include<vector>
#include<memory>
#include<functional>

#include "entity/User.hpp"
#include "repositories/IUserRepository.hpp"

/// @brief It represents a session with the in-memory database and act as a bridge between ap domain and the data base.
class CUserRepository : public IUserRepository
{
    public:

    CUserRepository();

    /// @brief Destroy/release the resources user by the db context
    ~CUserRepository() override = default;

    /// @brief Add a new user to the database.
    /// It will auto generate id for users.
    /// @param NewUser New user to add.
    void Add(CUser NewUser) override;

    /// @brief Retrieves the matched users with the specified expression.
    /// @param Expression Expression used to match with the users.
    /// @return Vector of matched users.
    std::vector<const CUser*> Find(const std::function<bool(const CUser&)>& Expression) const override;

    /// @brief Determines whether any users matches with the specified expression.
    /// @param Expression Expression used to match with the users.
    /// @return true of a matched user found; false otherwise.
    bool Any(const std::function<bool(const CUser&)>& Expression) const override;

    /// @brief Retrieves all the users.
    /// @return vector of all the users.
    std::vector<const CUser*> GetAll() const override;

    /// @brief Retrieve the user with specified id.
    /// @param nId Id of the user to retrieve.
    /// @return User with the specified id.
    const CUser* GetById(int nId) const override;

    /// @brief Update the target user with new salary.
    void UpdatePosition(int nId, POSITION ePosition) override;

    /// @brief Update the target user with new salary.
    void UpdateSalary(int nId, int nSalary) override;

    /// @brief Removes the user with specified user id.
    /// @param nId Id to of the user to remove.
    void RemoveById(int nId) override;

    private:
    /// @brief Vector to store user data in-memory.
    std::vector<std::unique_ptr<CUser>> Users;

    /// @brief used to generate new IDs
    int nNextId;

};

#endif