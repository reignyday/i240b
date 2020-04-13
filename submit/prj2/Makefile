
CXX = g++
CXXFLAGS = -g -Wall -std=c++17
CXX_FILES = $(wildcard *.cc)

all:		seq-test nums clean
seq-test:	seq-test.o command.o
		$(CXX) $(CXXFLAGS) $^ -o $@
seq-test.o:	seq-test.cc arrayseq.hh seq.hh #dlinkseq.hh
		$(CXX) $(CXXFLAGS) -c seq-test.cc
command:	command.o
		$(CXX) $(CXXFLAGS) $* -o $@
command.o: 	command.cc command.hh seq.hh
		$(CXX) $(CXXFLAGS) -c command.cc
#based off nums object
nums:		nums.o
		$(CXX) $(CXXFLAGS) $^ -o $@
#nums object based off of nums code/.cc file
nums.o: 	nums.cc arrayseq.hh dlinkseq.hh seq.hh command.cc
		$(CXX) $(CXXFLAGS) -c nums.cc command.cc

.phony: clean
clean: rm -f *~ *.o $(all)
