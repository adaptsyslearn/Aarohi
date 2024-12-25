// A Bison parser, made by GNU Bison 3.0.4.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// Take the name prefix into account.
#define yylex   phraselex

// First part of user declarations.
#line 3 "parser.yy" // lalr1.cc:404
 /*** C/C++ Declarations ***/

#include <stdio.h>
#include <string.h>
#include <sstream>
#include <iostream>
#include <vector>
#include "expression.h"
#include <sys/time.h>

#line 49 "parser.cc" // lalr1.cc:404

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

#include "y.tab.h"

// User implementation prologue.
#line 91 "parser.yy" // lalr1.cc:412


#include "driver.h"
#include "scanner.h"

/* this "connects" the bison parser in the driver to the flex scanner class
 * object. it defines the yylex() function call to pull the next token from the
 * current lexer object of the driver context. */
#undef yylex
#define yylex driver.lexer->lex


#line 75 "parser.cc" // lalr1.cc:412


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (/*CONSTCOND*/ false)
# endif


// Suppress unused-variable warnings by "using" E.
#define YYUSE(E) ((void) (E))

// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << std::endl;                  \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE(Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void>(0)
# define YY_STACK_PRINT()                static_cast<void>(0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)


namespace phrase {
#line 161 "parser.cc" // lalr1.cc:479

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  Parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr = "";
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              // Fall through.
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }


  /// Build a parser object.
  Parser::Parser (class Driver& driver_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      driver (driver_yyarg)
  {}

  Parser::~Parser ()
  {}


  /*---------------.
  | Symbol types.  |
  `---------------*/

  inline
  Parser::syntax_error::syntax_error (const location_type& l, const std::string& m)
    : std::runtime_error (m)
    , location (l)
  {}

  // basic_symbol.
  template <typename Base>
  inline
  Parser::basic_symbol<Base>::basic_symbol ()
    : value ()
  {}

  template <typename Base>
  inline
  Parser::basic_symbol<Base>::basic_symbol (const basic_symbol& other)
    : Base (other)
    , value ()
    , location (other.location)
  {
    value = other.value;
  }


  template <typename Base>
  inline
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const semantic_type& v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}


  /// Constructor for valueless symbols.
  template <typename Base>
  inline
  Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const location_type& l)
    : Base (t)
    , value ()
    , location (l)
  {}

  template <typename Base>
  inline
  Parser::basic_symbol<Base>::~basic_symbol ()
  {
    clear ();
  }

  template <typename Base>
  inline
  void
  Parser::basic_symbol<Base>::clear ()
  {
    Base::clear ();
  }

  template <typename Base>
  inline
  bool
  Parser::basic_symbol<Base>::empty () const
  {
    return Base::type_get () == empty_symbol;
  }

  template <typename Base>
  inline
  void
  Parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move(s);
    value = s.value;
    location = s.location;
  }

  // by_type.
  inline
  Parser::by_type::by_type ()
    : type (empty_symbol)
  {}

  inline
  Parser::by_type::by_type (const by_type& other)
    : type (other.type)
  {}

  inline
  Parser::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  inline
  void
  Parser::by_type::clear ()
  {
    type = empty_symbol;
  }

  inline
  void
  Parser::by_type::move (by_type& that)
  {
    type = that.type;
    that.clear ();
  }

  inline
  int
  Parser::by_type::type_get () const
  {
    return type;
  }


  // by_state.
  inline
  Parser::by_state::by_state ()
    : state (empty_state)
  {}

  inline
  Parser::by_state::by_state (const by_state& other)
    : state (other.state)
  {}

  inline
  void
  Parser::by_state::clear ()
  {
    state = empty_state;
  }

  inline
  void
  Parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  inline
  Parser::by_state::by_state (state_type s)
    : state (s)
  {}

  inline
  Parser::symbol_number_type
  Parser::by_state::type_get () const
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[state];
  }

  inline
  Parser::stack_symbol_type::stack_symbol_type ()
  {}


  inline
  Parser::stack_symbol_type::stack_symbol_type (state_type s, symbol_type& that)
    : super_type (s, that.location)
  {
    value = that.value;
    // that is emptied.
    that.type = empty_symbol;
  }

  inline
  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    value = that.value;
    location = that.location;
    return *this;
  }


  template <typename Base>
  inline
  void
  Parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);

    // User destructor.
    switch (yysym.type_get ())
    {
            case 6: // "string"

#line 86 "parser.yy" // lalr1.cc:614
        { delete (yysym.value.stringVal); }
#line 414 "parser.cc" // lalr1.cc:614
        break;

      case 8: // component

#line 87 "parser.yy" // lalr1.cc:614
        { delete (yysym.value.stringVal); }
#line 421 "parser.cc" // lalr1.cc:614
        break;


      default:
        break;
    }
  }

