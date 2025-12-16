#include"controllers/UserManager.hpp"

#include<vector>
#include<sstream>

CUserManager::CUserManager(ConsoleUI cConsoleUI, CServiceProvider cServiceProvider, CUserInputValidator CUserInputValidator, AuthPolicy cAuthPolicy)
        :m_cConsoleUI(cConsoleUI), m_cServiceProvider(cServiceProvider), m_cUserInputValidator(CUserInputValidator), m_cAuthPolicy(cAuthPolicy)
        { }

void CUserManager::HandleMenu(AuthSessionDto stAuthSessionDto)
{
    while(true)
    {
        this->m_cConsoleUI.PromptMessage("Home page\n\n");

        this->m_cConsoleUI.PromptMessage(
        "1. View the employee details (By category, Position) and total number of employees\n"
        "2. Add a new employee\n"
        "3. Remove an existing employee by ID\n"
        "4. Update an employee position\n"
        "5. Update an employee salary\n"
        "6. Search employee details by ID or by Position\n"
        "0. Exit\n"
          );


        int nUserChoice = this->m_cConsoleUI.PromptForValidInteger("\n\nEnter your choice : ");
        
        switch(nUserChoice)
        {
            case 1:
                HandleViewEmployee(stAuthSessionDto);
                break;
            case 2:
                HandleAddEmployee(stAuthSessionDto);
                break;
            case 3:
                HandleRemoveEmployee(stAuthSessionDto);
                break;
            case 4:
                HandleUpdatePositionOfEmployee(stAuthSessionDto);
                break;
            case 5:
                HandleUpdateSalaryOfEmployee(stAuthSessionDto);
                break;
            case 6:
                HandleSearchEmployee(stAuthSessionDto);
                break;
            case 0:
                return;
        }
    }
}

void CUserManager::HandleViewEmployee(AuthSessionDto stAuthSessionDto)
{
    if(!this->m_cAuthPolicy.IsAllowed(ACTION::VIEW_EMPLOYEE, stAuthSessionDto))
    {
        this->m_cConsoleUI.PromptMessage("You are not allowed to perform this action !");
        return;
    }
    while(true)
    {
        this->m_cConsoleUI.PromptMessage("View page\n\n");
        this->DisplayAllEmployee();
        this->m_cConsoleUI.PromptMessage(
            "\n1. View the employee details by category\n"
            "2. View the employee details by position\n"
            "3. View total number of employees\n"
            "0. Go back to home\n"
            );

        int nUserChoice = this->m_cConsoleUI.PromptForValidInteger("\n\nEnter your choice : ");

        switch(nUserChoice)
        {
            case 1:
                HandleViewEmployeeByCategory();
                break;
            case 2:
                HandleViewEmployeeByPosition();
                break;
            case 3:
                DisplayTotalNumberOfEmployees();
                break;
            case 0:
                return;
        }
    }
}

void CUserManager::HandleAddEmployee(AuthSessionDto stAuthSessionDto)
{
    if(!this->m_cAuthPolicy.IsAllowed(ACTION::ADD_EMPLOYEE, stAuthSessionDto))
    {
        this->m_cConsoleUI.PromptMessage("You are not allowed to perform this action !");
        return;
    }
    while(true)
    {
        this->m_cConsoleUI.PromptMessage("Add page\n\n");
        this->m_cConsoleUI.PromptMessage(
        "\n1. Add a hardware engineer\n"
        "2. Add a software engineer\n"
        "3. Add a management staff\n"
        "0. Go back to home\n"
        );

        int nUserChoice = this->m_cConsoleUI.PromptForValidInteger("\n\nEnter your choice : ");
        return;

        switch(nUserChoice)
        {
            case 1:
                HandleAddHardwareEngineer();
                break;
            case 2:
                HandleAddSoftwareEngineer();
                break;
            case 3:
                HandleAddManagementStaff();
                break;
            case 0:
                return;
        }
    }
    
}

