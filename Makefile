all: build/main.o build/libui.so build/libeventprocessor.so
	g++ build/main.o -Lbuild -lui -leventprocessor -lSDL2 -lSDL2_image -o build/YaT.bin

build/main.o: src/main.cpp
	g++ -c src/main.cpp -Iinclude -o build/main.o

build/libui.so: build/image.o build/drawer.o build/uiobject.o
	g++ -shared -o build/libui.so build/image.o build/drawer.o build/uiobject.o

build/image.o: src/ui/image.cpp include/ui/image.h
	g++ -c  -fPIC src/ui/image.cpp -Iinclude -o build/image.o

build/drawer.o: src/ui/drawer.cpp include/ui/drawer.h
	g++ -c  -fPIC src/ui/drawer.cpp -Iinclude -o build/drawer.o

build/uiobject.o: src/ui/uiobject.cpp include/ui/uiobject.h
	g++ -c -fPIC src/ui/uiobject.cpp -Iinclude -o build/uiobject.o

build/libeventprocessor.so: build/sdl_event_processor.o build/sdl_event_receiver.o build/event_notifier.o build/sdl_event_mapper.o build/event.o build/quit_listener.o
	g++ -shared -o build/libeventprocessor.so build/sdl_event_processor.o build/sdl_event_receiver.o build/event_notifier.o build/sdl_event_mapper.o build/event.o build/quit_listener.o

build/sdl_event_processor.o: src/ui/event_processor/sdl_event_processor.cpp include/ui/event_processor/sdl_event_processor.h
	g++ -c -fPIC src/ui/event_processor/sdl_event_processor.cpp -Iinclude -o build/sdl_event_processor.o

build/sdl_event_receiver.o: src/ui/event_processor/sdl_event_receiver.cpp include/ui/event_processor/sdl_event_receiver.h
	g++ -c -fPIC src/ui/event_processor/sdl_event_receiver.cpp -Iinclude -o build/sdl_event_receiver.o

build/event_notifier.o: src/ui/event_processor/event_notifier.cpp include/ui/event_processor/event_notifier.h
	g++ -c -fPIC src/ui/event_processor/event_notifier.cpp -Iinclude -o build/event_notifier.o

build/sdl_event_mapper.o: src/ui/event_processor/sdl_event_mapper.cpp include/ui/event_processor/sdl_event_mapper.h
	g++ -c -fPIC src/ui/event_processor/sdl_event_mapper.cpp -Iinclude -o build/sdl_event_mapper.o

build/event.o: src/ui/event_processor/event.cpp include/ui/event_processor/event.h
	g++ -c -fPIC src/ui/event_processor/event.cpp -Iinclude -o build/event.o

build/quit_listener.o:
	g++ -c -fPIC src/ui/event_processor/quit_listener.cpp -Iinclude -o build/quit_listener.o

clean:
	rm build/*


