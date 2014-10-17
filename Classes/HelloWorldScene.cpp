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

    glClearColor(0.5, 0.5, 0.5, 1);
    
    initWidget();
    
    GLProgram *program=GLProgram::createWithFilenames("sample5_6.vert", "sample5_6.frag");
    this->setGLProgram(program);
    
    return true;
}

void HelloWorld::draw(Renderer *renderer, const Mat4& transform, uint32_t flags)
{

//    Director::getInstance()->setViewport();
    _customCommand.init(_globalZOrder);
    _customCommand.func = CC_CALLBACK_0(HelloWorld::onDraw, this, transform, flags);
    renderer->addCommand(&_customCommand);

    
}
void HelloWorld::onDraw(const Mat4 &transform, uint32_t flags)
{

    Size visibleSize=Director::getInstance()->getVisibleSize();
    float vertices[] = {
        visibleSize.width/2, visibleSize.height/2, 0,
        visibleSize.width-100, visibleSize.height-100,0,
        100, visibleSize.height-100, 0,
        100, 100, 0,
        visibleSize.width-100, 100, 0, };
    
    float colors[] = {
        1, 1, 0, 0,// 黄
        1, 1, 1, 0,// 白
        0, 1, 0, 0,// 绿
        1, 1, 1, 0,// 白
        1, 1, 0, 0,// 黄
    };
    
    auto program=this->getGLProgram();
    program->use();
    program->setUniformsForBuiltins();
    glEnableVertexAttribArray(GLProgram::VERTEX_ATTRIB_POSITION);
    glVertexAttribPointer(GLProgram::VERTEX_ATTRIB_POSITION, 3, GL_FLOAT, GL_FALSE, 0, vertices);
    
    glEnableVertexAttribArray(GLProgram::VERTEX_ATTRIB_COLOR);
    glVertexAttribPointer(GLProgram::VERTEX_ATTRIB_COLOR, 4, GL_FLOAT, GL_FALSE, 0, colors);
    glLineWidth( 5.0f );
    switch (tag) {
        case 1000:
            glDrawArrays(GL_POINTS, 0, 5);
            break;
        case 1001:
            glDrawArrays(GL_LINE_STRIP, 0, 5);
            break;
        case 1002:
            glDrawArrays(GL_LINES, 0, 5);
            break;
        case  1003:
            glDrawArrays(GL_LINE_LOOP, 0, 5);
            break;
        default:
            break;
    }
    CC_INCREMENT_GL_DRAWN_BATCHES_AND_VERTICES(1, 5);

    CHECK_GL_ERROR_DEBUG();
}



