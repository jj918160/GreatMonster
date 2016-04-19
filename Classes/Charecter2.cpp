//
//  Charecter2.cpp
//  3D_Fight
//
//  Created by mac on 15-10-14.
//
//

#include "Charecter2.h"
#include "Charecter1.h"
#include "SimpleAudioEngine.h"
using namespace CocosDenshion;
bool Charecter2::init(){
    if (!Sprite3D::init()) {
        return false;
    }
    _sleep=true;
    _dead=false;
    _hit=false;
    hp=10;
    this->initWithFile("newY.c3b");
    this->setTexture("yaoyao1.png");
    //缓存动画
    auto YYY=Animation3D::create("newY.c3b");
    Animation3DCache::getInstance()->addAnimation("yaoyao",YYY);
    walk_speed=5;
    run_speed=10;
//    yy_stand=Animate3D::createWithFrames(YYY, 0, 136);
//    yy_beizhan=Animate3D::createWithFrames(YYY,137,167);
//    yy_attack1=Animate3D::createWithFrames(YYY,168,218);
//    yy_attack2=Animate3D::createWithFrames(YYY,219, 263);
//    yy_walk=Animate3D::createWithFrames(YYY,264, 303);
//    yy_run=Animate3D::createWithFrames(YYY,300, 330);
//    yy_yun=Animate3D::createWithFrames(YYY,331, 376);
//    yy_dead=Animate3D::createWithFrames(YYY,377, 420);
    scheduleUpdate();
    return true;
}

void Charecter2::walk(){
    this->stopAllActions();
    Animation3D* YYY=Animation3DCache::getInstance()->getAnimation("yaoyao");
    Animate3D* yy_walk=Animate3D::createWithFrames(YYY,264,303);
    this->runAction(RepeatForever::create(yy_walk));
    
}
void Charecter2::run(){
    this->stopAllActions();
    Animation3D* YYY=Animation3DCache::getInstance()->getAnimation("yaoyao");
    Animate3D* yy_run=Animate3D::createWithFrames(YYY,300, 330);
    this->runAction(RepeatForever::create(yy_run));
  
}
void Charecter2::yun(){
    this->stopAllActions();
    Animation3D* YYY=Animation3DCache::getInstance()->getAnimation("yaoyao");
    Animate3D* yy_yun=Animate3D::createWithFrames(YYY,331, 376);
    this->runAction(RepeatForever::create(yy_yun));
    
}
void Charecter2::stand(){
    this->stopAllActions();
    Animation3D* YYY=Animation3DCache::getInstance()->getAnimation("yaoyao");
    Animate3D*yy_stand=Animate3D::createWithFrames(YYY, 0, 136);
    this->runAction(RepeatForever::create(yy_stand));
    
}
void Charecter2::behit(){
    this->stopAllActions();
    Animation3D* YYY=Animation3DCache::getInstance()->getAnimation("yaoyao");
    Animate3D*yy_hit=Animate3D::createWithFrames(YYY, 57, 80);
    this->runAction(Sequence::create(yy_hit,CallFunc::create([&](){
        auto player=static_cast<Charecter1*>(this->getParent()->getChildByTag(9));
        player->_hit=false;
        this->beizhan();
        this->_hit=false;
    }),NULL));
}
void Charecter2::attack_1(){
    this->stopAllActions();
    Animation3D* YYY=Animation3DCache::getInstance()->getAnimation("yaoyao");
    Animate3D* yy_attack1=Animate3D::createWithFrames(YYY,168,218);
    this->runAction(Sequence::create(yy_attack1,CallFunc::create([&](){
          SimpleAudioEngine::getInstance()->playEffect("voice/mon_att1.wav");
            this->run();
        _hit=false;
        Charecter1::_hp--;
    }),NULL));
}
void Charecter2::attack_2(){
    this->stopAllActions();
    Animation3D* YYY=Animation3DCache::getInstance()->getAnimation("yaoyao");
    Animate3D* yy_attack1=Animate3D::createWithFrames(YYY,168,218);
    Animate3D* yy_attack2=Animate3D::createWithFrames(YYY,219,263);
    this->runAction(Sequence::create(yy_attack1,yy_attack2,CallFunc::create([&](){
        this->run();
        _hit=false;
        Charecter1::_hp=Charecter1::_hp-2;
    }),NULL));
}
void Charecter2::dead(){
    this->stopAllActions();
    Animation3D* YYY=Animation3DCache::getInstance()->getAnimation("yaoyao");
    Animate3D* yy_dead=Animate3D::createWithFrames(YYY,377,420);
    this->runAction(Sequence::create(yy_dead,DelayTime::create(0.1),FadeOut::create(2),
                                     CallFunc::create([&](){
        this->runAction(RemoveSelf::create());
    }),NULL));
}
void Charecter2::beizhan()
{
    this->stopAllActions();
    Animation3D* YYY=Animation3DCache::getInstance()->getAnimation("yaoyao");
    Animate3D*yy_beizhan=Animate3D::createWithFrames(YYY,137,167);
    this->runAction(RepeatForever::create(yy_beizhan));
}
void Charecter2::update(float dt){
    //死亡
    if (_dead) {
        return;
    }
    //判断死亡
    if (hp<=0) {
        _dead=true;
         SimpleAudioEngine::getInstance()->playEffect("voice/dead.wav");
        this->dead();
    }
    //攻击逻辑
    auto player=static_cast<Charecter1*>(this->getParent()->getChildByTag(9));
    auto daoguang=(Sprite3D*)player->getChildByTag(1);
    if (daoguang&&!player->_hit&&this->getAABB().intersects(daoguang->getAABB())) {
            player->_hit=true;
          SimpleAudioEngine::getInstance()->playEffect("voice/mon_att2.wav");
        this->runAction(Sequence::create(DelayTime::create(0.1),CallFunc::create([&](){
             this->behit();
            hp--;
        }), NULL));
                }
        main_logic();
    }
void Charecter2::main_logic(){
     auto player=static_cast<Charecter1*>(this->getParent()->getChildByTag(9));
    //被唤醒
    if (_sleep&&(this->getPosition3D()-player->getPosition3D()).lengthSquared()<40000) {
        _sleep=false;
        //追人，砍
        this->run();
    }
    float distannce=(this->getPosition3D()-player->getPosition3D()).lengthSquared();

    if (distannce>2500) {
        //追踪
    if (!_sleep&&!_hit) {
        Vec3 des=player->getPosition3D();
        float x=des.x-this->getPosition3D().x;
        float z=des.z-this->getPosition3D().z;
        this->setPosition3D(this->getPosition3D()+Vec3(x/(run_speed*5),0,z/(run_speed*5)));
        float rotate=CC_RADIANS_TO_DEGREES(asin(x/(des-this->getPosition3D()).length()));
        if (z<0) {
            rotate=180-rotate;
        }
        this->setRotation3D(Vec3(0,rotate,0));
        }
    }
    else
    {
    //攻击
    if(!_hit){
            _hit=true;
            int x=arc4random()%2;
            if (x==1)
                this->attack_1();
            else
                this->attack_2();
             }
    }
}