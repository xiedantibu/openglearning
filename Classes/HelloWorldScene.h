#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "CocosGUI.h"
#include "VisibleRect.h"

using namespace cocos2d::ui;
USING_NS_CC;

class HelloWorld : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    void initWidget();
    void checkBoxSelectEvent(Ref*,CheckBox::EventType);
    
    virtual void draw(Renderer *renderer, const Mat4& transform, uint32_t flags) override;
    void onDraw(const Mat4 &transform, uint32_t flags);
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
    
    ~HelloWorld();
    CustomCommand _customCommand;

    int tag={1000};
};

#endif // __HELLOWORLD_SCENE_H__
