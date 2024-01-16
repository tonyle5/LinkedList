all: program

program: main.o SongList.o Song.o myUtil.o
	g++ -g -Wall -std=c++17 main.o SongList.o Song.o myUtil.o -o program

main.o: main.cpp
	g++ -g -c -std=c++17 -Wall main.cpp -o main.o

SongList.o: SongList.cpp
	g++ -g -c -std=c++17 -Wall SongList.cpp -o SongList.o

Song.o: Song.cpp
	g++ -g -c -std=c++17 -Wall Song.cpp -o Song.o

myUtil.o: myUtil.cpp
	g++ -g -c -std=c++17 -Wall myUtil.cpp -o myUtil.o

clean:
	rm -f *.o
	rm -f ./program
