CXX = g++
CXXFLAGS = -g -Wall -std=c++17
CXX_FILES = $(wildcard *.cc)

all: seq-test nums clean
seq-test: seq-test.o
          $(CXX) $(CXXFLAGS) $^ -o $@
seq-test.o: seq-test.cc
       $(CXX) $(CXXFLAGS) $^ -o $@
#based off nums object
nums: nums.o
      $(CXX) $(CXXFLAGS) $^ -o $@
#nums object based off of nums code/.cc file
nums.o: nums.cc arrayseq.hh DLinkSeq.hh
        $(CXX) $(CXXFLAGS) $* -o $@
.phony: clean
clean: rm -f *~ *.o $(all)
