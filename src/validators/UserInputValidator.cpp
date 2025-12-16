#include "validators/UserInputValidator.hpp"

bool CUserInputValidator::IsValidName(const std::string& strName) const
{
    std::regex pattern("[A-Za-z ]+");
    return std::regex_match(strName, pattern);
}

bool CUserInputValidator::IsValidSalary(int nSalary) const
{
    return nSalary > 0;
}

bool CUserInputValidator::IsValidHardwareUnits(int nHardwareUnits) const
{
    return nHardwareUnits >= 0;
}

bool CUserInputValidator::IsValidPassword(const std::string& strPassword) const
{
    static const std::regex pattern(
        R"(^(?=.*[a-z])(?=.*[A-Z])(?=.*\d)(?=.*[@$!%*?&#^()_+\-=\[\]{};':"\\|,.<>\/])[A-Za-z\d@$!%*?&#^()_+\-=\[\]{};':"\\|,.<>\/]{8,}$)"
    );

    return std::regex_match(strPassword, pattern);
}
