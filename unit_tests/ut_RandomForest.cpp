/*
 * ut_RandomTree.cpp
 *
 *  Created on: Mar 28, 2012
 *      Author: anthony
 */

#include <cppunit/extensions/HelperMacros.h>
#include "ut_RandomForest.h"
#include "RandomForest.h"
#include "Dataset.h"

#include <fstream>
#include <iostream>

using namespace std;

CPPUNIT_TEST_SUITE_REGISTRATION( ut_RandomForest );

//------------------------------------------------------------------------------

vector<string> Tokenize(const string& str,const string& delimiters)
{
  vector<string> tokens;
  string::size_type delimPos = 0, tokenPos = 0, pos = 0;

  if(str.length() < 1)
  {
    return tokens;
  }

  while (true)
  {
    delimPos = str.find_first_of(delimiters, pos);
    tokenPos = str.find_first_not_of(delimiters, pos);

    if(string::npos != delimPos)
    {
      if(string::npos != tokenPos)
      {
        if(tokenPos<delimPos)
        {
          tokens.push_back(str.substr(pos,delimPos-pos));
        }
        else
        {
          tokens.push_back("");
        }
      }
      else
      {
        tokens.push_back("");
      }
      pos = delimPos+1;
    }
    else
    {
      if(string::npos != tokenPos)
      {
        tokens.push_back(str.substr(pos));
      }
      else
      {
        tokens.push_back("");
      }
      break;
    }
  }
  return tokens;
}

//------------------------------------------------------------------------------

void ut_RandomForest::setUp( void )
{
  // Load in dataset.
  string line;
  vector<string> lines;
  ifstream file( "data/seq_val_1.csv", ios_base::in );
  int i = 0;
  while ( getline(file, line, '\n') )
  {
    if ( ++i > 10 ) break;
    lines.push_back( line );
  }

  // Tokenize first line.
  vector<string> l1t = Tokenize(lines[0], ",");

  // Create dataset.
  Dataset ds( lines.size(), l1t.size()-1 );
}

//------------------------------------------------------------------------------

void ut_RandomForest::tearDown( void )
{
  //
}

//------------------------------------------------------------------------------

void ut_RandomForest::testMethod_grow_forest( void )
{
  // Load in
}

//------------------------------------------------------------------------------

void ut_RandomForest::testMethod_classify( void )
{
  //
}

//------------------------------------------------------------------------------

void ut_RandomForest::testMethod_classify_oob_set( void )
{
  //
}

//------------------------------------------------------------------------------
