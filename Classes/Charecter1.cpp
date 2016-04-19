//
//  Charecter1.cpp
//  3D_Fight
//
//  Created by mac on 15-10-14.
//
//

#include "Charecter1.h"
#include "ui_layer.h"
#include "SimpleAudioEngine.h"
using namespace CocosDenshion;
int Charecter1::_hp=50;
//聪之是2或
bool Charecter1::init(){
    if (!Sprite3D::init()) {
        return false;
    }
    this->initWithFile("newL.c3b");
    this->setTexture("long.png");
    //缓存动画
    load_animate();
    walk_speed=5;
    run_speed=10;
    
    _hit=false;
    return true;
}
void Charecter1::load_animate(){
    auto LLL=Animation3D::create("newL.c3b");
    Animation3DCache::getInstance()->addAnimation("long",LLL);
}
void Charecter1::walk(){
    this->stopAllActions();
     Animation3D* LLL=Animation3DCache::getInstance()->getAnimation("long");
     Animate3D* ghl_walk=Animate3D::createWithFrames(LLL,260, 299);
     this->runAction(RepeatForever::create(ghl_walk));
}
void Charecter1::run(){
    this->stopAllActions();
    Animation3D* LLL=Animation3DCache::getInstance()->getAnimation("long");
    Animate3D* ghl_run=Animate3D::createWithFrames(LLL,300, 326);
    this->runAction(RepeatForever::create(ghl_run));
}
void Charecter1::yun(){
    this->stopAllActions();
     Animation3D* LLL=Animation3DCache::getInstance()->getAnimation("long");
     Animate3D* ghl_yun=Animate3D::createWithFrames(LLL,327, 387);
    this->runAction(RepeatForever::create(ghl_yun));
}
void Charecter1::stand(){
     this->stopAllActions();
     Animation3D* LLL=Animation3DCache::getInstance()->getAnimation("long");
     Animate3D*ghl_stand=Animate3D::createWithFrames(LLL, 0, 136);
     this->runAction(RepeatForever::create(ghl_stand));
}
void Charecter1::attack_1(){
    if (ui_layer::fight_fit>1) {
        return;
    }
    this->stopAllActions();
     Animation3D* LLL=Animation3DCache::getInstance()->getAnimation("long");
    Animate3D* ghl_attack1=Animate3D::createWithFrames(LLL,175,210);
    this->runAction(Sequence::create(CallFunc::create([&](){
        
        Sprite3D*daoguang=Sprite3D::create("box.c3t","daoguang.png");
    
        daoguang->setPosition3D(Vec3(50,50,50));
        daoguang->setScaleX(10);
        daoguang->setScaleZ(20);
        daoguang->setCameraMask(2);
        daoguang->setOpacity(0);
        this->addChild(daoguang,0,1);
        daoguang->runAction(Sequence::create(DelayTime::create(0.4),FadeIn::create(0.1),MoveTo::create(0.2,Vec3(-50,50,50)),RemoveSelf::create(),NULL));
        
    }),ghl_attack1,CallFunc::create([&](){
        SimpleAudioEngine::getInstance()->playEffect("voice/att1.wav");
        _hit=false;
        if (ui_layer::fight_fit>=2)
            this->attack_2();
         else
         {
             ui_layer::fight_fit=0;
             this->beizhan();
         }
    }),NULL));
    
}
void Charecter1::attack_2(){
     Animation3D* LLL=Animation3DCache::getInstance()->getAnimation("long");
     Animate3D* ghl_attack2=Animate3D::createWithFrames(LLL,214, 259);
    this->runAction(Sequence::create(CallFunc::create([&](){
       
        Sprite3D*daoguang=Sprite3D::create("box.c3t","daoguang.png");
        daoguang->setPosition3D(Vec3(0,100,50));
        daoguang->setScaleY(10);
        daoguang->setScaleZ(20);
        daoguang->setCameraMask(2);
        daoguang->setOpacity(0);
        this->addChild(daoguang,0,1);
        daoguang->runAction(Sequence::create(DelayTime::create(0.5),FadeIn::create(0.05),MoveTo::create(0.15,Vec3(0,0,50)),RemoveSelf::create(),NULL));
        
    }),ghl_attack2,CallFunc::create([&](){
          SimpleAudioEngine::getInstance()->playEffect("voice/att2.wav");
        _hit=false;
        if (ui_layer::fight_fit>=3)
            this->attack_3();
        else
        {
            ui_layer::fight_fit=0;
            this->beizhan();
        }

    }),NULL));
}
void Charecter1::attack_3(){
    Animation3D* LLL=Animation3DCache::getInstance()->getAnimation("long");
     Animate3D* ghl_attack3=Animate3D::createWithFrames(LLL,168,210)->reverse();
    this->runAction(Sequence::create(CallFunc::create([&](){
        Sprite3D*daoguang=Sprite3D::create("box.c3t","daoguang.png");
        daoguang->setPosition3D(Vec3(-50,50,50));
        daoguang->setScaleX(10);
        daoguang->setScaleZ(20);
        daoguang->setCameraMask(2);
        daoguang->setOpacity(0);
        this->addChild(daoguang,0,1);
        daoguang->runAction(Sequence::create(DelayTime::create(0.5),FadeIn::create(0.1),MoveTo::create(0.15,Vec3(50,50,50)),RemoveSelf::create(),NULL));
        
    }),ghl_attack3,CallFunc::create([&](){
          SimpleAudioEngine::getInstance()->playEffect("voice/att3.wav");
        _hit=false;
        if (ui_layer::fight_fit>=4)
            this->attack_4();
        else
        {
            ui_layer::fight_fit=0;
            this->beizhan();
        }
        
    }),NULL));
}

void Charecter1::attack_4(){
    Animation3D* LLL=Animation3DCache::getInstance()->getAnimation("long");
    Animate3D* ghl_attack4=Animate3D::createWithFrames(LLL,214,259)->reverse();
    this->runAction(Sequence::create(CallFunc::create([&](){
        Sprite3D*daoguang=Sprite3D::create("box.c3t","daoguang.png");
        daoguang->setPosition3D(Vec3(0,0,50));
        daoguang->setScaleY(10);
        daoguang->setScaleZ(20);
        daoguang->setCameraMask(2);
        daoguang->setOpacity(0);
        this->addChild(daoguang,0,1);
        daoguang->runAction(Sequence::create(DelayTime::create(0.8),FadeIn::create(0.05),MoveTo::create(0.15,Vec3(0,100,50)),RemoveSelf::create(),NULL));
        
    }),ghl_attack4,CallFunc::create([&](){
          SimpleAudioEngine::getInstance()->playEffect("voice/att4.wav");
          _hit=false;
          ui_layer::fight_fit=0;
          this->beizhan();
    }),NULL));
}


void Charecter1::dead(){
    this->stopAllActions();
     Animation3D* LLL=Animation3DCache::getInstance()->getAnimation("long");
     Animate3D*ghl_dead=Animate3D::createWithFrames(LLL,388, 490);
    this->runAction(Sequence::create(ghl_dead,DelayTime::create(0.1),
                                                       CallFunc::create([&](){
        this->runAction(RemoveSelf::create());
    }),NULL));
}
void Charecter1::beizhan()
{
     this->stopAllActions();
     Animation3D* LLL=Animation3DCache::getInstance()->getAnimation("long");
     Animate3D*ghl_beizhan=Animate3D::createWithFrames(LLL,137,167);
     this->runAction(RepeatForever::create(ghl_beizhan));
}