GCC = g++
GXX = $(GCC)

STD = -std=c++11
FLAGS = -Wall
ifdef DEBUG
	FLAGS += -DDEBUG
endif

# SFML = -lsfml-graphics -lsfml-window -lsfml-system

COMPILE = $(GXX) $(STD) $(FLAGS)

SRC = src
OBJ = obj
BUILDS = bin
TESTS = tests

all: labo02 compile_tests

# cmake: CMakeLists.txt
# 	mkdir cmake && cd cmake && cmake .. && make

OBJECT =  $(OBJ)/color.o $(OBJ)/circle.o $(OBJ)/square.o $(OBJ)/triangle.o $(OBJ)/rectangle.o
# HEADERS = $(SRC)/color.h $(SRC)/circle.h $(SRC)/square.h $(SRC)/triangle.h $(SRC)/rectangle.h
# OBJECT = -Lobj
HEADERS = -Isrc

main: labo02

compile_tests: test_circle test_rectangle test_square test_triangle

clean: obj_dir
	rm -f $(OBJ)/*

documentation:
	mkdir -p doc && cd doc && mkdir -p doxy && doxygen Doxyfile && make -C doxy/latex && cp doxy/latex/refman.pdf doc.pdf

build_dir:
	mkdir -p $(BUILDS)

obj_dir:
	mkdir -p $(OBJ)

setup: build_dir obj_dir

labo02: setup color.o circle.o square.o triangle.o rectangle.o labo_02_comte_bruno_gallay_david.cpp
	$(COMPILE) $(OBJECT) $(HEADERS) labo_02_comte_bruno_gallay_david.cpp -o labo02

# labo02: setup geometry.o labo02.o
# 	$(COMPILE) $(SRC)/geometry.h $(OBJ)/geometry.o $(OBJ)/labo02.o -o $(BUILDS)/labo02

# # TESTS

test_circle: $(TESTS)/test_circle.cpp color.o circle.o
	$(COMPILE) $(SRC)/color.h $(SRC)/circle.h $(OBJ)/color.o $(OBJ)/circle.o $(TESTS)/test_circle.cpp -o $(BUILDS)/test_circle

test_rectangle: $(TESTS)/test_rectangle.cpp color.o rectangle.o
	$(COMPILE) $(SRC)/color.h $(SRC)/rectangle.h $(OBJ)/color.o $(OBJ)/rectangle.o $(TESTS)/test_rectangle.cpp -o $(BUILDS)/test_rectangle

test_square: $(TESTS)/test_square.cpp color.o square.o
	$(COMPILE) $(SRC)/color.h $(SRC)/square.h $(OBJ)/color.o $(OBJ)/square.o $(TESTS)/test_square.cpp -o $(BUILDS)/test_square

test_triangle: $(TESTS)/test_triangle.cpp color.o triangle.o
	$(COMPILE) $(SRC)/color.h $(SRC)/triangle.h $(OBJ)/color.o $(OBJ)/triangle.o $(TESTS)/test_triangle.cpp -o $(BUILDS)/test_triangle

# test_point_set: $(TESTS)/test_point_set.cpp geometry.o
# 	$(COMPILE) src/geometry.h $(OBJ)/geometry.o $(TESTS)/test_point_set.cpp -o $(BUILDS)/test_point_set
