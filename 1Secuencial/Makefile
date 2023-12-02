CC = g++
CFLAGS = -Wall -std=c++11
LIBS = `pkg-config --cflags --libs opencv4`

all: convertir_a_grises

convertir_a_grises: convertir_a_grises.cpp
	$(CC) $(CFLAGS) -o convertir_a_grises convertir_a_grises.cpp $(LIBS)

clean:
	rm -f convertir_a_grises
