//
//  CharecterBase.cpp
//  GreatMonster
//
//  Created by mac on 16-4-23.
//
//

#include "CharecterBase.h"
bool CharecterBase::init(){
    if (!Sprite3D::init()) {
        return false;
    }
    speedDirection=Vec3(1,0,0);
    this->scheduleUpdate();
    return true;
}

void CharecterBase::load_animate(){
    
}
void CharecterBase::walk(){
   
}
void CharecterBase::stand(){
    this->speedDirection=Vec3::ZERO;
}
void CharecterBase::beizhan(){
    this->speedDirection=Vec3::ZERO;
}
void CharecterBase::mainLogic(){
    
}
void CharecterBase::update(float dt){
    float angle =  Vec2(0,1).getAngle(Vec2(speedDirection.x,speedDirection.z));
    
    if(speedDirection.x!=0||speedDirection.z!=0){
    Quaternion tt(Vec3(0,-1,0),angle);
    this->setRotationQuat(tt);
    }
   
    this->setPosition3D(this->getPosition3D()+this->speedDirection*this->walk_speed);
}