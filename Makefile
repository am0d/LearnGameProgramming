SOURCES = $(wildcard src/*.cpp)
OBJECTS = $(SOURCES:.cpp=.o)
DEPS = $(SOURCES:.cpp=.d)
BIN = bin/sfml

CXXFLAGS += -MMD -Wall -Wextra -pedantic
LDFLAGS += -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system

all: $(BIN)

run: $(BIN)
	$(BIN)

.PHONY: clean

$(BIN): $(OBJECTS)
	$(CXX) -o $@ $(CXXFLAGS) $(LDFLAGS) $(OBJECTS)

.cpp.o:
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJECTS) $(DEPS) $(BINS)

-include $(DEPS)
