#include "HelloWorldScene.h"

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}
HelloWorld::~HelloWorld()
{
        if (cube) {
            cube->release();
        }
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    auto listenter=EventListenerTouchOneByOne::create();
    listenter->onTouchBegan=CC_CALLBACK_2(HelloWorld::onTouchBegan, this);
    listenter->onTouchMoved=CC_CALLBACK_2(HelloWorld::onTouchMoved, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listenter, this);
        cube=new Cube();
        if (cube) {
            cube->retain();
            this->addChild(cube);
        }else
        {
            return false;
        }


    return true;
}
bool HelloWorld::onTouchBegan(Touch *touch, Event *unused_event)
{

    return  true;
}
void HelloWorld::onTouchMoved(Touch *touch, Event *unused_event)
{

}

