//
//  SixPointedStar.cpp
//  openglearning
//
//  Created by agile on 14-10-13.
//
//

#include "Cube.h"
#include "Constant.h"
bool Cube::init()
{

    return true;
}
Cube::Cube()
{

    if ( !Node::init() )
    {
        return ;
    }
    
    GLProgram *program=GLProgram::createWithFilenames("sample5_3.vert", "sample5_3.frag");//读取编译顶点着色器脚本内容以及片元着色器脚本内容,并且链接
    //    setGLProgramState(GLProgramState::getOrCreateWithGLProgram(program));等价于setGLProgram
    setGLProgram(program);

}
void Cube::draw(Renderer *renderer, const Mat4 &transform, uint32_t flags)
{

    _customCommand.init(_globalZOrder);
    _customCommand.func = CC_CALLBACK_0(Cube::onDraw, this, transform, flags);
    renderer->addCommand(&_customCommand);

    
}

void Cube::onDraw(const Mat4 &transform, uint32_t flags)
{
    float vertices[]=
    {
        //前面
        0,0,UNIT_SIZE,
        UNIT_SIZE,UNIT_SIZE,UNIT_SIZE,
        -UNIT_SIZE,UNIT_SIZE, UNIT_SIZE,
        0,0, UNIT_SIZE,
        - UNIT_SIZE, UNIT_SIZE, UNIT_SIZE,
        - UNIT_SIZE,- UNIT_SIZE, UNIT_SIZE,
        0,0, UNIT_SIZE,
        - UNIT_SIZE,- UNIT_SIZE, UNIT_SIZE,
        UNIT_SIZE,- UNIT_SIZE, UNIT_SIZE,
        0,0, UNIT_SIZE,
        UNIT_SIZE,- UNIT_SIZE, UNIT_SIZE,
        UNIT_SIZE, UNIT_SIZE, UNIT_SIZE,
        //后面
        0,0,- UNIT_SIZE,
        UNIT_SIZE, UNIT_SIZE,- UNIT_SIZE,
        UNIT_SIZE,- UNIT_SIZE,- UNIT_SIZE,
        0,0,- UNIT_SIZE,
        UNIT_SIZE,- UNIT_SIZE,- UNIT_SIZE,
        - UNIT_SIZE,- UNIT_SIZE,- UNIT_SIZE,
        0,0,- UNIT_SIZE,
        - UNIT_SIZE,- UNIT_SIZE,- UNIT_SIZE,
        - UNIT_SIZE, UNIT_SIZE,- UNIT_SIZE,
        0,0,- UNIT_SIZE,
        - UNIT_SIZE, UNIT_SIZE,- UNIT_SIZE,
        UNIT_SIZE, UNIT_SIZE,- UNIT_SIZE,
        //左面
        - UNIT_SIZE,0,0,
        - UNIT_SIZE, UNIT_SIZE, UNIT_SIZE,
        - UNIT_SIZE, UNIT_SIZE,- UNIT_SIZE,
        - UNIT_SIZE,0,0,
        - UNIT_SIZE, UNIT_SIZE,- UNIT_SIZE,
        - UNIT_SIZE,- UNIT_SIZE,- UNIT_SIZE,
        - UNIT_SIZE,0,0,
        - UNIT_SIZE,- UNIT_SIZE,- UNIT_SIZE,
        - UNIT_SIZE,- UNIT_SIZE, UNIT_SIZE,
        - UNIT_SIZE,0,0,
        - UNIT_SIZE,- UNIT_SIZE, UNIT_SIZE,
        - UNIT_SIZE, UNIT_SIZE, UNIT_SIZE,
        //右面
        UNIT_SIZE,0,0,
        UNIT_SIZE, UNIT_SIZE, UNIT_SIZE,
        UNIT_SIZE,- UNIT_SIZE, UNIT_SIZE,
        UNIT_SIZE,0,0,
        UNIT_SIZE,- UNIT_SIZE, UNIT_SIZE,
        UNIT_SIZE,- UNIT_SIZE,- UNIT_SIZE,
        UNIT_SIZE,0,0,
        UNIT_SIZE,- UNIT_SIZE,- UNIT_SIZE,
        UNIT_SIZE, UNIT_SIZE,- UNIT_SIZE,
        UNIT_SIZE,0,0,
        UNIT_SIZE, UNIT_SIZE,- UNIT_SIZE,
        UNIT_SIZE, UNIT_SIZE, UNIT_SIZE,
        //上面
        0, UNIT_SIZE,0,
        UNIT_SIZE, UNIT_SIZE, UNIT_SIZE,
        UNIT_SIZE, UNIT_SIZE,- UNIT_SIZE,
        0, UNIT_SIZE,0,
        UNIT_SIZE, UNIT_SIZE,- UNIT_SIZE,
        - UNIT_SIZE, UNIT_SIZE,- UNIT_SIZE,
        0, UNIT_SIZE,0,
        - UNIT_SIZE, UNIT_SIZE,- UNIT_SIZE,
        - UNIT_SIZE, UNIT_SIZE, UNIT_SIZE,
        0, UNIT_SIZE,0,
        - UNIT_SIZE, UNIT_SIZE, UNIT_SIZE,
        UNIT_SIZE, UNIT_SIZE, UNIT_SIZE,
        //下面
        0,- UNIT_SIZE,0,
        UNIT_SIZE,- UNIT_SIZE, UNIT_SIZE,
        - UNIT_SIZE,- UNIT_SIZE, UNIT_SIZE,
        0,- UNIT_SIZE,0,
        - UNIT_SIZE,- UNIT_SIZE, UNIT_SIZE,
        - UNIT_SIZE,- UNIT_SIZE,- UNIT_SIZE,
        0,- UNIT_SIZE,0,
        - UNIT_SIZE,- UNIT_SIZE,- UNIT_SIZE,
        UNIT_SIZE,- UNIT_SIZE,- UNIT_SIZE,
        0,- UNIT_SIZE,0,
        UNIT_SIZE,- UNIT_SIZE,- UNIT_SIZE,
        UNIT_SIZE,- UNIT_SIZE, UNIT_SIZE,
    };
    
    //顶点颜色值数组，每个顶点4个色彩值RGBA
    float colors[]={
        //前面
        1,1,1,0,//中间为白色
        1,0,0,0,
        1,0,0,0,
        1,1,1,0,//中间为白色
        1,0,0,0,
        1,0,0,0,
        1,1,1,0,//中间为白色
        1,0,0,0,
        1,0,0,0,
        1,1,1,0,//中间为白色
        1,0,0,0,
        1,0,0,0,
        //后面
        1,1,1,0,//中间为白色
        0,0,1,0,
        0,0,1,0,
        1,1,1,0,//中间为白色
        0,0,1,0,
        0,0,1,0,
        1,1,1,0,//中间为白色
        0,0,1,0,
        0,0,1,0,
        1,1,1,0,//中间为白色
        0,0,1,0,
        0,0,1,0,
        //左面
        1,1,1,0,//中间为白色
        1,0,1,0,
        1,0,1,0,
        1,1,1,0,//中间为白色
        1,0,1,0,
        1,0,1,0,
        1,1,1,0,//中间为白色
        1,0,1,0,
        1,0,1,0,
        1,1,1,0,//中间为白色
        1,0,1,0,
        1,0,1,0,
        //右面
        1,1,1,0,//中间为白色
        1,1,0,0,
        1,1,0,0,
        1,1,1,0,//中间为白色
        1,1,0,0,
        1,1,0,0,
        1,1,1,0,//中间为白色
        1,1,0,0,
        1,1,0,0,
        1,1,1,0,//中间为白色
        1,1,0,0,
        1,1,0,0,
        //上面
        1,1,1,0,//中间为白色
        0,1,0,0,
        0,1,0,0,
        1,1,1,0,//中间为白色
        0,1,0,0,
        0,1,0,0,
        1,1,1,0,//中间为白色
        0,1,0,0,
        0,1,0,0,
        1,1,1,0,//中间为白色
        0,1,0,0,
        0,1,0,0,
        //下面
        1,1,1,0,//中间为白色
        0,1,1,0,
        0,1,1,0,
        1,1,1,0,//中间为白色
        0,1,1,0,
        0,1,1,0,
        1,1,1,0,//中间为白色
        0,1,1,0,
        0,1,1,0,
        1,1,1,0,//中间为白色
        0,1,1,0,
        0,1,1,0,
    };


    glEnable(GL_DEPTH_TEST);//打开深度测试
    glEnable(GL_CULL_FACE);//打开背面剪切
    Director::getInstance()->pushMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_PROJECTION);
    Director::getInstance()->loadIdentityMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_PROJECTION);
    Mat4 matrixPerspective,matrixTranslate,matrixLookup;
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Mat4::createPerspective(60, (GLfloat)visibleSize.width/visibleSize.height, 1, 20, &matrixPerspective);
    Director::getInstance()->multiplyMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_PROJECTION, matrixPerspective);
    
    Vec3 eye(16,8,-4), center(0, 0, 0.0f), up(0.0f, 1.0f, 0.0f);
    Mat4::createLookAt(eye, center, up, &matrixLookup);
    Director::getInstance()->multiplyMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_PROJECTION, matrixLookup);
    matrixTranslate.translate(10, 4, 0);
    matrixTranslate.scale(2, 2, 2);
    matrixTranslate.rotate(Vec3(1, 1, 0), CC_DEGREES_TO_RADIANS(20));
    
    auto glProgram = getGLProgram();
    glProgram->use();
    glProgram->setUniformsForBuiltins(matrixTranslate);
    
    glEnableVertexAttribArray(GLProgram::VERTEX_ATTRIB_POSITION);
    glVertexAttribPointer(GLProgram::VERTEX_ATTRIB_POSITION, 3, GL_FLOAT, GL_FALSE, 0, vertices);
    glEnableVertexAttribArray(GLProgram::VERTEX_ATTRIB_COLOR);
    glVertexAttribPointer(GLProgram::VERTEX_ATTRIB_COLOR, 4, GL_FLOAT, GL_FALSE, 0, colors);
    
    glDrawArrays(GL_TRIANGLES, 0, 72);
    CC_INCREMENT_GL_DRAWN_BATCHES_AND_VERTICES(1, 72);
    CHECK_GL_ERROR_DEBUG();

    
    Director::getInstance()->popMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_PROJECTION);
 
    
    glDisable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
}
