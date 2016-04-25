//
//  Charecter2.h
//  3D_Fight
//
//  Created by mac on 15-10-14.
//
//

#ifndef ___D_Fight__Charecter2__
#define ___D_Fight__Charecter2__

#include <stdio.h>
#include "cocos2d.h"
#include "CharecterBase.h"

USING_NS_CC;
class Charecter2:public CharecterBase
{
public:
    virtual bool init();
    CREATE_FUNC(Charecter2);
    virtual void load_animate();
    virtual void walk();
  //  void run();
  //  void yun();
    virtual void stand();
//    void attack_1();
//    void attack_2();
   // void dead();
    virtual void beizhan();
   // void behit();
   // bool _dead;
  //  void update(float dt);
    void LogicStep(float dt);
  //  bool _hit;
   // bool _sleep;
    virtual void mainLogic();
    
   // virtual void update(float dt);
 
  
    int LStep;
   
    
    
};

#endif /* defined(___D_Fight__Charecter2__) */
