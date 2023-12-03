CC = g++
CFLAGS = -Wall -std=c++11 `pkg-config --cflags opencv4`
LIBS = `pkg-config --libs opencv4`

all: convertir_a_grises

convertir_a_grises: convertir_a_grises.cpp
	$(CC) $(CFLAGS) -o $@ $< $(LIBS)

clean:
	rm -f convertir_a_grises
