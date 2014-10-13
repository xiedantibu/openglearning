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

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    GLProgram *program=GLProgram::createWithFilenames("sample3.vert", "sample3.frag");//读取编译顶点着色器脚本内容以及片元着色器脚本内容,并且链接
//    setGLProgramState(GLProgramState::getOrCreateWithGLProgram(program));等价于setGLProgram
    setGLProgram(program);
    
    return true;
}

void HelloWorld::draw(Renderer *renderer, const Mat4 &transform, uint32_t flags)
{

    _customCommand.init(_globalZOrder);
    _customCommand.func = CC_CALLBACK_0(HelloWorld::onDraw, this, transform, flags);
    renderer->addCommand(&_customCommand);
}

void HelloWorld::onDraw(const Mat4 &transform, uint32_t flags)
{
    Director::getInstance()->pushMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_PROJECTION);
    Director::getInstance()->loadIdentityMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_PROJECTION);
    
    Mat4 matrixPerspective,matrixLookup,matrixTranslate;
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Mat4::createPerspective(60, (GLfloat)visibleSize.width/visibleSize.height, 1, 10, &matrixPerspective);
    Vec3 eye(0, 0, 3), center(0,0,0), up(0.0f, 1.0f, 0.0f);
    Mat4::createLookAt(eye, center, up, &matrixLookup);
    Director::getInstance()->multiplyMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_PROJECTION, matrixPerspective);
    Director::getInstance()->multiplyMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_PROJECTION, matrixLookup);

    matrixTranslate.translate(0, 0.5, -2);
    matrixTranslate.rotate(Vec3(1, 0, 0), CC_DEGREES_TO_RADIANS(xAngle++));
    
    auto glProgram = getGLProgram();
    glProgram->use();
    glProgram->setUniformsForBuiltins(matrixTranslate);
    float vertices[]={
        -1,0,0,
        0,-1,0,
        1,0,0
    };
    float colors[]={
        0,1,1,1,
        0.5,0.5f,1,0,
        1,1,0,0
    };
    
    glEnableVertexAttribArray(GLProgram::VERTEX_ATTRIB_POSITION);
    glVertexAttribPointer(GLProgram::VERTEX_ATTRIB_POSITION, 3, GL_FLOAT, GL_FALSE, 0, vertices);
    
    glEnableVertexAttribArray(GLProgram::VERTEX_ATTRIB_COLOR);
    glVertexAttribPointer(GLProgram::VERTEX_ATTRIB_COLOR, 4, GL_FLOAT, GL_FALSE, 0, colors);
    
    glDrawArrays(GL_TRIANGLES, 0, 3);
    CC_INCREMENT_GL_DRAWN_BATCHES_AND_VERTICES(1, 3);
    CHECK_GL_ERROR_DEBUG();
    
    Director::getInstance()->popMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_PROJECTION);
}
