#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

USING_NS_CC;

class HelloWorld : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    virtual void draw(Renderer *renderer, const Mat4 &transform, uint32_t flags) override;

    void onDraw(const Mat4 &transform, uint32_t flags);
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
    
    CustomCommand _customCommand;
    float xAngle={0};
};

#endif // __HELLOWORLD_SCENE_H__
