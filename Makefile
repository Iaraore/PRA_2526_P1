# --- Regla principal (compila todo) ---
all: bin/testListArray bin/testListLinked bin/testPoint2D bin/testCircle bin/testRectangle bin/testSquare bin/testDrawing

# --- Reglas para Compilar Objetos (.o) ---

Point2D.o: Point2D.h Point2D.cpp
	g++ -c Point2D.cpp

Shape.o: Shape.h Shape.cpp Point2D.h
	g++ -c Shape.cpp

Circle.o: Circle.h Circle.cpp Shape.h Point2D.h
	g++ -c Circle.cpp

Rectangle.o: Rectangle.h Rectangle.cpp Shape.h Point2D.h
	g++ -c Rectangle.cpp

Square.o: Square.h Square.cpp Rectangle.h Shape.h Point2D.h
	g++ -c Square.cpp

Drawing.o: Drawing.h Drawing.cpp List.h ListArray.h Shape.h Circle.h Square.h Rectangle.h
	g++ -c Drawing.cpp

# --- Reglas para Generar Ejecutables (Tests) ---

bin/testListArray: testListArray.cpp ListArray.h List.h
	mkdir -p bin
	g++ -o bin/testListArray testListArray.cpp

bin/testListLinked: testListLinked.cpp ListLinked.h List.h Node.h
	mkdir -p bin
	g++ -o bin/testListLinked testListLinked.cpp

bin/testPoint2D: testPoint2D.cpp Point2D.o
	mkdir -p bin
	g++ -o bin/testPoint2D testPoint2D.cpp Point2D.o

bin/testCircle: testCircle.cpp Circle.o Shape.o Point2D.o
	mkdir -p bin
	g++ -o bin/testCircle testCircle.cpp Circle.o Shape.o Point2D.o

bin/testRectangle: testRectangle.cpp Rectangle.o Shape.o Point2D.o
	mkdir -p bin
	g++ -o bin/testRectangle testRectangle.cpp Rectangle.o Shape.o Point2D.o

bin/testSquare: testSquare.cpp Square.o Rectangle.o Shape.o Point2D.o
	mkdir -p bin
	g++ -o bin/testSquare testSquare.cpp Square.o Rectangle.o Shape.o Point2D.o

bin/testDrawing: testDrawing.cpp Drawing.o Square.o Rectangle.o Circle.o Shape.o Point2D.o
	mkdir -p bin
	g++ -o bin/testDrawing testDrawing.cpp Drawing.o Square.o Rectangle.o Circle.o Shape.o Point2D.o

# --- Limpieza ---

clean:
	rm -f *.o *.gch
	rm -rf bin

