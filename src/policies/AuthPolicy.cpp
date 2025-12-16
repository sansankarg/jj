#include "policies/AuthPolicy.hpp"

bool AuthPolicy::IsAllowed(ACTION eAction, AuthSessionDto stAuthSessionDto)
{
    switch (stAuthSessionDto.eRole)
    {
        case ROLE::MANAGEMENT_STAFF:
            return true;

        case ROLE::HARDWARE_ENGINEER:
        case ROLE::SOFTWARE_ENGINEER:
            switch (eAction)
            {
                case ACTION::VIEW_EMPLOYEE:
                case ACTION::SEARCH_EMPLOYEE:
                    return true;
                case ACTION::ADD_EMPLOYEE:
                case ACTION::UPDATE_EMPLOYEE:
                    return false;
                default:
                    return false;
            }

        default:
            return false;
    }
}