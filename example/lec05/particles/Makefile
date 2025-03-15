.PHONY: all clean run

CXX := g++
CXXFLAGS := -Isrc -Iinclude -lraylib -DPLATFORM_DESKTOP -Wall -O2 -lopengl32 -lgdi32 -lwinmm -std=c++11
LDFLAGS := -Llib
LIBS := -lraylib -lopengl32 -lgdi32 -lwinmm

SRC := src/main.cpp src/app.cpp src/particle.cpp

all: build/particles.exe

build/particles.exe: $(SRC)
	$(CXX) $(SRC) $(CXXFLAGS) $(LDFLAGS) $(LIBS) -o $@

clean:
	rm "build/particles.exe"

run: build/particles.exe
	build/particles.exe