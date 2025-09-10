TARGET := ./bin/main.exe
SOURCES := $(wildcard src/*.c src/*.cpp)
OBJECTS := $(patsubst src%,obj%, $(patsubst %.c,%.o, $(patsubst %.cpp,%.o,$(SOURCES))))
DEPS := $(OBJECTS:.o=.d)

INCLUDE := -I./inc -I./src
LIBPATH := -L./lib
LIBS := -lraylib -lgdi32 -lwinmm

FLAGS := -Wall -Wextra -ggdb -MMD -MP
CXXFLAGS := $(FLAGS)

CXX := gcc

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(INCLUDE) $(OBJECTS) -o $@ $(LIBPATH) $(LIBS)

obj/%.o: src/%.c
	$(CXX) $(FLAGS) $(INCLUDE) -c $< -o $@

obj/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $@


-include $(DEPS)

.PHONY: clean help

clean:
	rm -rf obj/*
	rm -f $(TARGET)
	
help:
	@grep -E '^[a-zA-Z_-]+:.*?## .*$$' $(MAKEFILE_LIST) | sort | awk 'BEGIN {FS = ":.*?## "}; {printf "\033[36m%-30s\033[0m %s\n", $$1, $$2}'
