/** \file driver.cc Implementation of the phrase::Driver class. */

#include <fstream>
#include <sstream>
#include <cstring>
#include "driver.h"
#include "scanner.h"
#include "expression.h"

namespace phrase {

Driver::Driver(class phraseAutomata& _matchedChain)
    : trace_scanning(false),
      trace_parsing(false),
      matchedChain(_matchedChain)
{
}

bool Driver::parse_stream(std::istream& in, const std::string& sname)
{
    streamname = sname;
    Scanner scanner(&in);
    scanner.set_debug(trace_scanning);
    this->lexer = &scanner;

    Parser parser(*this);
    parser.set_debug_level(trace_parsing);
    return (parser.parse() == 0);
}

bool Driver::parse_file(const std::string &filename)
{
    std::ifstream in(filename.c_str());
    if (!in.good()) return false;
    return parse_stream(in, filename);
}

bool Driver::parse_string(const std::string &input, const std::string& sname)
{
    std::istringstream iss(input);
    return parse_stream(iss, sname);
}

/*--------------------------------------------------------------------
 * dumpChar
 *
 * Returning character
 *------------------------------------------------------------------*/
char dumpChar(char c) {
  if (  isprint(c)  )
    return c;
  return '@';
}

/* dumpString
 *
 * Dumping String to Character
 *------------------------------------------------------------------*/
char * dumpString(char *s) {
  static char buf[101];
  int i;
  int n = strlen(s);

  if (  n > 100  )
    n = 100;

  for (i=0; i<n; i++)
    buf[i] = dumpChar(s[i]);
  buf[i] = 0;
  return buf;
}


/*--------------------------------------------------------------------
 * BeginToken
 *
 * marks the beginning of a new token
 *------------------------------------------------------------------*/
void Driver:: BeginToken(char *t) {
  /*================================================================*/
  /* Track the last token read --------------------------------------*/
  int TokenStart = 0;
  int TokenLength = 0;
  int TokenNextStart = 0;
  int Row = 0;
  int Buffer = 0;
  TokenStart = TokenNextStart;
  TokenLength = strlen(t);
  TokenNextStart = Buffer; // + 1;

  /*================================================================*/
  /* location for bison --------------------------------------------*/
  //yylloc.first_line = Row;
  //yylloc.first_column = TokenStart;
  //yylloc.last_line = Row;
  //yylloc.last_column = TokenStart + TokenLength - 1;

  //printf("Token '%s' at %d:%d next at %d\n", dumpString(t),
  //                    yylloc.first_column,
  //                  yylloc.last_column, TokenNextStart);
}


void Driver::error(const class location& l,
		   const std::string& m)
{
    std::cerr << l << ": " << m << std::endl;
}

void Driver::error(const std::string& m)
{
    std::cerr << m << std::endl;
}

} // namespace phrase
