engine.exe: compile.test
	engine.exe
compile.test: engine.cpp libs/base.h libs/GLbase.h libs/color.h
	g++ -Wall -o engine.exe engine.cpp -lglut32cu -lglu32 -lopengl32 -std=c++11
	echo "Compiling source..."
	touch compile.test