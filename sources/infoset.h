//
// FILE: infoset.h -- Declaration of Infoset class
//
// $Id$
//

#ifndef INFOSET_H
#define INFOSET_H

#ifdef __GNUG__
#pragma interface
#endif   // __GNUG__

#include "gvector.h"

#include "efplayer.h"

class Node;

class Lexicon;

class Action   {
  friend class Efg;
  friend class BehavProfile<double>;
  friend class BehavProfile<gRational>;
  friend class Infoset;
  private:
    int number;
    gString name;
    Infoset *owner;

    Action(int br, const gString &n, Infoset *s)
      : number(br), name(n), owner(s)   { }
    ~Action()   { }

  public:
    const gString &GetName(void) const   { return name; }
    void SetName(const gString &s)       { name = s; }

    int GetNumber(void) const        { return number; }
    Infoset *BelongsTo(void) const   { return owner; }
};

class Infoset   {
  friend class Efg;
  friend class EFPlayer;
  friend class BehavProfile<double>;
  friend class BehavProfile<gRational>;
  friend class Lexicon;

  protected:
    Efg *E;
    int number;
    gString name;
    EFPlayer *player;
    gBlock<Action *> actions;
    gBlock<Node *> members;
    int flag, whichbranch;
    
    Infoset(Efg *e, int n, EFPlayer *p, int br);
    virtual ~Infoset();  

    virtual void PrintActions(gOutput &f) const;

  public:
    Efg *Game(void) const   { return E; }

    bool IsChanceInfoset(void) const   { return (player->IsChance()); }

    EFPlayer *GetPlayer(void) const    { return player; }

    void SetName(const gString &s)    { name = s; }
    const gString &GetName(void) const   { return name; }

    virtual Action *InsertAction(int where);
    virtual void RemoveAction(int which);

    void SetActionName(int i, const gString &s)
      { actions[i]->name = s; }
    const gString &GetActionName(int i) const  { return actions[i]->name; }

    const gArray<Action *> &Actions(void) const  { return actions; }  
    int NumActions(void) const   { return actions.Length(); }

    const gArray<Node *> &Members(void) const   { return members; }
    int NumMembers(void) const   { return members.Length(); }

    int GetNumber(void) const    { return number; }
};



#endif   //# INFOSET_H
