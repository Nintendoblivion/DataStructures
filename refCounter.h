
/*
Author: Andrew Arizala

Description: Header for Refcounter class


*/

#ifndef  refCounter_H
#define  refCounter_H


class RefCounter
{
  public  :

    RefCounter();

    RefCounter(const RefCounter  &rhs);

    ~RefCounter();

	RefCounter &operator=(const RefCounter  &rhs);


    bool  onlyInstance() const
                         {  return *m_cnt == 1;  }

  private  :

    int  *m_cnt;
};


#endif