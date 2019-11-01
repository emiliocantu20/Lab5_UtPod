final: UtPodDriver.o UtPod.o Song.o
	g++ -std=c++11 -otest UtPodDriver.o UtPod.o Song.o
driver: UtPodDriver.cpp UtPod.h Song.h
	g++ -std=c++11 -c UtPodDriver.cpp
UtPod.o: UtPod.cpp UtPod.h Song.h
	g++ -std=c++11 -c UtPod.cpp
Song.o: Song.cpp Song.h
	g++ -std=c++11 -c Song.cpp
