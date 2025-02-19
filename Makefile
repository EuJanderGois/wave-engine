EXECUTABLE_NAME = out.exe
TARGET = build/$(EXECUTABLE_NAME)
SOURCES = src/main.cpp

INCLUDE_DIR = include

CC = g++
CFLAGS = $(addprefix -I, $(INCLUDE_DIR))
LDFLAGS = $(addprefix -L, -lyaml-cpp -lraylib -L/mingw64/lib -L/mingw64/bin -L/mingw64/include

$(TARGET): $(SOURCES)
	@echo "==== Building ($(TARGET)) ===="
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCES) $(LDFLAGS)

	@if [ -d "./build/resources" ]; then \
		rm -rf ./build/resources; \
	fi; \

	@if [ -d "./resources" ]; then \
		cp -r ./resources ./build/resources/; \
	fi

	@echo "==== Checking if styles directory exists ===="
	@if [ -d "./build/styles" ]; then \
		rm -rf ./build/styles; \
	fi; \

	@if [ -d "./src/styles" ]; then \
		cp -r src/styles ./build/styles/; \
	fi

run: $(TARGET)
	cd build && ./$(EXECUTABLE_NAME)

clean:
	rm -f $(TARGET)
	rm -rf ./build/resources/
	rm -rf ./build/styles/