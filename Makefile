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

VERSION	=	-std=c++2a\

all:
	@(echo "Compiling..." $(NAME))
	@(g++ -o $(NAME) $(DATA_WITHOUT_TEST) $(VERSION)) && echo "Compiling success" || echo "Compiling failed"
	@(mv $(NAME) bin/$(NAME))

compile_test:
	@(echo "Compiling Test...")
	#@(for i in $(DATA_WITH_TEST); do g++ -o $(i:src/Test:Test) $(i) $(VERSION); done)
	@(g++ -o test/Window src/Window/*.cpp $(VERSION)) && echo "Compiling Test success" || echo "Compiling Test failed"

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