#if YYDEBUG
  template <typename Base>
  void
  Parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " ("
        << yysym.location << ": ";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  inline
  void
  Parser::yypush_ (const char* m, state_type s, symbol_type& sym)
  {
    stack_symbol_type t (s, sym);
    yypush_ (m, t);
  }

  inline
  void
  Parser::yypush_ (const char* m, stack_symbol_type& s)
  {
    if (m)
      YY_SYMBOL_PRINT (m, s);
    yystack_.push (s);
  }

  inline
  void
  Parser::yypop_ (unsigned int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  Parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  Parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  Parser::debug_level_type
  Parser::debug_level () const
  {
    return yydebug_;
  }

  void
  Parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  inline Parser::state_type
  Parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  inline bool
  Parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
  Parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  Parser::parse ()
  {
    // State.
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

    // FIXME: This shoud be completely indented.  It is not yet to
    // avoid gratuitous conflicts when merging into the master branch.
    try
      {
    YYCDEBUG << "Starting parse" << std::endl;


    // User initialization code.
    #line 42 "/home/adas4/Aarohi/Aarohi_Code/src/parser.yy" // lalr1.cc:741
{
    // initialize the initial location object
    yyla.location.begin.filename = yyla.location.end.filename = &driver.streamname;
}

#line 559 "parser.cc" // lalr1.cc:741

    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, yyla);

    // A new symbol was pushed on the stack.
  yynewstate:
    YYCDEBUG << "Entering state " << yystack_[0].state << std::endl;

    // Accept?
    if (yystack_[0].state == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    // Backup.
  yybackup:

    // Try to take a decision without lookahead.
    yyn = yypact_[yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
        try
          {
            yyla.type = yytranslate_ (yylex (&yyla.value, &yyla.location));
          }
        catch (const syntax_error& yyexc)
          {
            error (yyexc);
            goto yyerrlab1;
          }
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      goto yydefault;

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", yyn, yyla);
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_(yystack_[yylen].state, yyr1_[yyn]);
      /* If YYLEN is nonzero, implement the default value of the
         action: '$$ = $1'.  Otherwise, use the top of the stack.

         Otherwise, the following line sets YYLHS.VALUE to garbage.
         This behavior is undocumented and Bison users should not rely
         upon it.  */
      if (yylen)
        yylhs.value = yystack_[yylen - 1].value;
      else
        yylhs.value = yystack_[0].value;

      // Compute the default @$.
      {
        slice<stack_symbol_type, stack_type> slice (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, slice, yylen);
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
      try
        {
          switch (yyn)
            {
  case 2:
#line 108 "parser.yy" // lalr1.cc:859
    { /*std::cout << "Expression it is " << std::endl;*/ }
#line 669 "parser.cc" // lalr1.cc:859
    break;

  case 3:
#line 110 "parser.yy" // lalr1.cc:859
    { 
		(yylhs.value.longVal) = (yystack_[2].value.longVal); 
		/*std::cout << "Encountered error after expression " << @$ << std::endl;*/
		yyclearin;
		yyerrok; 
	  }
#line 680 "parser.cc" // lalr1.cc:859
    break;

  case 4:
#line 119 "parser.yy" // lalr1.cc:859
    {
		(yylhs.value.longVal)=1;
		std::cout << "Event Sequence Matched Failure Chain 1 " << std::endl;
		driver.matchedChain.chains.push_back((yylhs.value.longVal));
          }
#line 690 "parser.cc" // lalr1.cc:859
    break;

  case 5:
#line 125 "parser.yy" // lalr1.cc:859
    {
		(yylhs.value.longVal)=2;
                std::cout << "Event Sequence Matched Failure Chain 2 " << std::endl;
		driver.matchedChain.chains.push_back((yylhs.value.longVal));
          }
#line 700 "parser.cc" // lalr1.cc:859
    break;

  case 6:
#line 131 "parser.yy" // lalr1.cc:859
    {
		(yylhs.value.longVal)=3;
                std::cout << "Event Sequence Matched Failure Chain 3 " << std::endl;
		driver.matchedChain.chains.push_back((yylhs.value.longVal));
		//YYACCEPT;
          }
#line 711 "parser.cc" // lalr1.cc:859
    break;

  case 7:
#line 138 "parser.yy" // lalr1.cc:859
    {
		(yylhs.value.longVal)=4;
                std::cout << "Event Sequence Matched Failure Chain 4 " << std::endl;
		driver.matchedChain.chains.push_back((yylhs.value.longVal));
          }
#line 721 "parser.cc" // lalr1.cc:859
    break;

  case 8:
#line 144 "parser.yy" // lalr1.cc:859
    {
		(yylhs.value.longVal)=5;
                std::cout << "Event Sequence Matched Failure Chain 5 " << std::endl;
		driver.matchedChain.chains.push_back((yylhs.value.longVal));
          }
#line 731 "parser.cc" // lalr1.cc:859
    break;

  case 9:
#line 150 "parser.yy" // lalr1.cc:859
    {
		 (yylhs.value.longVal)=6;
		 std::cout << "Event Sequence Matched Failure Chain 6 " << std::endl;
		 driver.matchedChain.chains.push_back((yylhs.value.longVal));
	  }
#line 741 "parser.cc" // lalr1.cc:859
    break;

  case 10:
#line 156 "parser.yy" // lalr1.cc:859
    { 
		 (yylhs.value.longVal)=7;
		 std::cout << "Event Sequence Matched Failure Chain 7 " << std::endl;
		 driver.matchedChain.chains.push_back((yylhs.value.longVal));
	  }
#line 751 "parser.cc" // lalr1.cc:859
    break;

  case 11:
#line 162 "parser.yy" // lalr1.cc:859
    {
		 (yylhs.value.longVal)=8;
		 std::cout << "Event Sequence Matched Failure Chain 8 " << std::endl;
		 driver.matchedChain.chains.push_back((yylhs.value.longVal));
		 //YYACCEPT;
	  }
#line 762 "parser.cc" // lalr1.cc:859
    break;

  case 12:
#line 169 "parser.yy" // lalr1.cc:859
    {
		 (yylhs.value.longVal)=9;
		 std::cout << "Event Sequence Matched Failure Chain 9 " << std::endl;
		 driver.matchedChain.chains.push_back((yylhs.value.longVal));
	  }
#line 772 "parser.cc" // lalr1.cc:859
    break;

  case 13:
#line 175 "parser.yy" // lalr1.cc:859
    {
		(yylhs.value.longVal)=10;
		std::cout << "Event Sequence Matched Failure Chain 10 " << std::endl;
		driver.matchedChain.chains.push_back((yylhs.value.longVal));
	  }
#line 782 "parser.cc" // lalr1.cc:859
    break;

  case 14:
#line 188 "parser.yy" // lalr1.cc:859
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
#line 808 "parser.cc" // lalr1.cc:859
    break;

  case 17:
#line 214 "parser.yy" // lalr1.cc:859
    {
              /*std::cout << "Found eventlist" << std::endl;*/
          }
#line 816 "parser.cc" // lalr1.cc:859
    break;

  case 18:
#line 218 "parser.yy" // lalr1.cc:859
    {
              /*std::cout << "Found EOL after eventlist" << std::endl;*/
          }
#line 824 "parser.cc" // lalr1.cc:859
    break;

  case 19:
#line 222 "parser.yy" // lalr1.cc:859
    {
	      YYACCEPT;
              /*std::cout << "Found END of file after eventlist" << std::endl;*/
          }
#line 833 "parser.cc" // lalr1.cc:859
    break;


#line 837 "parser.cc" // lalr1.cc:859
            default:
              break;
            }
        }
      catch (const syntax_error& yyexc)
        {
          error (yyexc);
          YYERROR;
        }
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, yylhs);
    }
    goto yynewstate;

  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yyla.location, yysyntax_error_ (yystack_[0].state, yyla));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;
    yyerror_range[1].location = yystack_[yylen - 1].location;
    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yyterror_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yyerror_range[1].location = yystack_[0].location;
          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = yyn;
      yypush_ ("Shifting", error_token);
    }
    goto yynewstate;

    // Accept.
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    // Abort.
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack"
                 << std::endl;
        // Do not try to display the values of the reclaimed symbols,
        // as their printer might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
  }

  void
  Parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what());
  }

  // Generate an error message.
  std::string
  Parser::yysyntax_error_ (state_type yystate, const symbol_type& yyla) const
  {
    // Number of reported tokens (one for the "unexpected", one per
    // "expected").
    size_t yycount = 0;
    // Its maximum.
    enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
    // Arguments of yyformat.
    char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];

    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state
         merging (from LALR or IELR) and default reductions corrupt the
         expected token list.  However, the list is correct for
         canonical LR with one exception: it will still contain any
         token that will not be accepted due to an error action in a
         later state.
    */
    if (!yyla.empty ())
      {
        int yytoken = yyla.type_get ();
        yyarg[yycount++] = yytname_[yytoken];
        int yyn = yypact_[yystate];
        if (!yy_pact_value_is_default_ (yyn))
          {
            /* Start YYX at -YYN if negative to avoid negative indexes in
               YYCHECK.  In other words, skip the first -YYN actions for
               this state because they are default actions.  */
            int yyxbegin = yyn < 0 ? -yyn : 0;
            // Stay within bounds of both yycheck and yytname.
            int yychecklim = yylast_ - yyn + 1;
            int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
            for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
              if (yycheck_[yyx + yyn] == yyx && yyx != yyterror_
                  && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
                {
                  if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                    {
                      yycount = 1;
                      break;
                    }
                  else
                    yyarg[yycount++] = yytname_[yyx];
                }
          }
      }

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
        YYCASE_(0, YY_("syntax error"));
        YYCASE_(1, YY_("syntax error, unexpected %s"));
        YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    size_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += yytnamerr_ (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char Parser::yypact_ninf_ = -61;

  const signed char Parser::yytable_ninf_ = -3;

  const short int
  Parser::yypact_[] =
  {
     -61,     0,   -61,   -61,   -61,     3,     5,     6,     7,     8,
       9,    10,    11,    13,    16,     2,    15,    19,    -2,    -6,
     -11,   -48,   -21,   -49,   -52,    -3,   -60,   -61,   -61,    30,
      33,    35,    36,    37,    38,    41,    44,    45,    47,    48,
     -61,    39,    29,    24,    23,    12,    14,   -17,   -19,    50,
     -27,    64,    65,    66,    67,    68,    70,    71,    74,    75,
      76,    63,    57,    52,    49,    40,    43,    17,     4,    -5,
      -1,    85,    93,    94,    95,    96,    97,    98,    99,   100,
     104,    89,    83,    84,    73,    42,    72,    25,    31,    92,
      22,   115,   117,   120,   121,   122,   123,   124,   125,   126,
     127,   111,   105,   106,   101,   102,    82,    58,    51,   118,
      46,   138,   139,   140,   141,   142,   143,   144,   145,   -61,
     -61,   128,   129,   130,   112,   131,   103,   132,    69,   -61,
     -61,   150,   151,   154,   155,   -61,   156,   133,   134,    86,
     110,    79,   160,   164,   165,   166,   167,   146,   135,   107,
     119,    87,   168,   171,   173,   176,   177,   157,   147,   108,
     137,   162,   181,   183,   184,   185,   -61,   172,   148,   116,
     149,   186,   192,   193,   194,   169,   153,   136,   152,   -61,
     196,   -61,   197,   180,   159,   -61,   200,   161,   202,   158,
     203,   163,   204,   170,   206,   174,   207,   175,   208,   179,
     209,   178,   210,   182,   211,   187,   215,   188,   217,   189,
     218,   190,   219,   191,   221,   195,   222,   198,   223,   212,
     224,   214,   -61
  };

  const unsigned char
  Parser::yydefact_[] =
  {
      15,     0,     1,    14,    16,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    17,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    19,    18,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       3,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    13,
      12,     0,     0,     0,     0,     0,     0,     0,     0,     4,
       5,     0,     0,     0,     0,    11,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    10,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     6,
       0,     9,     0,     0,     0,     7,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     8
  };

  const short int
  Parser::yypgoto_[] =
  {
     -61,   199,   -61,   -61
  };

  const signed char
  Parser::yydefgoto_[] =
  {
      -1,    15,    16,     1
  };

  const short int
  Parser::yytable_[] =
  {
       2,     3,    27,     4,    17,    28,    18,    19,    20,    21,
      22,    23,    24,     5,    25,    -2,    29,    26,    -2,    31,
       6,    32,    33,    34,    35,    36,     7,    37,    -2,    38,
      39,     3,     8,    30,    41,    -2,    42,    43,    44,    45,
       9,    -2,    46,     5,    10,    47,    48,    -2,    49,    50,
       6,    52,    53,    55,    51,    -2,     7,    54,    57,    -2,
      56,    58,     8,    59,    60,    61,    62,    63,    64,    65,
       9,    66,    67,    11,    10,    68,    69,    70,    12,    71,
      72,    73,    75,    79,    74,    78,    81,    13,    -2,    14,
      76,    80,    77,    -2,    82,    83,    84,    85,    86,    87,
      88,    89,    -2,    11,    -2,    90,    91,    92,    12,    94,
      93,    97,    99,    98,    95,   100,   101,    13,   102,    14,
      96,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   116,   115,   113,   118,   117,   120,   119,   114,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   134,
     132,   137,   138,   136,   133,   139,   140,   141,   131,   144,
     145,   147,   142,   135,   146,   148,   149,   150,   151,   157,
     155,   156,   158,   143,   159,   153,   152,   160,   161,   166,
     162,   154,   167,   164,   168,   169,   170,   175,   163,   165,
     172,   171,   173,   176,   177,   178,   180,   183,   184,   185,
     179,   187,   174,   189,   191,   193,   182,   195,   197,   199,
     201,   203,   205,   181,   186,   190,   207,   188,   209,   211,
     213,   192,   215,   217,   219,   221,     0,     0,    40,   194,
       0,   220,   222,     0,   196,     0,   198,   200,     0,     0,
     202,     0,     0,     0,     0,   204,     0,     0,     0,     0,
       0,   206,     0,   208,     0,   210,     0,   212,     0,   214,
       0,     0,     0,     0,   216,     0,     0,     0,   218
  };

  const signed char
  Parser::yycheck_[] =
  {
       0,     1,     0,     3,     1,     3,     1,     1,     1,     1,
       1,     1,     1,    13,     1,     0,     1,     1,     3,    21,
      20,    27,    33,    71,    45,    74,    26,    79,    13,    32,
      90,     1,    32,    14,     1,    20,     1,     1,     1,     1,
      40,    26,     1,    13,    44,     1,     1,    32,     1,     1,
      20,    22,    28,    41,    15,    40,    26,    34,    75,    44,
      46,    80,    32,    13,    91,     1,     1,     1,     1,     1,
      40,     1,     1,    73,    44,     1,     1,     1,    78,    16,
      23,    29,    42,    88,    35,    81,     1,    87,    73,    89,
      47,    92,    75,    78,     1,     1,     1,     1,     1,     1,
       1,     1,    87,    73,    89,     1,    17,    24,    78,    36,
      26,    86,    20,    82,    72,    93,     1,    87,     1,    89,
      48,     1,     1,     1,     1,     1,     1,     1,     1,    18,
      25,    49,    30,    27,    83,    77,    90,    19,    37,     1,
       1,     1,     1,     1,     1,     1,     1,    19,    19,    46,
      38,     1,     1,    84,    23,     1,     1,     1,    28,    73,
      50,     1,    29,    31,    85,     1,     1,     1,     1,     1,
      51,    84,     1,    39,     1,    40,    30,     1,     1,    17,
      23,    74,     1,    75,     1,     1,     1,     1,    41,    52,
      42,    19,    76,     1,     1,     1,    43,     1,     1,    19,
      31,     1,    53,     1,     1,     1,    54,     1,     1,     1,
       1,     1,     1,    77,    55,    57,     1,    56,     1,     1,
       1,    58,     1,     1,     1,     1,    -1,    -1,    29,    59,
      -1,    19,    18,    -1,    60,    -1,    61,    58,    -1,    -1,
      62,    -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,    -1,
      -1,    64,    -1,    65,    -1,    66,    -1,    67,    -1,    68,
      -1,    -1,    -1,    -1,    69,    -1,    -1,    -1,    70
  };

  const unsigned char
  Parser::yystos_[] =
  {
       0,   103,     0,     1,     3,    13,    20,    26,    32,    40,
      44,    73,    78,    87,    89,   101,   102,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     0,     3,     1,
      14,    21,    27,    33,    71,    45,    74,    79,    32,    90,
     101,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,    15,    22,    28,    34,    41,    46,    75,    80,    13,
      91,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,    16,    23,    29,    35,    42,    47,    75,    81,    88,
      92,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,    17,    24,    26,    36,    72,    48,    86,    82,    20,
      93,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,    18,    25,    27,    37,    30,    49,    77,    83,    19,
      90,     1,     1,     1,     1,     1,     1,     1,     1,    19,
      19,    28,    38,    23,    46,    31,    84,     1,     1,     1,
       1,     1,    29,    39,    73,    50,    85,     1,     1,     1,
       1,     1,    30,    40,    74,    51,    84,     1,     1,     1,
       1,     1,    23,    41,    75,    52,    17,     1,     1,     1,
       1,    19,    42,    76,    53,     1,     1,     1,     1,    31,
      43,    77,    54,     1,     1,    19,    55,     1,    56,     1,
      57,     1,    58,     1,    59,     1,    60,     1,    61,     1,
      58,     1,    62,     1,    63,     1,    64,     1,    65,     1,
      66,     1,    67,     1,    68,     1,    69,     1,    70,     1,
      19,     1,    18
  };

  const unsigned char
  Parser::yyr1_[] =
  {
       0,   100,   101,   101,   102,   102,   102,   102,   102,   102,
     102,   102,   102,   102,   102,   103,   103,   103,   103,   103
  };

  const unsigned char
  Parser::yyr2_[] =
  {
       0,     2,     1,     3,    13,    13,    23,    25,    61,    23,
      19,    13,    11,    11,     1,     0,     2,     2,     3,     3
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const Parser::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "\"end of line\"",
  "\"integer\"", "\"double\"", "\"string\"", "TIME", "component",
  "TIMESTAMP", "threshold", "PHRASE", "timediff", "P1", "P2", "P3", "P4",
  "P5", "P6", "P7", "P8", "P9", "P10", "P11", "P12", "P13", "P14", "P15",
  "P16", "P17", "P18", "P19", "P20", "P21", "P22", "P23", "P24", "P25",
  "P26", "P27", "P28", "P29", "P30", "P31", "P32", "P33", "P34", "P35",
  "P36", "P37", "P38", "P39", "P40", "P41", "P42", "P43", "P44", "P45",
  "P46", "P47", "P48", "P49", "P50", "P51", "P52", "P53", "P54", "P55",
  "P56", "P57", "P58", "P59", "P60", "P61", "P62", "P63", "P64", "P65",
  "P66", "P67", "P68", "P69", "P70", "P71", "P72", "P73", "P74", "P75",
  "P76", "P77", "P78", "P79", "P80", "P81", "P82", "IF", "THEN", "ELSE",
  "COMMA", "PLUS", "$accept", "eventlist", "expression", "start", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned char
  Parser::yyrline_[] =
  {
       0,   108,   108,   109,   118,   124,   130,   137,   143,   149,
     155,   161,   168,   174,   187,   211,   212,   213,   217,   221
  };

  // Print the state stack on the debug stream.
  void
  Parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << i->state;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  Parser::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):" << std::endl;
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

  // Symbol number corresponding to token number t.
  inline
  Parser::token_number_type
  Parser::yytranslate_ (int t)
  {
    static
    const token_number_type
    translate_table[] =
    {
     0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99
    };
    const unsigned int user_token_number_max_ = 354;
    const token_number_type undef_token_ = 2;

    if (static_cast<int>(t) <= yyeof_)
      return yyeof_;
    else if (static_cast<unsigned int> (t) <= user_token_number_max_)
      return translate_table[t];
    else
      return undef_token_;
  }


} // phrase
#line 1387 "parser.cc" // lalr1.cc:1167
#line 230 "parser.yy" // lalr1.cc:1168
 /*** Additional Code ***/
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
