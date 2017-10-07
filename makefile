


CXX = g++			#set a compiler for C++ filesi
CXXFLAGS = -std=c++11		#Ask compiler to use C++11 standard it has
CXXFLAGS += -Wall		#Don't remember what this does.
CXXFLAGS += -pedantic-errors	#Strictly enforce the standard.
LDFLAGS = -lboost_date_time

MAIN = main.cpp
HEADERS = Object.hpp Holdable.hpp Usable.hpp Goal.hpp Permanent.hpp driver.hpp
HEADERS += input.hpp menu.hpp
HEADERS += RoomMenu.hpp BPMenu.hpp
HEADERS += Backpack.hpp
HEADERS += Player.hpp
HEADERS += Room.hpp GoalRoom.hpp ResourceRoom.hpp InteractRoom.hpp
HEADERS += Game.hpp

SRCS = $(HEADERS:.hpp=.cpp) ${MAIN} 
OBJS = $(SRCS:.cpp=.o)

FILE = main

${FILE}: ${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} -o ${FILE}

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c ${SRCS}

debug: ${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} -g ${OBJS} -o debug

clean: 
	rm *.dat *.o *.gch a.out debug ${FILE}
