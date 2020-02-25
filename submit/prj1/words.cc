#include <stdio.hh>

int main(int argc, const char* argv[]) {
    //argc should be 5
    //argv shoule be [wordcounts, MAX_N_OUT, MIN_WORD_LEN, MAX_WORD_LEN, FILE]
    if (argc < 5) {
        std::cerr << "usage: " << argv[0] << " MAX_N_OUT MIN_WORD_LEN MAX_WORD_LEN FILE..." << std::endl;
	//EINVAL , error with an invalid argument
        return EINVAL;
    }

    //auto automatically identifies the type of the arguments
    //std::vector is a "collection"/unbounded array
    //<std::string> is the type of the elements that will be stored in the vector
    //(&argv[0], &argv[argc]) are the arguments that this will iterate through to create the vector 
    auto args = std::vector<std::string>(&argv[0], &argv[argc]);
    //vector/array of 3 elements that tell the size of something
    std::size_t data[3];
    char* names[3] = {"MAX_N_OUT", "MIN_WORD_LEN", "MAX_WORD_LEN"};
    //references to datas elements
    std::size_t &max_n_out(data[0]), &min_len(data[1]), &max_len(data[2]);
    //args[].length won't equal end Index if there are chars in the string becuase when the string is converted to an integer, the chars won't be included
    std::size_t endIndex;
    for (int i = 0; i < 3; i++) {
        try {
            data[i] = std::stoi(args[i + 1], endIndex);
            if (endIndex != args[i + 1].length())
                throw std::invalid_argument("invalid");
        }
	catch (const std::invalid_argument& e) {
            std::cerr << "bad integer value " << std::quoted(argv[i+i]) << " for " << names[i] << std::endl;
            return EINVAL;
        }
    }
    if (min_len > max_len) {
        std::cerr << names[1] << ' ' << min_len << " is greater than " << names[2] << ' ' << max_len << std::endl;
        return EINVAL;
    }

    //ifstream is a read only stream so you can pull stuff out, but cannot pull things in
    std::ifstream in(fileName);
    std::unordered_map<std::string, Count> map;
    while(in.good()) {
        std::string w;
        in >> w;
	//where the all the alphabetical only charcters will be stored
	std::string new_w;
	//iterating through all chars in the line/string from the file
	for (char c : w){
	  //if the character is an alphabetical one, add it to the new string/version of w with only alphabetical charcters. This gets rid of any characters that are special charcters, spcaes, or numhbers without having to change w
	    if (std::isalpha(c)){
	        //?or append
	        //not only adds only alphabetical characters, but also ones that are made up of only lower case letters
	        new_w += std::tolower(c);
	    }
	}
	if(new_w.length()>=data[1] && new_w.length()<=data[2]){
	    map.insert(new_w, ?); //help
	}
	Count& count =map[new_w];
	count +=1;
        std::cout << new_w << std::endl;
    }
    //if the file doesn't reach the end of the file or if all of the file isn't read
    if (!in.eof()) {
        //EIO, error with input output 
        std::cerr << std::strerror(EIO) << std::endl;
        return EIO;
    }

    bool wordCountCompare(std::string w1, std::string w2){
        int i=0;
	    
    typedef std::pair<std::string, Count> WordCount;
    auto wordCounts = std::vector<WordCount>(map.begin(), map.end());
    
}

