#ifndef ROLE_HPP
#define ROLE_HPP

/// @brief Represents a role of an employee.
enum class ROLE
{
    MANAGEMENT_STAFF,
    HARDWARE_ENGINEER,
    SOFTWARE_ENGINEER,
};

/// @brief Converts the role enum to string.
/// @param role Enum value to convert.
/// @return string representation of given enum.
inline std::string_view to_string(ROLE role)
{
    switch (role)
    {
        case ROLE::MANAGEMENT_STAFF:  return "MANAGEMENT_STAFF";
        case ROLE::HARDWARE_ENGINEER: return "HARDWARE_ENGINEER";
        case ROLE::SOFTWARE_ENGINEER: return "SOFTWARE_ENGINEER";
        default: return "UNKNOWN_ROLE";
    }
}

#endif