// file: aarohi.cc 

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include "driver.h"
#include "expression.h"
#include <stdint.h>
//#include <ctime> // for clock()
#include <time.h> // for clock_gettime

int main(int argc, char *argv[])
{
    phraseAutomata matchedChain;
    phrase::Driver driver(matchedChain);
    bool readfile = false;
    for(int ai = 1; ai < argc; ++ai)
    {
	if (argv[ai] == std::string ("-p")) {
	    driver.trace_parsing = true;
	}
	else if (argv[ai] == std::string ("-s")) {
	    driver.trace_scanning = true;
	}
	else
	{
	    // read a file with Timestamp and Phrase on each line (no comma)

	    std::fstream infile(argv[ai]);
            if (!infile.good())
	    {
		std::cerr << "Could not open input file: " << argv[ai] << std::endl;
		return 0;
	    }
	    matchedChain.clearChains();
            std::string timestamp, line, chain, phraseNum;
	    struct timespec start, mid, finish; 
	    //clock_t beginPhraseCheck = clock();
	    clock_gettime(CLOCK_MONOTONIC, &start); 
            int eventNotInFailureChain = 0;
	    int countLine = 0;
	    while (infile >> line)
	    {
                 //std::cout << "Line content is " << line << std::endl;
		 countLine++; // Divided by 2 since every event has a timestamp associated with it, line considers every space separated entry, not the entire log message 
            } 
	    infile << "\n";
	    infile.clear();
            infile.seekg(0, infile.beg);
	    //std::cout << "\n Total number of events in the input sequence is " << countLine/2 << std::endl;
	    
	    std::cout << "\n Starting Failure Prediction ...." << std::endl; 
	    //clock_t begindetection = clock(); 
	    clock_gettime(CLOCK_MONOTONIC, &mid); /* Using CLOCK_REALTIME has issues when the system time/date is changed, hence safer to use*/
  	    bool result = driver.parse_stream(infile);		
	    //bool result = driver.parse_file("Test1.txt"); 
	    //clock_t end = clock();
	    clock_gettime(CLOCK_MONOTONIC, &finish);
	    std::cout << "\n Finished Inference ...." << std::endl; 
            uint64_t elapsed_secs = 1000000000L * (finish.tv_sec - mid.tv_sec) + (finish.tv_nsec - mid.tv_nsec);
            uint64_t elapsed_total = 1000000000L * (finish.tv_sec - start.tv_sec) + (finish.tv_nsec - start.tv_nsec);
            //double elapsed_secs = double(end - begindetection) / CLOCKS_PER_SEC; // clock ticks per second
            //double elapsed_total = double(end - beginPhraseCheck) / CLOCKS_PER_SEC; // clock ticks per second
	    if (result)
	    {
		std::cout << "Parse Successful, Prediction time is: " << (long long unsigned int) elapsed_secs << " nsecs" << std::endl;
	    }
	    else // parse unsuccessful 
	    {
		std::cout << "Parse Unsuccessful by the end, Prediction time is: " << (long long unsigned int) elapsed_secs << " nsecs" << std::endl;
	    }
	    if (!matchedChain.chains.empty())
	    {
	    	std::cout << "FC Matched:" << std::endl;
            	for (unsigned int fc = 0; fc < matchedChain.chains.size(); ++fc)
            	{
            		std::cout << matchedChain.chains[fc] << std::endl;
            	}
	    }
	    else 
		std::cout << "No Fatch found" << std::endl;

	    readfile = true;
	} 
    }
    if (readfile) return 0;
    
    std::cout << "Process Phrase Sequence from stdin" << std::endl;

    std::string line;
    while( std::cout << "Phrases: " &&
    	   std::getline(std::cin, line) &&
    	   !line.empty() )
    {
    	//matchedChain.clearChains();
    	bool result = driver.parse_string(line, "Phrase");
 
    	if (result)
    	{
	    //std::cout << "FC Matched: " << std::endl;
    	    //for (unsigned int fc = 0; fc < matchedChain.chains.size(); ++fc)
    	    //{
    		//std::cout << ' ' << matchedChain.chains[fc];
    	    //}
    	}
    }
}
