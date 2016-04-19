//
//  ui_layer.cpp
//  3D_fight
//
//  Created by mac on 15-10-7.
//
//

#include "ui_layer.h"
#include "City_layer.h"
#include "GameScene.h"
#include "Charecter1.h"
#include "SimpleAudioEngine.h"
using namespace CocosDenshion;
int ui_layer::fight_fit=0;
bool ui_layer::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
     SimpleAudioEngine::getInstance()->playBackgroundMusic("voice/048.mp3",true);
    SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(0.2);
     SimpleAudioEngine::getInstance()->setEffectsVolume(1.f);
    
    run=false;
    deltax=0.f;
    deltaz=0.f;
    rokerPosition=Vec2(200,150);
    Sprite *spRockerBG=CCSprite::create("CG-1086.png");
    spRockerBG->setPosition(rokerPosition);
    spRockerBG->setOpacity(50);
    addChild(spRockerBG,1);
    rockerBGR=spRockerBG->getContentSize().width*0.5;
    auto spRockerF = Sprite::create("CG-7005.png");
    spRockerF->setPosition(rokerPosition);
    addChild(spRockerF, 2,1);

    auto attlistener=EventListenerTouchOneByOne::create();
    attlistener->onTouchBegan=[=](Touch*touch,Event*event){
        auto target=static_cast<Sprite*>(event->getCurrentTarget());
        Vec2 locationInNode=target->convertToNodeSpace(touch->getLocation());
        Size s=target->getContentSize();//点到判断碰撞
        Rect rect=Rect(0,0,s.width,s.height);
        if (rect.containsPoint(locationInNode)) {
              ui_layer::fight_fit=0;
            City_layer*gm=(City_layer*)this->getParent()->getChildByTag(1);
            Charecter1*spp=static_cast<Charecter1*>(gm->getChildByTag(9));
            if (run)
            {
                spp->run();
                SimpleAudioEngine::getInstance()->playEffect("voice/runn.wav",true,0.6f);
            }
            else
            {
            spp->walk();
                SimpleAudioEngine::getInstance()->playEffect("voice/walk.wav",true,0.6f);
            }
            return  true;
        }
        return false;
        
    };
    
    attlistener->onTouchMoved=[&](Touch*touch,Event*event){
        Vec2 point=touch->getLocation();
        auto target=static_cast<Sprite*>(event->getCurrentTarget());
        if (sqrt(pow((rokerPosition.x-point.x),2)+pow((rokerPosition.y-point.y),2))>=rockerBGR){
            float angle=getRad(point);
            target->setPosition(ccpAdd(getAnglePosition(rockerBGR, angle),rokerPosition));
        }else{
            target->setPosition(target->getPosition()+touch->getDelta());
        }
        
        float px=point.x-rokerPosition.x;
        float pz=point.y-rokerPosition.y;
        Vec2 temp=Vec2(px,pz);
        temp.normalize();
        deltax=temp.x;
        deltaz=-temp.y;
        
        //玩家变向
           City_layer*gm=(City_layer*)this->getParent()->getChildByTag(1);
        
            float dx=deltax*cos(gm->_rotation)+deltaz*sin(gm->_rotation);
            float dy=-deltax*sin(gm->_rotation)+deltaz*cos(gm->_rotation);
      
            if (dy<=0) {
                 gm->_firstrotation=-CC_RADIANS_TO_DEGREES(asin(dx))-90;
            }
            else{
            gm->_firstrotation=CC_RADIANS_TO_DEGREES(asin(dx))+90;
            }
            gm->getChildByTag(9)->setRotation3D(Vec3(0,gm->_firstrotation-90,0));
    };
    
    
    attlistener->onTouchEnded=[&](Touch*touch,Event*event){
        Sprite *spRockerF=(Sprite*)this->getChildByTag(1);
       // spRockerF->runAction(CCMoveTo::create(0.05, rokerPosition));
        spRockerF->setPosition(rokerPosition);
        deltax=0;
        deltaz=0;
        City_layer*gm=(City_layer*)this->getParent()->getChildByTag(1);
        Charecter1*spp=(Charecter1*)gm->getChildByTag(9);
        spp->stand();
           SimpleAudioEngine::getInstance()->stopAllEffects();
    };
    attlistener->setSwallowTouches(true);
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(attlistener,spRockerF);

