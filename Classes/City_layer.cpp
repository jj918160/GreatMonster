//
//  City_layer.cpp
//  3D_Fight
//
//  Created by mac on 15-10-15.
//
//

#include "City_layer.h"
//#include "Charecter1.h"
//#include "Charecter2.h"
//#include "ui_layer.h"
#include "DrawNode3D.h"
// on "init" you need to initialize your instance
bool City_layer::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    _rotation=0.f;
    //_firstrotation=0.f;
    
    Size size=Director::getInstance()->getWinSize();
    pCamera=Camera::createPerspective(60.0,size.width/size.height,0.1f,2000);
    pCamera->setCameraFlag(CameraFlag::USER1);
    pCamera->setPosition3D(Vec3(100,50,0));
    pCamera->lookAt(Vec3(0,0,0));
    addChild(pCamera);
    //sdsdsdsd
    
   // 天空盒
//    Skybox*sky=Skybox::create("Default/desert_left.jpg", "Default/desert_right.jpg", "Default/desert_top.jpg", "Default/desert_top.jpg", "Default/desert_front.jpg", "Default/desert_back.jpg");
//    sky->setCameraMask(2);
//    addChild(sky);

    Terrain::DetailMap r("TerrainTest/dirt.jpg"),g("TerrainTest/Grass2.jpg"),b("TerrainTest/road.jpg"),a("TerrainTest/GreenSkin.jpg");
    
    Terrain::TerrainData data("TerrainTest/heightmap0.png","TerrainTest/alphamapyellow.png",r,g,b,a);
    
    _terrain = Terrain::create(data,Terrain::CrackFixedType::SKIRT);
    
    _terrain->setLODDistance(3.2f,6.4f,9.6f);
    _terrain->setMaxDetailMapAmount(4);
    addChild(_terrain);
    _terrain->setScale(20.f, 1.f);
    _terrain->setScaleZ(20.f);
    _terrain->setCameraMask(2);
    _terrain->setDrawWire(false);

    
    
    
//    auto floor=Sprite3D::create("plane.c3t","plane.png");
//    floor->setPosition3D(Vec3(480,0,0));
//    floor->setScaleX(100);
//    floor->setScaleY(100);
//    floor->setRotation3D(Vec3(90,0,0));
//    floor->setCameraMask(2);
//    addChild(floor);
//    
//    
//    Charecter1*player=Charecter1::create();
//    player->setPosition3D(Vec3(480,10,0));
//    player->setRotation3D(Vec3(0,0,0));
//    player->stand();
//    player->setCameraMask(2);
//    addChild(player,0,9);
//    
//    create_monster(Vec3(300,10,200));
//    create_monster(Vec3(500,10,-100));
//    create_monster(Vec3(-100,10,-400));
//    create_monster(Vec3(-100,10,300));
//    create_monster(Vec3(-900,10,1300));
//    create_monster(Vec3(-900,10,-1300));
//     create_monster(Vec3(1500,10,1300));
//     create_monster(Vec3(1500,10,-1300));
    auto touchEvt=EventListenerTouchOneByOne::create();
    touchEvt->onTouchBegan=[=](Touch*ptouch,Event*pevent){
        
        return true;
    };
    touchEvt->onTouchMoved=[=](Touch*ptouch,Event*pevent){
           // 圆面相机 第3人称相机的移动
        
            auto location=ptouch->getLocation();
            Vec2 newPos=ptouch->getPreviousLocation()-location;
            _rotation+=newPos.x/1000; //算出角度
       
            float deltax=100*sin(_rotation);//x增量
            float deltaz=100*cos(_rotation);//z增量
            pCamera->setPosition3D(Vec3(deltax,50,deltaz));
            pCamera->lookAt(Vec3(0,0,0));
   
           };
    
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchEvt,this);
//
//    scheduleUpdate();
    
    return true;
}


//void City_layer::update(float dt)
//{
//        ui_layer*ui=(ui_layer*)this->getParent()->getChildByTag(2);
//        float dz=-ui->deltax*sin(_rotation)+ui->deltaz*cos(_rotation);
//        float dx=ui->deltax*cos(_rotation)+ui->deltaz*sin(_rotation);
//        auto player=(Charecter1*)this->getChildByTag(9);
//    if(ui->run)
//        player->setPosition3D(player->getPosition3D()+Vec3(dx,0,dz)*player->run_speed);
//    else
//        player->setPosition3D(player->getPosition3D()+Vec3(dx,0,dz)*player->walk_speed);
//
//        float deltax=300*sin(_rotation);//x增量
//        float deltaz=300*cos(_rotation);//z增量
//        pCamera->setPosition3D(player->getPosition3D()+Vec3(deltax,450,deltaz));
//        pCamera->lookAt(player->getPosition3D());
//        
//   }
//void City_layer::create_monster(Vec3 pos){
//    Charecter2*monster=Charecter2::create();
//    monster->setPosition3D(pos);
//    monster->setRotation3D(Vec3(0,0,0));
//    monster->stand();
//    monster->setCameraMask(2);
//    addChild(monster);
//    
//}

