#ifndef USER_INPUT_VALIDATOR_HPP
#define USER_INPUT_VALIDATOR_HPP

#include<iostream>
#include<string>
#include<regex>

class CUserInputValidator
{
public:
    CUserInputValidator() = default;

    bool IsValidName(const std::string& strName) const;
    bool IsValidSalary(int nSalary) const;
    bool IsValidHardwareUnits(int nHardwareUnits) const;
    bool IsValidPassword(const std::string& strPassword) const;
};


#endif