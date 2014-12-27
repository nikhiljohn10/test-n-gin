engine.exe: compile
	engine.exe
compile: engine.cpp libs/base.h libs/GLbase.h libs/color.h
	g++ -Wall -o engine.exe engine.cpp -lglut32cu -lglu32 -lopengl32 -std=c++11
	echo "Compiling source..."
	touch compile
debug: engine.cpp libs/base.h libs/GLbase.h libs/color.h
	g++ -g -Wall -o engine_debug.exe engine.cpp -lglut32cu -lglu32 -lopengl32 -std=c++11
	gdb engine_debug.exe