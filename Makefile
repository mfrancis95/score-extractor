all: main.cpp
	g++ -o main main.cpp `pkg-config --cflags --libs opencv`

clean:
	rm -f main output.png