//    auto item=MenuItemImage::create("CG-1492.png", "CG-1493.png", CC_CALLBACK_1(ui_layer::callback2,this));
//    item->setPosition(100,600);
//
//
//    auto item2=MenuItemImage::create("CG-1487.png", "CG-1486.png", CC_CALLBACK_1(ui_layer::changeCamera,this));
//    item2->setPosition(860,600);
//
    auto item=MenuItemImage::create("att1.png", "att2.png", CC_CALLBACK_1(ui_layer::attack,this));
    item->setPosition(800,150);
//    
  
    auto tol=MenuItemToggle::createWithCallback(CC_CALLBACK_1(ui_layer::is_run,this),
                                                MenuItemImage::create("CG-1494.png", "CG-1494.png"),
                                                MenuItemImage::create("CG-1493.png", "CG-1493.png"),
                                                
                                                NULL);
    tol->setPosition(50,600);
//    
    auto menu=Menu::create(item,tol,NULL);
    menu->setPosition(0,0);
    this->addChild(menu);
    
    auto sp_hp=Sprite::create("CG-1087.png");
    auto hp=ProgressTimer::create(sp_hp);
    hp->setType(ProgressTimer::Type::BAR);
    hp->setPercentage(Charecter1::_hp*2);
    hp->setPosition(820,620);
    hp->setMidpoint(Vec2(1,0));
    hp->setBarChangeRate(Vec2(1,0));
    addChild(hp,0,10);
    char text[64];
    sprintf(text,"%d/50", Charecter1::_hp);
    auto hp_str=Label::createWithBMFont("bitmapFontTest.fnt", text);
    hp_str->setPosition(820,580);
    addChild(hp_str,0,9);
    scheduleUpdate();
    return true;
}

void ui_layer::update(float dt)
{
    auto hp=(ProgressTimer*)this->getChildByTag(10);
    hp->setPercentage(Charecter1::_hp*2);
    char text[64];
    sprintf(text,"%d/50", Charecter1::_hp);
    auto hp_text=(Label*)this->getChildByTag(9);
    hp_text->setString(text);
    
}
float ui_layer::getRad(Vec2 pos1){
    float px1=pos1.x;
    float py1=pos1.y;
    float x=px1-rokerPosition.x;
    float y=py1-rokerPosition.y;
    float xie=sqrt(pow(x,2)+pow(y,2));
    float cosAngle=x/xie;
    float rad=acos(cosAngle);
    if (py1<rokerPosition.y) {
        rad=-rad;
    }
    return rad;
}

Vec2 ui_layer::getAnglePosition(float r,float angle){
    return Vec2(r*cos(angle),r*sin(angle));
}

//void ui_layer::changeCamera(Ref* psender){
//    GameLayer*gm=(GameLayer*)this->getParent()->getChildByTag(1);
//    gm->pCamera_I->setCameraFlag(CameraFlag::USER1);
//    gm->pCamera_III->setCameraFlag(CameraFlag::USER2);
//    gm->firstperson=true;
//    //this->getScene()->setPhysics3DDebugCamera(gm->pCamera_I);
//}
//
//void ui_layer::callback2(Ref* psender){
//    GameLayer*gm=(GameLayer*)this->getParent()->getChildByTag(1);
//    gm->pCamera_I->setCameraFlag(CameraFlag::USER2);
//    gm->pCamera_III->setCameraFlag(CameraFlag::USER1);
//    gm->firstperson=false;
//    float deltax=200*sin(gm->rotation);//x增量
//    float deltaz=200*cos(gm->rotation);//z增量
//    gm->pCamera_III->setPosition3D(gm->pla->getChildByTag(2)->getPosition3D()+Vec3(deltax,110,deltaz));
//    gm->pCamera_III->lookAt(gm->pla->getChildByTag(2)->getPosition3D());
//   // this->getScene()->setPhysics3DDebugCamera(gm->pCamera_III);
//}
void ui_layer::attack(Ref* psender)
{
    fight_fit++;
    City_layer*gm=(City_layer*)this->getParent()->getChildByTag(1);
    Charecter1*spp=(Charecter1*)gm->getChildByTag(9);
    spp->attack_1();
    
}
void ui_layer::is_run(Ref*psender){
    run=!run;
  }