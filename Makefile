#!bin/bash

DATA	=	src/*.cpp\
			\
			src/Sprite/Drawable/[^Test]*.cpp\
			src/Sprite/ImageInterpretor/[^Test]*.cpp\
			src/Sprite/Pixel/[^Test]*.cpp\
			src/Sprite/Rectangle/[^Test]*.cpp\
			src/Sprite/Sprite2D/[^Test]*.cpp\
			\
			src/Window/Window/[^Test]*.cpp\

DATA_WITHOUT_TEST	=	src/[^Test]*.cpp\
						\
						src/Sprite/Circle/[^Test]*.cpp\
						src/Sprite/Drawable/[^Test]*.cpp\
						src/Sprite/ImageInterpretor/[^Test]*.cpp\
						src/Sprite/Pixel/[^Test]*.cpp\
						src/Sprite/Rectangle/[^Test]*.cpp\
						src/Sprite/Sprite2D/[^Test]*.cpp\
						\
						src/Window/Window/[^Test]*.cpp\

DATA_WITH_TEST	=	src/Test.cpp\
					\
					src/Sprite/Circle/Test.cpp\
					src/Sprite/Drawable/Test.cpp\
					src/Sprite/ImageInterpretor/Test.cpp\
					src/Sprite/Pixel/Test.cpp\
					src/Sprite/Rectangle/Test.cpp\
					src/Sprite/Sprite2D/Test.cpp\
					\
					src/Window/Window/Test.cpp\

FLAGG		=	`sdl-config --cflags --libs`\
				`sdl2-config --cflags --libs`\
				-lSDL2 -lSDL2_image\
				-lsfml-graphics -lsfml-window -lsfml-system\

VERSION	=	-std=c++2a\

all:
	@echo "Delete ..."
	@make delete > /dev/null
	@echo "Deleted"
	@(mkdir test/Window) > /dev/null
	@(mkdir test/Sprite) > /dev/null
	@echo "Compiling..."
	@echo "Window :"
	@make test_window >/dev/null
	@echo "Event :"
	@make test_event >/dev/null
	@echo "Mouse :"
	@make test_mouse >/dev/null
	@echo "Keyboard :"
	@make test_keyboard >/dev/null
	@echo "Pixel :"
	@make test_pixel >/dev/null
	@echo "Image Interpretor :"
	@make test_imageinterpretor >/dev/null
	@echo "Sprite :"
	@make test_sprite >/dev/null
	@echo "Rectangle :"
	@make test_rectangle >/dev/null
	@echo "Done."
	@echo "Run test :"
	@make test > /dev/null

test_window:
	@(echo "Compiling Test Window...")
	@(g++ -o test/Window/Window src/Window/Keyboard/[^Test]*.cpp src/Window/Mouse/[^Test]*.cpp src/Window/Event/[^Test]*.cpp src/Window/Window/*.cpp src/Sprite/Sprite2D/[^Test]*.cpp src/Sprite/ImageInterpretor/[^Test]*.cpp src/Sprite/Pixel/[^Test]*.cpp src/Sprite/Rectangle/[^Test]*.cpp src/Sprite/Drawable/[^Test]*.cpp $(FLAGG) $(VERSION)) && echo "Compiling Test success" || echo "Compiling Test failed"

test_event:
	@(echo "Compiling Test Event...")
	@(g++ -o test/Window/Event src/Window/Event/*.cpp $(FLAGG) $(VERSION)) && echo "Compiling Test success" || echo "Compiling Test failed"

test_mouse:
	@(echo "Compiling Test Mouse...")
	@(g++ -o test/Window/Mouse src/Window/Mouse/*.cpp src/Window/Event/[^Test]*.cpp $(FLAGG) $(VERSION)) && echo "Compiling Test success" || echo "Compiling Test failed"

test_keyboard:
	@(echo "Compiling Test Mouse...")
	@(g++ -o test/Window/Keyborad src/Window/Keyboard/*.cpp src/Window/Event/[^Test]*.cpp $(FLAGG) $(VERSION)) && echo "Compiling Test success" || echo "Compiling Test failed"

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
	@(rm -rf test/Window/*)
	@(rm -rf test/Sprite/*)
	@(rm -rf bin/*)
	@(rm -rf test/*)
	@(echo "Deleting success")

test_:
	@(echo "Running test...")
	@(./test/Window/Window)
	@(./test/Sprite/Pixel)
	@(./test/Sprite/ImageInterpretor)
	@(./test/Sprite/Sprite2D)
	@(./test/Sprite/Rectangle)
	@(echo "Test success")