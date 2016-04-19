//
//  City_layer.h
//  3D_Fight
//
//  Created by mac on 15-10-15.
//
//

#ifndef ___D_Fight__City_layer__
#define ___D_Fight__City_layer__

#include <stdio.h>
#include "cocos2d.h"
USING_NS_CC;
class City_layer : public Layer
{
public:
    
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // implement the "static create()" method manually
    CREATE_FUNC(City_layer);
    
    float _rotation;
    //float _firstrotation;
    Camera* pCamera;
    Terrain* _terrain;
   // void update(float dt);
    //void create_monster(Vec3 pos);
};

#endif /* defined(___D_Fight__City_layer__) */
