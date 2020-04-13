#ifndef OUT_HH_
#define OUT_HH_

#include <algorithm>
#include <vector>


template <typename Iterator>
void
outContainer(Iterator begin, Iterator end) 
{
  std::cout << "[ ";
  auto print = [](const int& i) { std::cout << i << " " ; };
  std::for_each(begin, end, print);
  std::cout << "]" << std::endl;
}

/** create a vector which is identical to [begin, end) but with first
 *  occurrence of arg removed.  Output vector elements within [ ],
 *  separated by spaces.
 */
template <typename Iterator>
void
loopFn(Iterator begin, Iterator end, int arg)
{
  std::vector<int> vec;
  //@TODO
    bool isSeen=false;
    for (auto a=begin; a!=end; ++a)
    {
        if(*a==arg)
	{
	    if(isSeen==false)
	    {
	        isSeen=true;
	    }
	    else
	    {
	        vec.push_back(*a);
	    }
	}
        else// if(*a!=arg)
	{
	    vec.push_back(*a);
	}
    }
  outContainer(vec.begin(), vec.end());
}

/** Exactly like loopFn() but no loops should be used */
template <typename Iterator>
void noLoopFn(Iterator begin, Iterator end, int arg)
{
  //@TODO
    auto it=std::find(begin, end, arg);
    std::vector<int> vec= std::vector<int>(begin, it);
    if(it!=end)
    {
        std::copy(++it, end, std::back_inserter(vec));
    }
    outContainer(vec.begin(), vec.end());
}

#endif //ifndef OUT_HH_
