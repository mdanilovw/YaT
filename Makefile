all: build/main.o build/image.o
	g++ build/main.o build/image.o -lSDL2 -lSDL2_image -o build/YaT.bin

build/main.o: src/main.cpp
	g++ -c src/main.cpp -Iinclude -o build/main.o

build/image.o: src/ui/image.cpp include/ui/image.h
	g++ -c src/ui/image.cpp -Iinclude -o build/image.o

clean:
	rm build/*


