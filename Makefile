#!bin/bash

DATA	=	src/*.cpp\
			src/Game/*.cpp\
			src/Window/*.cpp\

DATA_WITHOUT_TEST	=	src/[^Test]*.cpp\
						src/Game/[^Test]*.cpp\
						src/Window/[^Test]*.cpp\

DATA_WITH_TEST	=	src/Test.cpp\
					src/Game/Test.cpp\
					src/Window/Test.cpp\

NAME	=	Zelda

FLAGG		=	`sdl-config --cflags --libs`\
				`sdl2-config --cflags --libs`\

VERSION	=	-std=c++2a\

all:
	@(echo "Compiling..." $(NAME))
	@(g++ -o $(NAME) $(DATA_WITHOUT_TEST) $(VERSION)) && echo "Compiling success" || echo "Compiling failed"
	@(mv $(NAME) bin/$(NAME))

test_window:
	@(echo "Compiling Test Window...")
	@(g++ -o test/Window src/Window/*.cpp $(FLAGG) $(VERSION)) && echo "Compiling Test success" || echo "Compiling Test failed"

test_main:
	@(echo "Compiling Test Main...")
	@(g++ -o test/Main src/Test.cpp $(FLAGG) $(VERSION)) && echo "Compiling Test success" || echo "Compiling Test failed"

test_game:
	@(echo "Compiling Test Game...")
	@(g++ -o test/Game src/Game/*.cpp $(FLAGG) $(VERSION)) && echo "Compiling Test success" || echo "Compiling Test failed"

test_pixel:
	@(echo "Compiling Test Pixel...")
	@(g++ -o test/Pixel src/Pixel/*.cpp $(FLAGG) $(VERSION)) && echo "Compiling Test success" || echo "Compiling Test failed"

delete:
	@(echo "Deleting...")
	@(rm -rf bin/*)
	@(rm -rf test/*)
	@(echo "Deleting success")

run:
	@(echo "Running...")
	@(./bin/$(NAME))
	@(echo "Running success")

run_test:
	@(echo "Running Test...")
	@(./test/Main $(ARGS))
	@(echo "Running Test success")