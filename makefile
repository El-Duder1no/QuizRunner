FLAGS = -Wall -Werror --std=c++11
CXX += -g -Wall -Wextra -pthread -std=c++17

OBJ = g++ $(FLAGS) -c $^ -o $@
OBJ_TEST = $(CXX) -I $^ -o $@

EXE = bin/QuizRunner
TEST = bin/test

DIR_SRC = build/src
DIR_TEST = build/test

GTEST_DIR = thirdparty/googletest
LD_FLAGS = -L $(GTEST_D)/lib -lgtest_main -lpthread
CFLAG += -isystem $(GTEST_DIR)/include


all: $(EXE) $(TEST)

.PHONY: clean all

$(EXE): $(DIR_SRC)/main.o $(DIR_SRC)/binSearch.o $(DIR_SRC)/parseString.o $(DIR_SRC)/screenFunctions.o $(DIR_SRC)/selectSort.o $(DIR_SRC)/signInOut.o $(DIR_SRC)/adminMenu.o $(DIR_SRC)/parseForTXT.o $(DIR_SRC)/testFunctions.o $(DIR_SRC)/userMenu.o
	g++ $(FLAGS) $^ -o $@

$(TEST): $(DIR_TEST)/test.o
	$(CXX) $(CFLAG) $(LD_FLAGS) $^ -o $@
$(DIR_TEST)/test.o: test/test.cpp
	$(CXX) $(CFLAG) -I $(GTEST_DIR)/include -I src -c test/test.cpp -o $(DIR_TEST)/test.o
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

clean:
	rm -rf $(DIR_SRC)/*.o
	rm -rf %(DIR_TEST)/*.o
	rm bin/*.exe