//
// FILE: liapsub.h -- Solve efg by liap on nfg
//
// $Id$
//

#ifndef LIAPSUB_H
#define LIAPSUB_H

#include "nliap.h"
#include "subsolve.h"

class efgLiapNfgSolve : public SubgameSolver  {
private:
  int nevals, subgame_number;
  gPVector<int> infoset_subgames;
  NFLiapParams params;
  BehavProfile<gNumber> start;

  int SolveSubgame(const Efg &, const EFSupport &, gList<BehavSolution> &);
  EfgAlgType AlgorithmID() const { return EfgAlg_NLIAPSUB; }    

public:
  efgLiapNfgSolve(const Efg &, const NFLiapParams &,
		  const BehavProfile<gNumber> &, int max = 0);
  virtual ~efgLiapNfgSolve();
  
  int NumEvals(void) const   { return nevals; }
};

#endif   // LIAPSUB_H
