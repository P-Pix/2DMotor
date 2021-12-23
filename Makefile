#!bin/bash

DATA	=	src/*.cpp\
			src/Game/*.cpp\
			src/Window/*.cpp\
			src/ImageInterpretor/*.cpp\
			src/Operator/*.cpp\
			src/Pixel/*.cpp\
			src/Sprite/*.cpp\
			src/Stats/*.cpp\

DATA_WITHOUT_TEST	=	src/[^Test]*.cpp\
						src/Game/[^Test]*.cpp\
						src/Window/[^Test]*.cpp\
						src/ImageInterpretor/[^Test]*.cpp\
						src/Operator/[^Test]*.cpp\
						src/Pixel/[^Test]*.cpp\
						src/Sprite/[^Test]*.cpp\
						src/Stats/[^Test]*.cpp\

DATA_WITH_TEST	=	src/Test.cpp\
					src/Game/Test.cpp\
					src/Window/Test.cpp\
					src/ImageInterpretor/Test.cpp\
					src/Operator/Test.cpp\
					src/Pixel/Test.cpp\
					src/Sprite/Test.cpp\
					src/Stats/Test.cpp\

NAME	=	Zelda

FLAGG		=	`sdl-config --cflags --libs`\
				`sdl2-config --cflags --libs`\
				-lSDL2 -lSDL2_image\
				-lsfml-graphics -lsfml-window -lsfml-system\

VERSION	=	-std=c++2a\

all:
	@echo "Compiling..."
	@echo "Total :"
	@make total >/dev/null
	@echo "Window :"
	@make test_window >/dev/null
	@echo "Pixel :"
	@make test_pixel >/dev/null
	#@echo "Game :"
	#@make test_game >/dev/null
	@echo "Main :"
	@make test_main >/dev/null
	@echo "Image Interpretor :"
	@make test_imageinterpretor >/dev/null
	@echo "Sprite :"
	@make test_sprite >/dev/null
	@echo "Stats :"
	@make test_stats >/dev/null
	@echo "Done."

total:
	@(echo "Compiling..." $(NAME))
	@(g++ -o $(NAME) $(DATA_WITHOUT_TEST) $(FLAGG) $(VERSION)) && echo "Compiling success" || echo "Compiling failed"
	@(mv $(NAME) bin/$(NAME))

test_window:
	@(echo "Compiling Test Window...")
	@(g++ -o test/Window src/Window/*.cpp src/Sprite/[^Test]*.cpp src/ImageInterpretor/[^Test]*.cpp src/Pixel/[^Test]*.cpp $(FLAGG) $(VERSION)) && echo "Compiling Test success" || echo "Compiling Test failed"

test_main:
	@(echo "Compiling Test Main...")
	@(g++ -o test/Main src/Test.cpp $(FLAGG) $(VERSION)) && echo "Compiling Test success" || echo "Compiling Test failed"

test_game:
	@(echo "Compiling Test Game...")
	@(g++ -o test/Game src/Game/*.cpp $(FLAGG) $(VERSION)) && echo "Compiling Test success" || echo "Compiling Test failed"

test_pixel:
	@(echo "Compiling Test Pixel...")
	@(g++ -o test/Pixel src/Pixel/*.cpp $(FLAGG) $(VERSION)) && echo "Compiling Test success" || echo "Compiling Test failed"

test_imageinterpretor:
	@(echo "Compiling Test Image Interpretor...")
	@(g++ -o test/ImageInterpretor src/ImageInterpretor/*.cpp src/Pixel/[^Test]*.cpp $(FLAGG) $(VERSION)) && echo "Compiling Test success" || echo "Compiling Test failed"

test_sprite:
	@(echo "Compiling Test Image Sprite...")
	@(g++ -o test/Sprite src/Sprite/*.cpp src/ImageInterpretor/[^Test]*.cpp src/Pixel/[^Test]*.cpp $(FLAGG) $(VERSION)) && echo "Compiling Test success" || echo "Compiling Test failed"

test_stats:
	@(echo "Compiling Test Stats...")
	@(g++ -o test/Stats src/Stats/*.cpp $(FLAGG) $(VERSION)) && echo "Compiling Test success" || echo "Compiling Test failed"

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