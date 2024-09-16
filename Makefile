all: build/main.o build/image.o build/drawer.o build/uiobject.o
	g++ build/main.o build/image.o build/drawer.o build/uiobject.o -lSDL2 -lSDL2_image -o build/YaT.bin

build/main.o: src/main.cpp
	g++ -c src/main.cpp -Iinclude -o build/main.o

build/image.o: src/ui/image.cpp include/ui/image.h
	g++ -c src/ui/image.cpp -Iinclude -o build/image.o

build/drawer.o: src/ui/drawer.cpp include/ui/drawer.h
	g++ -c src/ui/drawer.cpp -Iinclude -o build/drawer.o

build/uiobject.o: src/ui/uiobject.cpp include/ui/uiobject.h
	g++ -c src/ui/uiobject.cpp -Iinclude -o build/uiobject.o

clean:
	rm build/*


