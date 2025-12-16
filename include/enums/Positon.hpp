#ifndef POSITION_HPP
#define POSITION_HPP

/// @brief Represents a position of an employee.
enum class POSITION
{
    SENIOR,
    JUNIOR
};

/// @brief Converts the position enum to string.
/// @param role Enum value to convert.
/// @return string representation of given enum.
inline std::string to_string(POSITION p)
{
    switch (p)
    {
        case POSITION::SENIOR: return "SENIOR";
        case POSITION::JUNIOR: return "JUNIOR";
        default: return "UNKNOWN";
    }
}

#endif