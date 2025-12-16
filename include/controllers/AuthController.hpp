#ifndef AUTH_CONTROLLER_HPP
#define AUTH_CONTROLLER_HPP

#include "services/ServiceProvider.hpp"
#include "ui/ConsoleUi.hpp"
#include "validators/UserInputValidator.hpp"
#include "dto/LoginRequestDto.hpp"
#include "dto/AuthSession.hpp"

/// @brief Controller that is reponsible for authentication action such as login.
class CAuthController
{
    public:

    /// @brief Creates a new instance of CAuthController
    /// @param cConsoleUI 
    /// @param cServiceProvider 
    /// @param CUserInputValidator 
    CAuthController(ConsoleUI cConsoleUI, CServiceProvider cServiceProvider, CUserInputValidator CUserInputValidator);

    /// @brief Handle the user login process.
    /// @return AuthSessionDto containing session info of the login.
    AuthSessionDto HandleLogin();

    void ChangePassword();

    private:

    CServiceProvider m_cServiceProvider;
    
    ConsoleUI m_cConsoleUI;

    CUserInputValidator m_cUserInputValidator;

};

#endif