EXE = bin/QuizRunner
TEST = bin/test

DIR_SRC = build/src
DIR_TEST = build/test

GTEST_DIR = thirdparty/googletest
GFLAGS += -isystem $(GTEST_DIR)/include
LDFLAGS += -g -Wall -Wextra -pthread --std=c++17

FLAGS = -Wall -Werror --std=c++11
TEST_FLAGS = g++ $(GFLAGS) $(LDFLAGS) -L$(GTEST_DIR)/lib -l gtest_main -l gtest -lpthread

OBJ = g++ $(FLAGS) -c $^ -o $@
OBJ-TEST = g++ $(GFLAGS) $(LDFLAGS) -I src -c $^ -o $@

all: $(EXE) $(TEST)

.PHONY: clean all

$(EXE): $(DIR_SRC)/main.o $(DIR_SRC)/binSearch.o $(DIR_SRC)/parseString.o $(DIR_SRC)/screenFunctions.o $(DIR_SRC)/selectSort.o $(DIR_SRC)/signInOut.o $(DIR_SRC)/adminMenu.o $(DIR_SRC)/parseForTXT.o $(DIR_SRC)/testFunctions.o $(DIR_SRC)/userMenu.o $(DIR_SRC)/resultsParse.o $(DIR_SRC)/testPassing.o
	g++ $(FLAGS) $^ -o $@

$(TEST): $(DIR_TEST)/signInOut-TEST.o $(DIR_SRC)/binSearch.o $(DIR_SRC)/parseString.o $(DIR_SRC)/selectSort.o $(DIR_SRC)/signInOut.o $(DIR_SRC)/screenFunctions.o $(DIR_TEST)/resultParse-TEST.o $(DIR_SRC)/resultsParse.o $(DIR_SRC)/testFunctions.o $(DIR_SRC)/parseForTXT.o
	$(TEST_FLAGS) $^ -o $@
	
$(DIR_TEST)/signInOut-TEST.o: test/signInOut-TEST.cpp
	$(OBJ-TEST)
	
$(DIR_TEST)/resultParse-TEST.o: test/resultParse-TEST.cpp
	$(OBJ-TEST)

$(DIR_TEST)/checkPath-TEST.o: test/checkPath-TEST.cpp
	$(OBJ-TEST)
	
$(DIR_SRC)/main.o: src/main.cpp
	$(OBJ)
$(DIR_SRC)/binSearch.o: src/binSearch.cpp
	$(OBJ)
$(DIR_SRC)/parseString.o: src/parseString.cpp
	$(OBJ)
$(DIR_SRC)/screenFunctions.o: src/screenFunctions.cpp
	$(OBJ)
$(DIR_SRC)/selectSort.o: src/selectSort.cpp
	$(OBJ)
$(DIR_SRC)/signInOut.o: src/signInOut.cpp
	$(OBJ)
$(DIR_SRC)/adminMenu.o: src/adminMenu.cpp
	$(OBJ)
$(DIR_SRC)/parseForTXT.o: src/parseForTXT.cpp
	$(OBJ)
$(DIR_SRC)/testFunctions.o: src/testFunctions.cpp
	$(OBJ)
$(DIR_SRC)/userMenu.o: src/userMenu.cpp
	$(OBJ)
$(DIR_SRC)/resultsParse.o: src/resultsParse.cpp
	$(OBJ)
$(DIR_SRC)/testPassing.o: src/testPassing.cpp
	$(OBJ)

clean:
	rm -rf $(DIR_SRC)/*.o
	rm -rf $(DIR_TEST)/*.o
	rm bin/*.exe