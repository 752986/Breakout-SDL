compiler = g++
libpath = .
libs = -lSDL2
output = .
name = a.exe
source = .
objects = main.cpp

all: build

build:
	$(compiler) -g -o $(output)/$(name) $(source)/$(objects) -I$(libpath)/include -L $(libpath)/lib $(libs)
	
run: build
	$(output)/$(name)