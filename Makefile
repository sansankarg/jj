INCLUDE = -I INCLUDE
TARGET = app.exe
BUILDS = build
SRC = src/entity

all: $(BUILDS)/$(TARGET)

$(BUILDS)/$(TARGET): $(BUILDS)/main.o $(BUILDS)/User.o $(BUILDS)/HardwareEngineerData.o $(BUILDS)/UserDbContext.o $(BUILDS)/HardwareEngineerRepository.o $(BUILDS)/SoftwareEngineerRepository.o $(BUILDS)/ManagementStaffRepository.o $(BUILDS)/UserSeeder.o $(BUILDS)/RepositoryProvider.o $(BUILDS)/EmployeeRepository.o $(BUILDS)/ConsoleUi.o $(BUILDS)/UserManager.o
	$(CXX) $(BUILDS)/main.o $(BUILDS)/User.o $(BUILDS)/HardwareEngineerData.o $(BUILDS)/UserDbContext.o $(BUILDS)/HardwareEngineerRepository.o $(BUILDS)/SoftwareEngineerRepository.o $(BUILDS)/ManagementStaffRepository.o $(BUILDS)/UserSeeder.o $(BUILDS)/RepositoryProvider.o $(BUILDS)/EmployeeRepository.o $(BUILDS)/ConsoleUi.o $(BUILDS)/UserManager.o -o $(BUILDS)/$(TARGET)

$(BUILDS)/main.o: src/main.cpp | $(BUILDS)
	$(CXX) $(INCLUDE) -c src/main.cpp -o $(BUILDS)/main.o

$(BUILDS)/User.o: src/entity/User.cpp | $(BUILDS)
	$(CXX) $(INCLUDE) -c src/entity/User.cpp -o $(BUILDS)/User.o

$(BUILDS)/HardwareEngineerData.o: src/entity/HardwareEngineerData.cpp | $(BUILDS)
	$(CXX) $(INCLUDE) -c src/entity/HardwareEngineerData.cpp -o $(BUILDS)/HardwareEngineerData.o

$(BUILDS)/UserDbContext.o: src/contexts/UserDbContext.cpp | $(BUILDS)
	$(CXX) $(INCLUDE) -c src/contexts/UserDbContext.cpp -o $(BUILDS)/UserDbContext.o

$(BUILDS)/EmployeeRepository.o: src/repositories/EmployeeRepository.cpp | $(BUILDS)
	$(CXX) $(INCLUDE) -c src/repositories/EmployeeRepository.cpp -o $(BUILDS)/EmployeeRepository.o

$(BUILDS)/HardwareEngineerRepository.o: src/repositories/HardwareEngineerRepository.cpp | $(BUILDS)
	$(CXX) $(INCLUDE) -c src/repositories/HardwareEngineerRepository.cpp -o $(BUILDS)/HardwareEngineerRepository.o

$(BUILDS)/SoftwareEngineerRepository.o: src/repositories/SoftwareEngineerRepository.cpp | $(BUILDS)
	$(CXX) $(INCLUDE) -c src/repositories/SoftwareEngineerRepository.cpp -o $(BUILDS)/SoftwareEngineerRepository.o

$(BUILDS)/ManagementStaffRepository.o: src/repositories/ManagementStaffRepository.cpp | $(BUILDS)
	$(CXX) $(INCLUDE) -c src/repositories/ManagementStaffRepository.cpp -o $(BUILDS)/ManagementStaffRepository.o

$(BUILDS)/UserSeeder.o: src/seeder/UserSeeder.cpp | $(BUILDS)
	$(CXX) $(INCLUDE) -c src/seeder/UserSeeder.cpp -o $(BUILDS)/UserSeeder.o

$(BUILDS)/RepositoryProvider.o: src/repositories/RepositoryProvider.cpp | $(BUILDS)
	$(CXX) $(INCLUDE) -c src/repositories/RepositoryProvider.cpp -o $(BUILDS)/RepositoryProvider.o

$(BUILDS)/ConsoleUi.o: src/ui/ConsoleUi.cpp | $(BUILDS)
	$(CXX) $(INCLUDE) -c src/ui/ConsoleUi.cpp -o $(BUILDS)/ConsoleUi.o

$(BUILDS)/UserManager.o: src/controllers/UserManager.cpp | $(BUILDS)
	$(CXX) $(INCLUDE) -c src/controllers/UserManager.cpp -o $(BUILDS)/UserManager.o

$(BUILDS):
	mkdir $(BUILDS)

clean:
	rm -f $(BUILDS)/*.o $(builds)/$(TARGET)

.PHONY: all clean
