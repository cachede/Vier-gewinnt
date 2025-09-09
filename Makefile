# - inc/
#     - *.h
# - lib/
#     - *.lib
# - src/
#     - *.c
#     - *.h
#     - *.cpp
#	 - *.hpp
# - obj/
#     - *.o
# - bin/
#     - main.exe

TARGET := bin/main.exe
SOURCES := $(wildcard src/*.c src/*.cpp)
OBJECTS := $(patsubst src%,obj%, $(patsubst %.c,%.o, $(patsubst %.cpp,%.o,$(SOURCES))))

INCLUDE := -I./inc
LIBPATH := -L./lib
LIBS := -lraylib -lgdi32 -lwinmm

FLAGS := -Wall -Wextra -ggdb
CXXFLAGS := $(FLAGS)

CXX := gcc

all: $(OBJECTS)
	$(CXX) $(INCLUDE) $(OBJECTS) -o $(TARGET) $(LIBPATH) $(LIBS)

%.o: ../src/%.c
	$(CXX) $(FLAGS) $(INCLUDE) -c $< -o $@

%.o: ../src/%.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $@

.PHONY: clean help

clean:
	rm -rf obj/*
	rm -f $(TARGET)
	
help:
	@grep -E '^[a-zA-Z_-]+:.*?## .*$$' $(MAKEFILE_LIST) | sort | awk 'BEGIN {FS = ":.*?## "}; {printf "\033[36m%-30s\033[0m %s\n", $$1, $$2}'