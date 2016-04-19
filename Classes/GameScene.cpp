//
//  GameScene.cpp
//  3D_Fight
//
//  Created by mac on 15-10-15.
//
//

#include "GameScene.h"
#include "City_layer.h"
//#include "ui_layer.h"
USING_NS_CC;

Scene* GameScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = GameScene::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool GameScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
//    ui_layer*ui=ui_layer::create();
//    addChild(ui,1,2);
    
    City_layer*ct=City_layer::create();
    addChild(ct,0,1);
   
    
    
    return true;
}

