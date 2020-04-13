#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <string>
#include "dlinkseq.hh"
#include "arrayseq.hh"
#include "seq.hh"
#include "command.hh"

using TestType= int;
Seq<TestType>* arrp= ArraySeq<TestType>::make().get();
Seq<TestType>* dlinkp= DLinkSeq<TestType>::make().get();

//to read in ints from file and push onto stack
void readints(const std::string fileName, Seq<TestType>* seq)
{
    std::ifstream in(fileName);
    if(!in)
    {
	std::cerr << "Cannot read " << fileName << ": No such file or directory" << std::endl;
	std::exit(1);
    }
    //while there's aother line available
    while(in)
    {
        //making temp int
        TestType temp;
	//putting each int from the ifstream into temp
        in >> temp;
	//pushing each number on the stack
        seq->push(temp);
    }
    //close file
    in.close();
}

void outputdata(Seq<TestType>* seq)
{
    //constant iter pointer?
    auto beginp = seq -> cbegin();
    auto endp = seq -> cend();
    auto &start = *beginp;
    auto &fin = *endp;
    --fin;
    while(start && fin)
    {
        std::cout << *start << std::endl;
        std::cout << *fin << std::endl;
        ++start;
        --fin;
    }
}
    
int main(int argc, char **argv)
{
    //if nums is the only argument
    if(argc < 2)
    {
        std::cout << "usage: ./nums ArraySeq | DLinkSeq" << std::endl;
        return 0;
    }
    std::string fileName= std::string(argv[1]);
    if(argc==2){

        //if there's only 2 arguments and the second one is -a, then there
        //must be no file name
      //strcmp returns 0 if equal, greater than 0, less than 0 if it is earlier alphabetically
      if(strcmp(argv[1],"-a")==0)
        {
	    std::cout << "Missing File Name" << std::endl;
  	    std::exit(1);
        }
        readints(fileName, dlinkp);
        outputdata(dlinkp);
    }

    if(argc==3)
    {
        if(strcmp(argv[1],"-a")!=0)
        {
	    std::cout << "ArrayList(-a) Seq not indicated" << std::endl;
  	    std::exit(1);
        }
	readints(fileName, arrp);
	outputdata(arrp);
    }
/**
    cout << "[REPEAT] [COMMAND] [VALUE]" << std::endl;
    cout << "COMMAND is one of the following: clear | unshift | shift | push | pop | help" << std::endl;
*/
    return 0;
}
