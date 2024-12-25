/** \file expression.h Implements an phrase automaton class group. */

#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <map>
#include <vector>
#include <ostream>
#include <stdexcept>
#include <cmath>

/** EventState for event chain analysis. Different FCs can be detected **/
class EventState
{
public:
    virtual ~EventState()
    {
    }

    /// evaluate the complete failure chain and return whether a failure or not
    virtual double	evaluate() const = 0;

    /// output the chain to the given test phrase. 
    virtual void	print(std::ostream &os, unsigned int depth=0) const = 0;

    /// print() function
    static inline std::string indent(unsigned int d)
    {
	return std::string(d * 2, ' ');
    }

};

/** PhraseAutomata context used to save the parsed chains. This context is
 * passed along to the phrase::Driver class and filled during parsing via bison
 * actions. */
class phraseAutomata
{
public:

    /// type of the variable storage
    typedef std::map<std::string, double> event_details;

    /// phrases storage. maps of timstamps and phrases
    event_details	events;

    /// array of chains matched by the parser from an input stream
    //std::vector<EventState*>	chains;
    std::vector<long int>	chains;
    long int threshold = 240000; //4 mins in msecs 
    long int timediff, currentTime;

    struct timeval tp1;
    
    ~phraseAutomata()
    {
	clearChains();
    }

    /// Deallocate all saved matched FCs 
    void clearChains()
    {
	//for(unsigned int i = 0; i < chains.size(); ++i)
	//{
	    //delete chains[i];
	//}
	chains.clear();
    }

    /// if phrase exists in the storage
    bool existsVariable(const std::string &varname) const
    {
	return events.find(varname) != events.end();
    }
    
    /// return the phrase from the storage. throws an exception if it
    /// does not exist.
    double	getVariable(const std::string &varname) const
    {
	event_details::const_iterator vi = events.find(varname);
	if (vi == events.end())
	    throw(std::runtime_error("Unknown variable."));
	else
	    return vi->second;
    }
};

#endif // EXPRESSION_H
