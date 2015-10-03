
/*
Author: Andrew Arizala

Description: Code for the Refcounter class


*/

#include  <iostream>
#include  "refCounter.h"

using namespace std;


//
// Constructor
//
RefCounter::RefCounter()  :  m_cnt(new int(1))
{
  if  (! m_cnt)
  {
    cerr  <<  "Memory allocation error!"  <<  endl;
    exit(EXIT_FAILURE);
  }
}


//
// Copy constructor
//
RefCounter::RefCounter(const RefCounter  &rhs) :
  m_cnt(rhs.m_cnt)
{
  (*m_cnt)++;
}


//
// Destructor
//
RefCounter::~RefCounter()
{
  if  ( ! --(*m_cnt) )
    delete m_cnt;
 }

RefCounter &RefCounter::operator=(const RefCounter  &rhs){
	if (this != &rhs){
		if (!--(*m_cnt)){
			delete m_cnt;
		}

		m_cnt = rhs.m_cnt;

		(*m_cnt)++;
	}

	

	return *this;
	
} 
