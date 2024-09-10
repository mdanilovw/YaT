all: build/main.o build/image.o build/drawer.o
	g++ build/main.o build/image.o build/drawer.o -lSDL2 -lSDL2_image -o build/YaT.bin

build/main.o: src/main.cpp
	g++ -c src/main.cpp -Iinclude -o build/main.o

build/image.o: src/ui/image.cpp include/ui/image.h
	g++ -c src/ui/image.cpp -Iinclude -o build/image.o

build/drawer.o: src/ui/drawer.cpp include/ui/drawer.h
	g++ -c src/ui/drawer.cpp -Iinclude -o build/drawer.o

clean:
	rm build/*


