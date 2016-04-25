//
//  CharecterBase.h
//  GreatMonster
//
//  Created by mac on 16-4-23.
//
//

#ifndef __GreatMonster__CharecterBase__
#define __GreatMonster__CharecterBase__

#include <stdio.h>
#include "cocos2d.h"

USING_NS_CC;
class CharecterBase:public Sprite3D
{
public:
    virtual bool init();
    CREATE_FUNC(CharecterBase);
    virtual void load_animate();
    virtual void walk();
    virtual void stand();
    virtual void beizhan();
    virtual void mainLogic();
    virtual void update(float dt);
    Vec3 speedDirection;
    float walk_speed;


};

#endif /* defined(__GreatMonster__CharecterBase__) */
