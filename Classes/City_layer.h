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
#include "DrawNode3D.h"
USING_NS_CC;
class City_layer : public Layer
{
public:
    
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // implement the "static create()" method manually
    CREATE_FUNC(City_layer);
    
    Sprite3D*selected;
    float _rotation;
    //float _firstrotation;
    Camera* pCamera;
    Terrain* _terrain;
    Plane horizontalPlane;
    void create_house(std::string name,Vec3 pos,Vec3 rotate,float scale=1.f);
    void create_human1(Vec3 pos,float scale=1.f);
    void create_human2(Vec3 pos,float scale=1.f);
   // void create_human1(std::string name,std::string TextureName,Vec3 pos,Vec3 rotate,float scale=1.f);
    // void create_human2(std::string name,std::string TextureName,Vec3 pos,Vec3 rotate,float scale=1.f);
    DrawNode3D*node1;
   
    Vector<Sprite3D*>vecObj;
    virtual void update(float dt);
    
    float _distance;
   // void update(float dt);
    //void create_monster(Vec3 pos);;
    void unproject(const Mat4& viewProjection, const Size* viewport, Vec3* src, Vec3* dst);
    void calculateRayByLocationInView(Ray* ray, const Vec2& location);
};

#endif /* defined(___D_Fight__City_layer__) */
