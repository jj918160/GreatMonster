//
//  Charecter1.h
//  3D_Fight
//
//  Created by mac on 15-10-14.
//
//

#ifndef ___D_Fight__Charecter1__
#define ___D_Fight__Charecter1__

#include <stdio.h>
#include "cocos2d.h"

USING_NS_CC;
class Charecter1:public Sprite3D
{
public:
    virtual bool init();
    CREATE_FUNC(Charecter1);
    void load_animate();
    void walk();
    void run();
    void yun();
    void stand();
    void attack_1();
    void attack_2();
    void attack_3();
    void attack_4();
    void dead();
    void beizhan();
    float walk_speed;
    float run_speed;
    bool _hit;
    static int _hp;
private:
//    Animate3D* ghl_stand;
//    Animate3D* ghl_attack1;
//    Animate3D* ghl_attack2;
//    Animate3D* ghl_walk;
//    Animate3D* ghl_run;
//    Animate3D* ghl_yun;
//    Animate3D* ghl_dead;
//    Animate3D* ghl_beizhan;
    
    
};
#endif /* defined(___D_Fight__Charecter1__) */
