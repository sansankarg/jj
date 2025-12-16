INCLUDE = -I INCLUDE
CXXFLAGS = -g -O0 -Wall -Wextra -std=c++17
TARGET = app.exe
BUILDS = build
SRC = src/entity

all: $(BUILDS)/$(TARGET)

$(BUILDS)/$(TARGET): $(BUILDS)/main.o $(BUILDS)/User.o $(BUILDS)/HardwareEngineerData.o $(BUILDS)/UserRepository.o $(BUILDS)/HardwareEngineerService.o $(BUILDS)/SoftwareEngineerService.o $(BUILDS)/ManagementStaffService.o $(BUILDS)/UserSeeder.o $(BUILDS)/ServiceProvider.o $(BUILDS)/EmployeeService.o $(BUILDS)/ConsoleUi.o $(BUILDS)/UserManager.o $(BUILDS)/UserInputValidator.o $(BUILDS)/AuthService.o $(BUILDS)/AuthController.o $(BUILDS)/AuthPolicy.o
	$(CXX) $(CXXFLAGS) $(BUILDS)/main.o $(BUILDS)/User.o $(BUILDS)/HardwareEngineerData.o $(BUILDS)/UserRepository.o $(BUILDS)/HardwareEngineerService.o $(BUILDS)/SoftwareEngineerService.o $(BUILDS)/ManagementStaffService.o $(BUILDS)/UserSeeder.o $(BUILDS)/ServiceProvider.o $(BUILDS)/EmployeeService.o $(BUILDS)/ConsoleUi.o $(BUILDS)/UserManager.o $(BUILDS)/UserInputValidator.o $(BUILDS)/AuthService.o $(BUILDS)/AuthController.o $(BUILDS)/AuthPolicy.o -o $(BUILDS)/$(TARGET)

$(BUILDS)/main.o: src/main.cpp | $(BUILDS)
	$(CXX) $(CXXFLAGS)  $(INCLUDE) -c src/main.cpp -o $(BUILDS)/main.o

$(BUILDS)/User.o: src/entity/User.cpp | $(BUILDS)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c src/entity/User.cpp -o $(BUILDS)/User.o

$(BUILDS)/HardwareEngineerData.o: src/entity/HardwareEngineerData.cpp | $(BUILDS)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c src/entity/HardwareEngineerData.cpp -o $(BUILDS)/HardwareEngineerData.o

$(BUILDS)/UserRepository.o: src/repositories/UserRepository.cpp | $(BUILDS)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c src/repositories/UserRepository.cpp -o $(BUILDS)/UserRepository.o

$(BUILDS)/EmployeeService.o: src/services/EmployeeService.cpp | $(BUILDS)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c src/services/EmployeeService.cpp -o $(BUILDS)/EmployeeService.o

$(BUILDS)/HardwareEngineerService.o: src/services/HardwareEngineerService.cpp | $(BUILDS)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c src/services/HardwareEngineerService.cpp -o $(BUILDS)/HardwareEngineerService.o

$(BUILDS)/SoftwareEngineerService.o: src/services/SoftwareEngineerService.cpp | $(BUILDS)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c src/services/SoftwareEngineerService.cpp -o $(BUILDS)/SoftwareEngineerService.o

$(BUILDS)/ManagementStaffService.o: src/services/ManagementStaffService.cpp | $(BUILDS)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c src/services/ManagementStaffService.cpp -o $(BUILDS)/ManagementStaffService.o

$(BUILDS)/UserSeeder.o: src/seeder/UserSeeder.cpp | $(BUILDS)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c src/seeder/UserSeeder.cpp -o $(BUILDS)/UserSeeder.o

$(BUILDS)/ServiceProvider.o: src/services/ServiceProvider.cpp | $(BUILDS)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c src/services/ServiceProvider.cpp -o $(BUILDS)/ServiceProvider.o

$(BUILDS)/ConsoleUi.o: src/ui/ConsoleUi.cpp | $(BUILDS)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c src/ui/ConsoleUi.cpp -o $(BUILDS)/ConsoleUi.o

$(BUILDS)/UserInputValidator.o: src/validators/UserInputValidator.cpp | $(BUILDS)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c src/validators/UserInputValidator.cpp -o $(BUILDS)/UserInputValidator.o

$(BUILDS)/UserManager.o: src/controllers/UserManager.cpp | $(BUILDS)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c src/controllers/UserManager.cpp -o $(BUILDS)/UserManager.o

$(BUILDS)/AuthController.o: src/controllers/AuthController.cpp | $(BUILDS)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c src/controllers/AuthController.cpp -o $(BUILDS)/AuthController.o

$(BUILDS)/AuthService.o: src/services/AuthService.cpp | $(BUILDS)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c src/services/AuthService.cpp -o $(BUILDS)/AuthService.o

$(BUILDS)/AuthPolicy.o: src/policies/AuthPolicy.cpp | $(BUILDS)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c src/policies/AuthPolicy.cpp -o $(BUILDS)/AuthPolicy.o


$(BUILDS):
	mkdir $(BUILDS)

clean:
	rm -f $(BUILDS)/*.o $(builds)/$(TARGET)

.PHONY: all clean