void CUserManager::HandleRemoveEmployee(AuthSessionDto stAuthSessionDto)
{
    if(!this->m_cAuthPolicy.IsAllowed(ACTION::REMOVE_EMPLOYEE, stAuthSessionDto))
    {
        this->m_cConsoleUI.PromptMessage("You are not allowed to perform this action !");
        return;
    }
    this->m_cConsoleUI.PromptMessage("Remove page\n\n");
    DisplayAllEmployee();
    int nEmployeeIdToRemove = this->m_cConsoleUI.PromptForValidInteger(
        "Enter the ID of the employee to remove : ",
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
    this->m_cServiceProvider.m_cEmployee.RemoveById(nEmployeeIdToRemove);
}

void CUserManager::HandleUpdatePositionOfEmployee(AuthSessionDto stAuthSessionDto)
{
    if(!this->m_cAuthPolicy.IsAllowed(ACTION::UPDATE_EMPLOYEE, stAuthSessionDto))
    {
        this->m_cConsoleUI.PromptMessage("You are not allowed to perform this action !");
        return;
    }
    this->m_cConsoleUI.PromptMessage("Update position page\n\n");
    DisplayAllEmployee();
    int nEmployeeIdToUpdate = this->m_cConsoleUI.PromptForValidInteger(
        "Enter the ID of the employee to update position : ",
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

    POSITION eNewPosition = this->GetEmployeePositionFromUser("Enter the new psoition : ");
    this->m_cServiceProvider.m_cEmployee.UpdatePosition(nEmployeeIdToUpdate, eNewPosition);

}

void CUserManager::HandleUpdateSalaryOfEmployee(AuthSessionDto stAuthSessionDto)
{
    if(!this->m_cAuthPolicy.IsAllowed(ACTION::UPDATE_EMPLOYEE, stAuthSessionDto))
    {
        this->m_cConsoleUI.PromptMessage("You are not allowed to perform this action !");
        return;
    }
    this->m_cConsoleUI.PromptMessage("Update salary page\n\n");
    DisplayAllEmployee();
    int nEmployeeIdToUpdate = this->m_cConsoleUI.PromptForValidInteger(
        "Enter the ID of the employee to update salary : ",
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

    int nNewSalary = this->GetEmployeeSalaryFromUser("Enter new salary to update : ");
    this->m_cServiceProvider.m_cEmployee.UpdateSalary(nEmployeeIdToUpdate, nNewSalary);
}

void CUserManager::HandleSearchEmployee(AuthSessionDto stAuthSessionDto)
{
    if(!this->m_cAuthPolicy.IsAllowed(ACTION::SEARCH_EMPLOYEE, stAuthSessionDto))
    {
        this->m_cConsoleUI.PromptMessage("You are not allowed to perform this action !");
        return;
    }
    this->m_cConsoleUI.PromptMessage("Search page\n\n");
    int nEmployeeIdToSearch = this->m_cConsoleUI.PromptForValidInteger(
        "Enter the ID of the employee to search for : ",
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

    ROLE eMatchedUserRole = this->m_cServiceProvider.m_cEmployee.GetById(nEmployeeIdToSearch).value().eRole;

    switch (eMatchedUserRole)
    {
        case ROLE::HARDWARE_ENGINEER:
        {
            HardwareEngineerDto matchedHardwareEngineerDto =
                this->m_cServiceProvider.m_cHardwareEngineers
                    .GetById(nEmployeeIdToSearch)
                    .value();

            this->m_cConsoleUI.PrintHardwareEngineerTable(
                std::vector<HardwareEngineerDto>{ matchedHardwareEngineerDto }
            );
            break;
        }

        case ROLE::SOFTWARE_ENGINEER:
        {
            SoftwareEngineerDto matchedSoftwareEngineerDto =
                this->m_cServiceProvider.m_cSoftwareEngineers
                    .GetById(nEmployeeIdToSearch)
                    .value();

            this->m_cConsoleUI.PrintSoftwareEngineerTable(
                std::vector<SoftwareEngineerDto>{ matchedSoftwareEngineerDto }
            );
            break;
        }

        case ROLE::MANAGEMENT_STAFF:
        {
            ManagementStaffDto matchedManagementStaffDto =
                this->m_cServiceProvider.m_cManagementStaff
                    .GetById(nEmployeeIdToSearch)
                    .value();

            this->m_cConsoleUI.PrintManagementStaffTable(
                std::vector<ManagementStaffDto>{ matchedManagementStaffDto }
            );
            break;
        }
    }

    }

void CUserManager::HandleViewEmployeeByCategory()
{
    while(true)
    {
        this->m_cConsoleUI.PromptMessage(
        "\n1. View the hardware engineer details\n"
        "2. View the software engineer details\n"
        "3. View the management staff details\n"
        "0. Go back to view all employee\n"
        );

        int nUserChoice = this->m_cConsoleUI.PromptForValidInteger("\nEnter your choice : ");

        switch(nUserChoice)
        {
            case 1:
                DisplayAllHardwareEngineer();
                break;
            case 2:
                DisplayAllSoftwareEngineeer();
                break;
            case 3:
                DisplayAllManagementStaff();
                break;
            case 0:
                return;
        }
    }    
}

void CUserManager::DislayAllEmployeesWithRole(ROLE eRole)
{
    this->m_cConsoleUI.PromptMessage(to_string(eRole));
    std::vector<EmployeeDto> stEmployees = this->m_cServiceProvider.m_cEmployee
        .Find([&eRole](const EmployeeDto& stEmployeeDto)
        {
            return stEmployeeDto.eRole == eRole;
        });

    this->m_cConsoleUI.PrintEmployeeTable(stEmployees);
    this->m_cConsoleUI.PromptForValidInteger("0. Go back", [](int nInput){
        return nInput == 0;
    });
}

void CUserManager::HandleViewEmployeeByPosition()
{
    while(true)
    {
        this->m_cConsoleUI.PromptMessage(
        "1. View the senior employees details\n"
        "2. View the junior emloyees details\n"
        "0. Go back to view all employee\n"
        );

        int nUserChoice = this->m_cConsoleUI.PromptForValidInteger("\nEnter your choice : ");

        switch(nUserChoice)
        {
            case 1:
                DislayAllEmployeesWithRole(ROLE::HARDWARE_ENGINEER);
                break;
            case 2:
                DislayAllEmployeesWithRole(ROLE::SOFTWARE_ENGINEER);
                break;
            case 0:
                return;
        }
    }    
}

void CUserManager::DisplayAllEmployee()
{
    std::vector<EmployeeDto> stEmployees = this->m_cServiceProvider.m_cEmployee.GetAll();
    this->m_cConsoleUI.PrintEmployeeTable(stEmployees);
}

void CUserManager::DisplayAllHardwareEngineer()
{
    std::vector<HardwareEngineerDto> stHardwareEngineers = this->m_cServiceProvider.m_cHardwareEngineers.GetAll();
    this->m_cConsoleUI.PrintHardwareEngineerTable(stHardwareEngineers);
    this->m_cConsoleUI.PromptForValidInteger("0. Go back", [](int nInput){
        return nInput == 0;
    });
}

void CUserManager::DisplayAllSoftwareEngineeer()
{
    std::vector<SoftwareEngineerDto> stSoftwareEngineers = this->m_cServiceProvider.m_cSoftwareEngineers.GetAll();
    this->m_cConsoleUI.PrintSoftwareEngineerTable(stSoftwareEngineers);
    this->m_cConsoleUI.PromptForValidInteger("0. Go back", [](int nInput){
        return nInput == 0;
    });
}

void CUserManager::DisplayAllManagementStaff()
{
    std::vector<ManagementStaffDto> stManagementStaff = this->m_cServiceProvider.m_cManagementStaff.GetAll();
    this->m_cConsoleUI.PrintManagementStaffTable(stManagementStaff);
    this->m_cConsoleUI.PromptForValidInteger("0. Go back", [](int nInput){
        return nInput == 0;
    });
}

void CUserManager::DisplayTotalNumberOfEmployees()
{
    std::ostringstream cTotalNumberOfEmployeesMessage;
    cTotalNumberOfEmployeesMessage << "Total Number of employees "<< this->m_cServiceProvider.m_cEmployee.GetAll().size();
    this->m_cConsoleUI.PromptMessage(cTotalNumberOfEmployeesMessage.str());
    this->m_cConsoleUI.PromptForValidInteger("0. Go back", [](int nInput){
        return nInput == 0;
    });
}

void CUserManager::HandleAddHardwareEngineer()
{
    HardwareEngineerCreateDto stNewHardwareEngineer;
    stNewHardwareEngineer.strName = this->GetNameFromUser("Enter the name of new hardware engineer : ");
    stNewHardwareEngineer.ePosition = this->GetEmployeePositionFromUser("Enter the position of the hardware engnineer : ");
    stNewHardwareEngineer.nSalary = this->GetEmployeeSalaryFromUser("Enter the salary of the new hardware engineer : ");
    stNewHardwareEngineer.nHardwareUnitCount = this->GetHardwareUnitsFromUser("Enter total number of hardware units the new employee holds : ");
    stNewHardwareEngineer.strPassword = stNewHardwareEngineer.strName;

    this->m_cServiceProvider.m_cHardwareEngineers.Add(stNewHardwareEngineer);

    this->m_cConsoleUI.PromptMessage("\n\nNew hardware engineer added successfully");
}

void CUserManager::HandleAddSoftwareEngineer()
{
    SoftwareEngineerCreateDto stNewSoftwareEngineer;
    stNewSoftwareEngineer.strName = this->GetNameFromUser("Enter the name of new software engineer : ");
    stNewSoftwareEngineer.ePosition = this->GetEmployeePositionFromUser("Enter the position of the software engnineer : ");
    stNewSoftwareEngineer.nSalary = this->GetEmployeeSalaryFromUser("Enter the salary of the new software engineer : ");
    stNewSoftwareEngineer.strPassword = stNewSoftwareEngineer.strName;

    this->m_cServiceProvider.m_cSoftwareEngineers.Add(stNewSoftwareEngineer);

    this->m_cConsoleUI.PromptMessage("\n\nNew software engineer added successfully");
}

void CUserManager::HandleAddManagementStaff()
{
    ManagementStaffCreateDto stNewManagementStaff;
    stNewManagementStaff.strName = this->GetNameFromUser("Enter the name of new software engineer : ");
    stNewManagementStaff.ePosition = this->GetEmployeePositionFromUser("Enter the position of the software engnineer : ");
    stNewManagementStaff.nSalary = this->GetEmployeeSalaryFromUser("Enter the salary of the new software engineer : ");
    stNewManagementStaff.strPassword = stNewManagementStaff.strName;

    this->m_cServiceProvider.m_cManagementStaff.Add(stNewManagementStaff);

    this->m_cConsoleUI.PromptMessage("\n\nNew management staff added successfully");
}

std::string CUserManager::GetNameFromUser(std::string strPrompt)
{
    return this->m_cConsoleUI
        .PromptForValidString(
            strPrompt,
            [this](std::string strName)
            {
                return this->m_cUserInputValidator.IsValidName(strName);
            });
}

POSITION CUserManager::GetEmployeePositionFromUser(std::string strPrompt)
{
    this->m_cConsoleUI.PromptMessage(
        "Select position\n\n"
        "1. Senior\n"
        "2. Junior\n"
        );
    int nUserChoice = this->m_cConsoleUI
        .PromptForValidInteger(
            "\n\nEnter your choice  :",
        [](int nChoice)
        {
            return nChoice <= 2 && nChoice >= 1;
        });
    
    POSITION eNewEmployeePosition;
    switch(nUserChoice)
    {
        case 1:
            return POSITION::SENIOR;
        case 2:
            return POSITION::JUNIOR;
    }
    return eNewEmployeePosition;
}

int CUserManager::GetEmployeeSalaryFromUser(std::string strPrompt)
{
    return this->m_cConsoleUI
        .PromptForValidInteger(
            strPrompt,
            [this](int nSalary)
            {
                return this->m_cUserInputValidator.IsValidSalary(nSalary);
            });
}

int CUserManager::GetHardwareUnitsFromUser(std::string strPrompt)
{
    return this->m_cConsoleUI
        .PromptForValidInteger(
            strPrompt,
            [this](int nHardwareUnits)
            {
                return this->m_cUserInputValidator.IsValidHardwareUnits(nHardwareUnits);
            });
}

