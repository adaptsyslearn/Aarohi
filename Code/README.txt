
  
 ****************** AAROHI Inference ENGINE **********************

 This is the first version of the Aarohi Inference Tool. 

 Failure Chains (FCs) are taken as input, and the predictor checks the sequence of phrases in the test logs
 to infer if it matches a rule (i.e., failure chain or FC).

 This version does not include partial multiple rule matches, i.e., multiple instantiation of parsers to check multiple rules
                  simultaneously.

 Currently, one specific rule is checked at a time, whichever starting phrase matches any of the rules first, 
 that rule is checked subsequently. This continues until no phrases are left in the file or there is a timeout based violation.

 In this version of Aarohi, the system times are considered for timeouts, only during "errors" (i.e., phrase mismatches during rule checks).
  
************ To create the binary ***********

Pre-requisites: 
          Flex version - 2.6.4 
          Bison - 3.0.4 
          g++ - 5.4.0          

 cd Code 

 To generate two binaries of aarohi, with and without compiler optimization (O3) with suitble prefix path,  
 Run:

	bash compile.sh
	Outputs: aarohi, aarohiUnoptimized in src directory
 
 If changes are made in any files other than .ll or .yy files of src, please run:
	make clean

 else, if changes are made in .ll or .yy files as well, please run:
	make distclean

 followed by generating an optimized binary (i.e., with O3 compiler flag):
	./configure --enable-optimize --prefix=$(pwd)/src
	make && make install

 to generate an unoptimized binary

	./configure --program-suffix=Unoptimized --prefix=$(pwd)/src
	make && make install

 copy the binaries from src/bin to src (if needed), to run other scripts


************ To run experiments ***********

 Once the binary is created, run the test logs with the binary:

cd Code/src/

In general: ./aarohi   ../TestFiles/Test.txt 

The usage of -s, -p options help to debug with verbose tracing enabled (i.e., has added tracing overhead). 
./aarohi -s ../TestFiles/Test.txt 

It is recommended not to use -s & -p options to get major performance numbers.
 
Example:
./aarohi ../TestFiles/Test8.txt

(matches FC8 from FC List.txt from Algorithm 1 in the paper)


