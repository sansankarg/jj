#include "controllers/AuthController.hpp"

#include "services/ServiceProvider.hpp"
#include "ui/ConsoleUi.hpp"
#include "validators/UserInputValidator.hpp"
#include "dto/LoginRequestDto.hpp"
#include "dto/AuthSession.hpp"

CAuthController::CAuthController(ConsoleUI cConsoleUI, CServiceProvider cServiceProvider, CUserInputValidator CUserInputValidator)
        :m_cConsoleUI(cConsoleUI), m_cServiceProvider(cServiceProvider), m_cUserInputValidator(CUserInputValidator)
        { }

AuthSessionDto CAuthController::HandleLogin() 
{
    this->m_cConsoleUI.PromptMessage("\nLogin\n\n");

    while(true)
    {
        int nId= this->m_cConsoleUI
        .PromptForValidInteger(
            "Enter Id : ",
            [this](int nInput)
            {
                return this->m_cServiceProvider.m_cEmployee.Any(
                    [nInput](const EmployeeDto& stEmployeeDto)
                    {
                        return stEmployeeDto.nId == nInput;
                    }
                );
            }
        );

        std::string strpassword = this->m_cConsoleUI
            .PromptForValidString(
                "Enter password : ",
                [this](std::string strName)
                {
                    return this->m_cUserInputValidator.IsValidPassword(strName);
                });

        std::optional<AuthSessionDto> stAuthSessionDto = this->m_cServiceProvider.m_cAuthService.Authenticate(LoginRequestDto(nId, strpassword));
        if(stAuthSessionDto)
        {
            return stAuthSessionDto.value();
        }
        this->m_cConsoleUI.PromptMessage("\nInvalid password or username\n");
    }
}