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

USING_NS_CC;
class Charecter2:public Sprite3D
{
public:
    virtual bool init();
    CREATE_FUNC(Charecter2);
    float walk_speed;
    float run_speed;
    int hp;
    void walk();
    void run();
    void yun();
    void stand();
    void attack_1();
    void attack_2();
    void dead();
    void beizhan();
    void behit();
    bool _dead;
    void update(float dt);
    
    bool _hit;
    bool _sleep;
    void main_logic();
private:
//    Animate3D* yy_stand;
//    Animate3D* yy_attack1;
//    Animate3D* yy_attack2;
//    Animate3D* yy_walk;
//    Animate3D* yy_run;
//    Animate3D* yy_yun;
//    Animate3D* yy_dead;
//    Animate3D* yy_beizhan;
    
    
};

#endif /* defined(___D_Fight__Charecter2__) */
