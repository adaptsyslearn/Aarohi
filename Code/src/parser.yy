/** \file parser.yy Contains the phrase Bison parser source */

%{ /*** C/C++ Declarations ***/

#include <stdio.h>
#include <string.h>
#include <sstream>
#include <iostream>
#include <vector>
#include "expression.h"
#include <sys/time.h>
%}

/*** yacc/bison Declarations ***/

/* Require bison 2.3 or later */
%require "2.3"

%debug

/* start symbol is named "start" */
%start start

/* write out a header file containing the token defines */
%defines

/* use C++ skeleton file */
%skeleton "lalr1.cc"

/* Non-reentrant Parser */
/* %define api.pure full */

/* namespace to enclose parser in */
%name-prefix "phrase"

/* set the parser's class identifier */
%define parser_class_name {Parser}

/* keep track of the current position within the input */
%locations
%initial-action
{
    // initialize the initial location object
    @$.begin.filename = @$.end.filename = &driver.streamname;
};

/* The driver is passed by reference to the parser and to the scanner. This
 * provides a simple but effective pure interface, not relying on global
 * variables. */
%parse-param { class Driver& driver }

/* verbose error messages */
%define parse.error verbose

 /*** BEGIN PHRASE - Change the phrase grammar's tokens below ***/

%union {
    int  			integerVal;
    double 			doubleVal;
    long int			longVal;
    std::string*		stringVal;
    struct timespec*		time;	
    class phraseAutomata*       matchedChain;
}

%token			END	     0	"end of file"
%token			EOL		"end of line"
%token <integerVal> 	INTEGER		"integer"
%token <doubleVal> 	DOUBLE		"double"
%token <stringVal> 	STRING		"string"
%token <time>	TIME

%token <stringVal>      component
%token <doubleVal>      TIMESTAMP threshold  
%token <integerVal> 	PHRASE timediff 
%token P1 P2 P3 P4 P5 P6 P7 P8 P9 P10 P11 P12 P13 P14 P15 P16 P17 P18 P19 P20 P21 P22 P23 P24 P25 P26 P27 P28 P29 P30 P31 P32 P33 P34 P35 P36 P37 P38 P39 P40 P41 P42 P43 P44 P45 P46 P47 P48 P49 P50 P51 P52 P53 P54 P55 P56 P57 P58 P59 P60 P61 P62 P63 P64 P65 P66 P67 P68 P69 P70 P71 P72 P73 P74 P75 P76 P77 P78 P79 P80 P81 P82 
%token IF
%token THEN
%token ELSE
%token COMMA
%left PLUS 

%type <longVal> P19 P61 P62 error expression
%type <longVal> eventlist event 

%destructor { delete $$; } STRING
%destructor { delete $$; } component 

 /*** END PHRASE - Change the phrase grammar's tokens above ***/

%{

#include "driver.h"
#include "scanner.h"

/* this "connects" the bison parser in the driver to the flex scanner class
 * object. it defines the yylex() function call to pull the next token from the
 * current lexer object of the driver context. */
#undef yylex
#define yylex driver.lexer->lex

%}

%% /*** Grammar Rules ***/

 /*** BEGIN PHRASE - Change the phrase grammar rules below ***/

eventlist : expression { /*std::cout << "Expression it is " << std::endl;*/ } 
          | expression error eventlist  
          { 
		$$ = $1; 
		/*std::cout << "Encountered error after expression " << @$ << std::endl;*/
		yyclearin;
		yyerrok; 
	  }
	  ;

