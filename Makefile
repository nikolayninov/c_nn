FILES=*.*pp Functions/*.*pp
run: all
	./main

all:
	g++ -O2 -Wall -std=c++17 ${FILES} -o main

clean:
	rm main