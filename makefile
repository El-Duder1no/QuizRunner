FLAGS = -Wall -Werror --std=c++11

EXE = bin/QuizRunner
TEST = bin/test

DIR_SRC = build/src
DIR_TEST = build/test

all: $(EXE)

$(EXE): $(DIR_SRC)/main.o $(DIR_SRC)/binSearch.o $(DIR_SRC)/parseString.o $(DIR_SRC)/screenFunctions.o $(DIR_SRC)/selectSort.o $(DIR_SRC)/signInOut.o $(DIR_SRC)/adminMenu.o $(DIR_SRC)/parseForTXT.o $(DIR_SRC)/testFunctions.o $(DIR_SRC)/userMenu.o
	g++ $(FLAGS) $(DIR_SRC)/main.o $(DIR_SRC)/binSearch.o $(DIR_SRC)/parseString.o $(DIR_SRC)/screenFunctions.o $(DIR_SRC)/selectSort.o $(DIR_SRC)/signInOut.o $(DIR_SRC)/adminMenu.o $(DIR_SRC)/parseForTXT.o $(DIR_SRC)/testFunctions.o $(DIR_SRC)/userMenu.o

$(DIR_SRC)/main.o: src/main.cpp
	g++ $(FLAGS) -c src/main.cpp -o $(DIR_SRC)/main.o
$(DIR_SRC)/binSearch.o: src/binSearch.cpp
	g++ $(FLAGS) -c src/binSearch.cpp -o $(DIR_SRC)/binSearch.o
$(DIR_SRC)/parseString.o: src/parseString.cpp
	g++ $(FLAGS) -c src/parseString.cpp -o $(DIR_SRC)/parseString.o
$(DIR_SRC)/screenFunctions.o: src/screenFunctions.cpp
	g++ $(FLAGS) -c src/screenFunctions.cpp -o $(DIR_SRC)/screenFunctions.o	
$(DIR_SRC)/selectSort.o: src/selectSort.cpp
	g++ $(FLAGS) -c src/selectSort.cpp -o $(DIR_SRC)/selectSort.o	
$(DIR_SRC)/signInOut.o: src/signInOut.cpp
	g++ $(FLAGS) -c src/signInOut.cpp -o $(DIR_SRC)/signInOut.o	
$(DIR_SRC)/adminMenu.o: src/adminMenu.cpp
	g++ $(FLAGS) -c src/adminMenu.cpp -o $(DIR_SRC)/adminMenu.o	
$(DIR_SRC)/parseForTXT.o: src/parseForTXT.cpp
	g++ $(FLAGS) -c src/parseForTXT.cpp -o $(DIR_SRC)/parseForTXT.o	
$(DIR_SRC)/testFunctions.o: src/testFunctions.cpp
	g++ $(FLAGS) -c src/testFunctions.cpp -o $(DIR_SRC)/testFunctions.o	
$(DIR_SRC)/userMenu.o: src/userMenu.
	g++ $(FLAGS) -c src/userMenu.cpp -o $(DIR_SRC)/userMenu.o	

clean:
	rm -rf $(DIR_SRC)/*.o
	rm -rf %(DIR_TEST)/*.o
	rm bin/*.exe