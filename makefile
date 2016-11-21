####### Compiler, tools and options

CXX           = LC_ALL=C g++ -std=c++14
DEL_FILE      = rm -f

####### Implicit rules

clean: 
	-$(DEL_FILE) *.o
	-$(DEL_FILE) *~ core *.core


####### Compile
all:  chronobook
Media : Media.h Media.cpp
	$(CXX) -c  -o Media.o Media.cpp
AutoSortLibrary : AutoSortLibrary.cpp AutoSortLibrary.h
	$(CXX) -c -o AutoSortLibrary.o AutoSortLibrary.cpp
chronobook: AutoSortLibrary Media chronobook.h chronobook.cpp
	$(CXX) -g  -o chronobook AutoSortLibrary.o  Media.o chronobook.cpp
