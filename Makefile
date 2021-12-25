#!bin/bash

DATA	=	src/*.cpp\
			\
			src/Sprite/Circle/*.cpp\
			src/Sprite/Drawable/*.cpp\
			src/Sprite/ImageInterpretor/*.cpp\
			src/Sprite/Pixel/*.cpp\
			src/Sprite/Rectangle/*.cpp\
			src/Sprite/Sprite/*.cpp\
			\
			src/Window/Window/*.cpp\

DATA_WITHOUT_TEST	=	src/[^Test]*.cpp\
						\
						src/Sprite/Circle/[^Test]*.cpp\
						src/Sprite/Drawable/[^Test]*.cpp\
						src/Sprite/ImageInterpretor/[^Test]*.cpp\
						src/Sprite/Pixel/[^Test]*.cpp\
						src/Sprite/Rectangle/[^Test]*.cpp\
						src/Sprite/Sprite/[^Test]*.cpp\
						\
						src/Window/Window/[^Test]*.cpp\

DATA_WITH_TEST	=	src/Test.cpp\
					\
					src/Sprite/Circle/Test.cpp\
					src/Sprite/Drawable/Test.cpp\
					src/Sprite/ImageInterpretor/Test.cpp\
					src/Sprite/Pixel/Test.cpp\
					src/Sprite/Rectangle/Test.cpp\
					src/Sprite/Sprite/Test.cpp\
					\
					src/Window/Window/Test.cpp\

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
	@echo "Main :"
	@make test_main >/dev/null
	@echo "Image Interpretor :"
	@make test_imageinterpretor >/dev/null
	@echo "Sprite :"
	@make test_sprite >/dev/null
	@echo "Done."

bin:
	@echo "Compiling..."


test_window:
	@(echo "Compiling Test Window...")
	@(g++ -o test/Window/Window src/Window/Window/*.cpp src/Sprite/Sprite/[^Test]*.cpp src/Sprite/ImageInterpretor/[^Test]*.cpp src/Sprite/Pixel/[^Test]*.cpp $(FLAGG) $(VERSION)) && echo "Compiling Test success" || echo "Compiling Test failed"

test_main:
	@(echo "Compiling Test Main...")
	@(g++ -o test/Main src/Test.cpp $(FLAGG) $(VERSION)) && echo "Compiling Test success" || echo "Compiling Test failed"

test_pixel:
	@(echo "Compiling Test Pixel...")
	@(g++ -o test/Sprite/Pixel src/Sprite/Pixel/*.cpp src/Sprite/Rectangle/[^Test]*.cpp src/Sprite/Drawable/[^Test]*.cpp $(FLAGG) $(VERSION)) && echo "Compiling Test success" || echo "Compiling Test failed"

test_imageinterpretor:
	@(echo "Compiling Test Image Interpretor...")
	@(g++ -o test/Sprite/ImageInterpretor src/Sprite/ImageInterpretor/*.cpp src/Sprite/Pixel/[^Test]*.cpp src/Sprite/Rectangle/[^Test]*.cpp src/Sprite/Drawable/[^Test]*.cpp $(FLAGG) $(VERSION)) && echo "Compiling Test success" || echo "Compiling Test failed"

test_sprite:
	@(echo "Compiling Test Image Sprite...")
	@(g++ -o test/Sprite/Sprite2D src/Sprite/Sprite2D/*.cpp src/Sprite/ImageInterpretor/[^Test]*.cpp src/Sprite/Pixel/[^Test]*.cpp src/Sprite/Rectangle/[^Test]*.cpp src/Sprite/Drawable/[^Test]*.cpp $(FLAGG) $(VERSION)) && echo "Compiling Test success" || echo "Compiling Test failed"

test_drawable:
	@(echo "Compiling Test Drawable...")
	@(g++ -o test/Sprite/Drawable src/Sprite/Drawable/*.cpp $(FLAGG) $(VERSION)) && echo "Compiling Test success" || echo "Compiling Test failed"

test_rectangle:
	@(echo "Compiling Test Rectangle...")
	@(g++ -o test/Sprite/Rectangle src/Sprite/Rectangle/*.cpp src/Sprite/Drawable/[^Test]*.cpp $(FLAGG) $(VERSION)) && echo "Compiling Test success" || echo "Compiling Test failed"

delete:
	@(echo "Deleting...")
	@(rm -rf bin/*)
	@(rm -rf test/*)
	@(rm -rf test/Window/*)
	@(rm -rf test/Sprite/*)
	@(echo "Deleting success")