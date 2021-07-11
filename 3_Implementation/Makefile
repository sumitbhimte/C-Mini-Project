#Targetname : dependencies
#<TAB>command

TEST_PROJ_NAME = BankManagementSystem
BUILD_DIR = Build
CFLAGS = -Wall -g

#All the Source File
SRC = main.c\
      src/*.c

#Include folder path
INC = inc


$(BUILD_DIR):
	mkdir $(BUILD_DIR)

INC_TEST = -Iinc -Iunity
#Library Inlcudes
INCLUDE_LIBS = 

OUTPUT = $(BUILD_DIR)/$(TEST_PROJ_NAME).$(EXEC)

TEST_SRC = src/*c\
test/test_bankManagementSystem.c\
unity/unity.c\

TEST_OUTPUT = $(BUILD_DIR)/Test_$(TEST_PROJ_NAME).$(EXEC)

#check if the OS is Windows or Linux and set the executable file extension 
#and delete command accordingly
ifdef OS
   RM = del /q
   FixPath = $(subst /,\,$1)
   EXEC = exe
else
   ifeq ($(shell uname), Linux)
      RM = rm -rf
      FixPath = $1
	  EXEC = out
   endif
endif

# compile the program and generate the .exe or .out file
all : $(SRC) $(BUILD_DIR)
	gcc -I $(INC) $(SRC) -o $(call FixPath,$(OUTPUT))
    #gcc $^ -I$(INC) -o $@   

#execute the program
run : all
	$(call FixPath,$(OUTPUT))
    #./all.exe

# Remove all the built files, invoke by `make clean
clean :
	$(RM) $(call FixPath,$(BUILD_DIR)/*)
    #del all.exe

#valgrind only works in wsl 
#In windows use Dr.Memory
#check the heap memory usage 
valgrind :
	valgrind $(call FixPath,$(TEST_OUTPUT))

#Code Coverage Check
coverageCheck:$(BUILD_DIR)
	g++ -fprofile-arcs -ftest-coverage -fPIC -O0 $(SRC) $(INC) -o $(OUTPUT)
	./$(OUTPUT)

#test the testcases 
test:$(BUILD_DIR)
	gcc $(TEST_SRC) $(INC_TEST) -o $(TEST_OUTPUT) $(INCLUDE_LIBS)
	./$(TEST_OUTPUT)

