//
// FILE: lemke.h -- Interface to Lemke solution module
//
// $Id$
//

#ifndef LEMKE_H
#define LEMKE_H

#include "nfg.h"
#include "mixedsol.h"
#include "glist.h"
#include "lhtab.h"
#include "gstatus.h"

class LemkeParams     {
  public:
    int dup_strat, trace, stopAfter;
    gOutput *tracefile;
    gStatus &status;
    
    LemkeParams(gStatus & = gstatus);
};

//
// The general-purpose interface to the solver routines
//

template <class T> class LemkeModule  {
private:
  const Nfg &NF;
  const NFSupport &support;
  const LemkeParams &params;
  long npivots;
  double time;
  T epsilon;
  int num_strats;
  gList<BFS<T> > List;
  gList<MixedSolution<T> > solutions;

public:
  LemkeModule(const Nfg &N, const LemkeParams &p, const NFSupport &);
  virtual ~LemkeModule();
  
  int Lemke(int dup = 0);
  int All_Lemke(int dup, LHTableau<T> &B, long &np);
  
  int Add_BFS(LHTableau<T> &B);
  long NumPivots(void) const;
  double Time(void) const;
  
  void AddSolutions(void);
  const gList<MixedSolution<T> > &GetSolutions(void) const;
//   void GetSolutions(gList<MixedSolution<T> > &) const;
};


#endif    // LEMKE_H





