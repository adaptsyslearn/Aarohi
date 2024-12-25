/** \file driver.h Declaration of the phrase::Driver class. */

#ifndef PHRASE_DRIVER_H
#define PHRASE_DRIVER_H

#include <string>
#include <vector>

class phraseAutomata;

/** 
 * phrase::Parser, phrase::Scanner and phrase::Driver */

namespace phrase {

class Driver
{
public:
    /// parser driver context
    Driver(class phraseAutomata& matchedChain);

    /// tracing debug of the scanner
    bool trace_scanning;

    /// tracing debug of the bison parser
    bool trace_parsing;

    /// Stream to be parsed
    std::string streamname;

    /** Invoke the scanner and parser for a stream.
     * @param in	input stream
     * @param sname	stream name for error messages
     * @return		true if successfully parsed
     */
    bool parse_stream(std::istream& in,
		      const std::string& sname = "stream input");

    /** Invoke the scanner and parser on an input string.
     * @param input	input string
     * @param sname	stream name for error messages
     * @return		true if successfully parsed
     */
    bool parse_string(const std::string& input,
		      const std::string& sname = "string stream");

    /** Invoke the scanner and parser on a file. Use parse_stream with a
     * std::ifstream if detection of file reading errors is required.
     * @param filename	input file name
     * @return		true if successfully parsed
     */
    bool parse_file(const std::string& filename);
    void BeginToken(char*);
    
    void error(const class location& l, const std::string& m);

    void error(const std::string& m);

    /** Pointer to the current lexer instance, this is used to connect the
     * parser to the scanner. It is used in the yylex macro. */
    class Scanner* lexer;

    /** Reference to the matchedChain filled during parsing of the
     *  Sequence of phrases */
    class phraseAutomata& matchedChain;
};

} // namespace phrase

#endif // PHRASE_DRIVER_H
