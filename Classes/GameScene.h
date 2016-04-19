//
//  GameScene.h
//  3D_Fight
//
//  Created by mac on 15-10-15.
//
//

#ifndef ___D_Fight__GameScene__
#define ___D_Fight__GameScene__

#include <stdio.h>
#include "cocos2d.h"
USING_NS_CC;
class GameScene : public Layer
{
public:
  
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static Scene* createScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // implement the "static create()" method manually
    CREATE_FUNC(GameScene);
    
};

#endif /* defined(___D_Fight__GameScene__) */