expression : P1 error P2 error P3 error P4 error P5 error P6 error P7 
          {
		$$=1;
		std::cout << "Event Sequence Matched Failure Chain 1 " << std::endl;
		driver.matchedChain.chains.push_back($$);
          }
          | P8 error P9 error P10 error P11 error P12 error P13 error P7 
          {
		$$=2;
                std::cout << "Event Sequence Matched Failure Chain 2 " << std::endl;
		driver.matchedChain.chains.push_back($$);
          }
          | P14 error P15 error P16 error P17 error P14 error P15 error P16 error P17 error P18 error P11 error P7 error P19
          {
		$$=3;
                std::cout << "Event Sequence Matched Failure Chain 3 " << std::endl;
		driver.matchedChain.chains.push_back($$);
		//YYACCEPT;
          }
          | P20 error P21 error P22 error P23 error P24 error P25 error P26 error P27 error P28 error P29 error P30 error P31 error P7
          {
		$$=4;
                std::cout << "Event Sequence Matched Failure Chain 4 " << std::endl;
		driver.matchedChain.chains.push_back($$);
          }
          | P32 error P33 error P34 error P35 error P36 error P37 error P34 error P38 error P39 error P40 error P41 error P42 error P43 error P44 error P45 error P46 error P47 error P48 error P49 error P46 error P50 error P51 error P52 error P53 error P54 error P55 error P56 error P57 error P58 error P7 error P6
          {
		$$=5;
                std::cout << "Event Sequence Matched Failure Chain 5 " << std::endl;
		driver.matchedChain.chains.push_back($$);
          }
	  | P28 error P59 error P29 error P30 error P60 error P18 error P11 error P61 error P62 error P63 error P64 error P65
	  {
		 $$=6;
		 std::cout << "Event Sequence Matched Failure Chain 6 " << std::endl;
		 driver.matchedChain.chains.push_back($$);
	  }
	  | P66 error P67 error P68 error P69 error P70 error P71 error P72 error P73 error P72 error P5 
	  { 
		 $$=7;
		 std::cout << "Event Sequence Matched Failure Chain 7 " << std::endl;
		 driver.matchedChain.chains.push_back($$);
	  }
	  | P61 error P62 error P63 error P63 error P74 error P65 error P19  
	  {
		 $$=8;
		 std::cout << "Event Sequence Matched Failure Chain 8 " << std::endl;
		 driver.matchedChain.chains.push_back($$);
		 //YYACCEPT;
	  }
	  | P77 error P78 error P79 error P80 error P81 error P78
	  {
		 $$=9;
		 std::cout << "Event Sequence Matched Failure Chain 9 " << std::endl;
		 driver.matchedChain.chains.push_back($$);
	  }
	  | P75 error P20 error P1 error P76 error P8 error P7
	  {
		$$=10;
		std::cout << "Event Sequence Matched Failure Chain 10 " << std::endl;
		driver.matchedChain.chains.push_back($$);
	  }
	  /*| DOUBLE
	  {
		std::cout << "Timestamp " << std::endl;
		yyclearin;
                yyerrok;

	  }*/
	  | error 
          {
		/*std::cout << "Encountered error " << @$ << std::endl;*/
		gettimeofday(&driver.matchedChain.tp1, NULL); /* current time */
		driver.matchedChain.currentTime = ((driver.matchedChain.tp1.tv_sec * 1000) + (driver.matchedChain.tp1.tv_usec/1000));
                driver.matchedChain.timediff = (driver.matchedChain.currentTime - yyla.value.longVal); /*milliseconds*/
                /*driver.matchedChain.timediff = ($1 - yyla.value.longVal);*/ /*lookahead's location value milliseconds*/
                /*std::cout << "Current Time at Parser is " << driver.matchedChain.currentTime << std::endl;*/ 
                /*std::cout << "Last time is " << yyla.value.longVal << std::endl; */
		if (driver.matchedChain.timediff <= driver.matchedChain.threshold) /* within time threshold */
                {
                        /*std::cout << "Time difference is " << driver.matchedChain.timediff << " msecs, is under threshold: Skip, Continue" << std::endl;*/
                        yyclearin;
                        yyerrok;
                }
                else {
                        /*std::cout << "Timeout exceeded, Abort !!" << driver.matchedChain.timediff << std::endl;*/
                        yyclearin;
                        yyerrok;
			/*YYERROR;*/
                }
          }
	  ;

start   : /* empty */
        | start EOL
        | start eventlist
          {
              /*std::cout << "Found eventlist" << std::endl;*/
          }
        | start eventlist EOL
          {
              /*std::cout << "Found EOL after eventlist" << std::endl;*/
          }
        | start eventlist END
          {
	      YYACCEPT;
              /*std::cout << "Found END of file after eventlist" << std::endl;*/
          }
	;

/*** END PHRASE - Change the phrase grammar rules above ***/

%% /*** Additional Code ***/
extern
void yyerror(char *s) {
  printf("Error '%s'\n", s);
}

void phrase::Parser::error(const Parser::location_type& l,
                           const std::string& m)
{
   driver.error(l, m);
}
/** \file parser.yy Contains the phrase Bison parser source */
