

program: Main.o
	$(CXX) -o program Main.o Calculator.o Matrix.o

Main.o: Calculator.o
	$(CXX) -c -o Main.o main.cpp

Calculator.o: Matrix.o calculator.h
	$(CXX) -c -o Calculator.o Calculator.cpp

Matrix.o : matrix.h
	$(CXX) -c -o Matrix.o Matrix.cpp

clean:
	rm *.o
	rm program
	rm HW01_skodaji4.tar.gz

zip:
	tar -czvf HW01_skodaji4.tar.gz ./calculator.h ./colours.h ./errors.h ./matrix.h ./operations.h ./Calculator.cpp ./main.cpp ./Matrix.cpp ./Makefile