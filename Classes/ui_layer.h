//
//  ui_layer.h
//  3D_fight
//
//  Created by mac on 15-10-7.
//
//

#ifndef ___D_fight__ui_layer__
#define ___D_fight__ui_layer__

#include <stdio.h>
#include "cocos2d.h"
USING_NS_CC;
class ui_layer : public Layer
{
public:
    bool run;
   static int fight_fit;
     virtual bool init();
     CREATE_FUNC(ui_layer);
    Vec2 getAnglePosition(float r,float angle);
    float getRad(Vec2 pos1);
    Vec2 rokerPosition;
    float rockerBGR;
    float deltax;
    float deltaz;
//    void changeCamera(Ref* psender);
//    void callback2(Ref* psender);
    void attack(Ref* psender);
    void is_run(Ref*psender);
    void update(float dt);
};

#endif /* defined(___D_fight__ui_layer__) */