void HelloWorld::initWidget()
{
    CheckBox *pointsCheckBox=CheckBox::create("check_box_normal.png",
                                              "check_box_normal_press.png",
                                              "check_box_active.png",
                                              "check_box_normal_disable.png",
                                              "check_box_active_disable.png");
    pointsCheckBox->setPosition(Vec2(VisibleRect::left().x+pointsCheckBox->getContentSize().width+20,VisibleRect::top().y-pointsCheckBox->getContentSize().height-20));
    pointsCheckBox->setTag(1000);
    pointsCheckBox->addEventListener(CC_CALLBACK_2(HelloWorld::checkBoxSelectEvent,this));
    this->addChild(pointsCheckBox);
    Text *pointsText = Text::create("GL_POINTS", "Arial", 20);
    pointsText->setTextColor(Color4B::GREEN);
    pointsText->setPosition(Vec2(pointsCheckBox->getPosition().x+pointsCheckBox->getContentSize().width/2+pointsCheckBox->getContentSize().width, pointsCheckBox->getPosition().y));
    pointsText->setAnchorPoint(Vec2(0, 0.5));
    this->addChild(pointsText);
    
    
    CheckBox *lineStripCheckBox=CheckBox::create("check_box_normal.png",
                                                 "check_box_normal_press.png",
                                                 "check_box_active.png",
                                                 "check_box_normal_disable.png",
                                                 "check_box_active_disable.png");

    lineStripCheckBox->setPosition(Vec2(pointsText->getPosition().x+pointsText->getContentSize().width+lineStripCheckBox->getContentSize().width+20,pointsText->getPosition().y));
    lineStripCheckBox->setTag(1001);
    lineStripCheckBox->addEventListener(CC_CALLBACK_2(HelloWorld::checkBoxSelectEvent, this));
    this->addChild(lineStripCheckBox);
    Text *lineStripText = Text::create("GL_LINE_STRIP", "Arial", 20);
    lineStripText->setTextColor(Color4B::GREEN);
    lineStripText->setPosition(Vec2(lineStripCheckBox->getPosition().x+lineStripCheckBox->getContentSize().width/2+lineStripCheckBox->getContentSize().width, pointsCheckBox->getPosition().y));
    lineStripText->setAnchorPoint(Vec2(0, 0.5));
    this->addChild(lineStripText);
    
    
    CheckBox *lineCheckBox=CheckBox::create("check_box_normal.png",
                                                 "check_box_normal_press.png",
                                                 "check_box_active.png",
                                                 "check_box_normal_disable.png",
                                                 "check_box_active_disable.png");
    
    lineCheckBox->setPosition(Vec2(lineStripText->getPosition().x+lineStripText->getContentSize().width+lineCheckBox->getContentSize().width+20,lineStripText->getPosition().y));
    lineCheckBox->setTag(1002);
    lineCheckBox->addEventListener(CC_CALLBACK_2(HelloWorld::checkBoxSelectEvent, this));
    this->addChild(lineCheckBox);
    Text *lineText = Text::create("GL_LINE", "Arial", 20);
    lineText->setTextColor(Color4B::GREEN);
    lineText->setPosition(Vec2(lineCheckBox->getPosition().x+lineCheckBox->getContentSize().width/2+lineCheckBox->getContentSize().width, lineCheckBox->getPosition().y));
    lineText->setAnchorPoint(Vec2(0, 0.5));
    this->addChild(lineText);

    CheckBox *lineLoopCheckBox=CheckBox::create("check_box_normal.png",
                                            "check_box_normal_press.png",
                                            "check_box_active.png",
                                            "check_box_normal_disable.png",
                                            "check_box_active_disable.png");
    
    lineLoopCheckBox->setPosition(Vec2(lineText->getPosition().x+lineText->getContentSize().width+lineLoopCheckBox->getContentSize().width+20,lineStripText->getPosition().y));
    lineLoopCheckBox->setTag(1003);
    lineLoopCheckBox->addEventListener(CC_CALLBACK_2(HelloWorld::checkBoxSelectEvent, this));
    this->addChild(lineLoopCheckBox);
    Text *lineLoopText = Text::create("GL_LINE_LOOP", "Arial", 20);
    lineLoopText->setTextColor(Color4B::GREEN);
    lineLoopText->setPosition(Vec2(lineLoopCheckBox->getPosition().x+lineLoopCheckBox->getContentSize().width/2+lineLoopCheckBox->getContentSize().width, lineLoopCheckBox->getPosition().y));
    lineLoopText->setAnchorPoint(Vec2(0, 0.5));
    this->addChild(lineLoopText);


    pointsCheckBox->setSelected(true);
}

void HelloWorld::checkBoxSelectEvent(Ref* ref,CheckBox::EventType type)
{

    if (ref==nullptr) {
        return;
    }
    CheckBox * box=dynamic_cast<CheckBox *>(ref);
    CheckBox * box01=(CheckBox *)this->getChildByTag(1000);
    CheckBox * box02=(CheckBox *)this->getChildByTag(1001);
    CheckBox * box03=(CheckBox *)this->getChildByTag(1002);
    CheckBox * box04=(CheckBox *)this->getChildByTag(1003);
    
    if (type==CheckBox::EventType::UNSELECTED) {
        
        box->setSelected(true);
        return;
    }
    tag=box->getTag();
    if (box->getTag()==1000) {
        box->setSelected(true);
        box02->setSelected(false);
        box03->setSelected(false);
        box04->setSelected(false);
    }else if(box->getTag()==1001)
    {
        box->setSelected(true);
        box01->setSelected(false);
        box03->setSelected(false);
        box04->setSelected(false);
    }else if(box->getTag()==1002)
    {
        box->setSelected(true);
        box02->setSelected(false);
        box01->setSelected(false);
        box04->setSelected(false);
    }else if(box->getTag()==1003)
    {
        box->setSelected(true);
        box02->setSelected(false);
        box03->setSelected(false);
        box01->setSelected(false);
    }
    
}

