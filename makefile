####### Compiler, tools and options

CXX           = LC_ALL=C g++ -std=c++17
DEL_FILE      = rm -f

####### Implicit rules

clean: 
	-$(DEL_FILE) *.o
	-$(DEL_FILE) *~ core *.core


####### Compile
all:  chronobook
Media : Media.h Media.cpp
	$(CXX) -c  -o Media.o Media.cpp
Utilities : Utilities.cpp Utilities.h
	$(CXX) -c -o Utilities.o Utilities.cpp
ASL_node : ASL_node.cpp
	$(CXX) -c -o ASL_node.o ASL_node.cpp
AutoSortLibrary : AutoSortLibrary.cpp AutoSortLibrary.h ASL_node
	$(CXX) -c -o AutoSortLibrary.o  ASL_node.o   AutoSortLibrary.cpp
chronobook: AutoSortLibrary Media chronobook.h chronobook.cpp Utilities
	$(CXX) -g  -o chronobook AutoSortLibrary.o ASL_node.o Utilities.o  Media.o chronobook.cpp
