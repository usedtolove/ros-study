main: http.o main.o
	g++ http.cpp main.cpp -o main -lcurl

main.o: main.cpp
	g++ -c main.cpp -o main.o

http.o: http.cpp http.h
	g++ -c http.cpp -o http.o

clean:
	rm *.o
	rm main
