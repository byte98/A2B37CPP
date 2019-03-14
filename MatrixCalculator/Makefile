CFLAGS += -Wall

program: Main.o Matrix.o
	$(CXX) $(CFLAGS) -o program Main.o Matrix.o

Main.o: Main.cpp Matrix.h
	$(CXX) $(CFLAGS) -c Main.cpp


Matrix.o : Matrix.h

clean:
	rm *.o
	rm program
