//
//  SixPointedStar.cpp
//  openglearning
//
//  Created by agile on 14-10-13.
//
//

#include "SixPointedStar.h"

bool SixPointedStar::init()
{

    return true;
}
SixPointedStar::SixPointedStar(float r,float R,float z)
{
    this->r=r;
    this->R=R;
    this->z=z;
    
    if ( !Node::init() )
    {
        return ;
    }
    
    GLProgram *program=GLProgram::createWithFilenames("sample5_1.vert", "sample5_1.frag");//读取编译顶点着色器脚本内容以及片元着色器脚本内容,并且链接
    //    setGLProgramState(GLProgramState::getOrCreateWithGLProgram(program));等价于setGLProgram
    setGLProgram(program);
    
    initVertexData(r,R,z);
}
SixPointedStar::SixPointedStar():r(0.5),R(1),z(0)
{

    SixPointedStar(0.5,1,0);
}
void SixPointedStar::draw(Renderer *renderer, const Mat4 &transform, uint32_t flags)
{

    _customCommand.init(_globalZOrder);
    _customCommand.func = CC_CALLBACK_0(SixPointedStar::onDraw, this, transform, flags);
    renderer->addCommand(&_customCommand);

    
}

void SixPointedStar::onDraw(const Mat4 &transform, uint32_t flags)
{

    glEnable(GL_DEPTH_TEST);//打开深度测试
    glEnable(GL_CULL_FACE);//打开背面剪切
    Director::getInstance()->pushMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_PROJECTION);
    Director::getInstance()->loadIdentityMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_PROJECTION);
    Mat4 matrixPerspective,matrixLookup,matrixTranslate;
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Mat4::createPerspective(60, (GLfloat)visibleSize.width/visibleSize.height, 1, 10, &matrixPerspective);
    Vec3 eye(0, 0, 3), center(0,0,0), up(0.0f, 1.0f, 0.0f);
    Mat4::createLookAt(eye, center, up, &matrixLookup);
    Director::getInstance()->multiplyMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_PROJECTION, matrixPerspective);
    Director::getInstance()->multiplyMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_PROJECTION, matrixLookup);
    
    matrixTranslate.translate(0, 0, 0);
    matrixTranslate.rotate(Vec3(1, 0, 0), CC_DEGREES_TO_RADIANS(xAngle));
    matrixTranslate.rotate(Vec3(0, 1, 0), CC_DEGREES_TO_RADIANS(yAngle));
    
    
    auto glProgram = getGLProgram();
    glProgram->use();
    glProgram->setUniformsForBuiltins(matrixTranslate);
    
    glEnableVertexAttribArray(GLProgram::VERTEX_ATTRIB_POSITION);
    glVertexAttribPointer(GLProgram::VERTEX_ATTRIB_POSITION, 3, GL_FLOAT, GL_FALSE, 0, vertices);
    
    glEnableVertexAttribArray(GLProgram::VERTEX_ATTRIB_COLOR);
    glVertexAttribPointer(GLProgram::VERTEX_ATTRIB_COLOR, 4, GL_FLOAT, GL_FALSE, 0, colors);
    
    glDrawArrays(GL_TRIANGLES, 0, 36);
    CC_INCREMENT_GL_DRAWN_BATCHES_AND_VERTICES(1, 36);
    CHECK_GL_ERROR_DEBUG();

    
    Director::getInstance()->popMatrix(MATRIX_STACK_TYPE::MATRIX_STACK_PROJECTION);
 
    
    glDisable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
}

void SixPointedStar::initVertexData(float r,float R,float z)
{

    float tempAngle=360/6;
    for (float angle=0; angle<360; angle+=tempAngle) {
    
        int i=angle/60;
        
        vertices[i*18]=0;
        vertices[i*18+1]=0;
        vertices[i*18+2]=z;
        
        vertices[i*18+3]=(float)(R*cosf(CC_DEGREES_TO_RADIANS(angle)));
        vertices[i*18+4]=(float)(R*sinf(CC_DEGREES_TO_RADIANS(angle)));
        vertices[i*18+5]=z;
        

        vertices[i*18+6]=(float)(r*cosf(CC_DEGREES_TO_RADIANS(angle+tempAngle/2)));
        vertices[i*18+7]=(float)(r*sinf(CC_DEGREES_TO_RADIANS(angle+tempAngle/2)));
        vertices[i*18+8]=z;

        
        vertices[i*18+9]=0;
        vertices[i*18+10]=0;
        vertices[i*18+11]=z;

        vertices[i*18+12]=(float)(r*cosf(CC_DEGREES_TO_RADIANS(angle+tempAngle/2)));
        vertices[i*18+13]=(float)(r*sinf(CC_DEGREES_TO_RADIANS(angle+tempAngle/2)));
        vertices[i*18+14]=z;
        
        vertices[i*18+15]=(float)(R*cosf(CC_DEGREES_TO_RADIANS(angle+tempAngle)));
        vertices[i*18+16]=(float)(R*sinf(CC_DEGREES_TO_RADIANS(angle+tempAngle)));
        vertices[i*18+17]=z;
        
    }

    for(int i=0;i<108;i++)
    {
        if(i%3==0){//中心点为白色
            colors[i*4]=1;
            colors[i*4+1]=1;
            colors[i*4+2]=1;
            colors[i*4+3]=0;
        }
        else{//边上的点为淡蓝色
            colors[i*4]=0.45f;
            colors[i*4+1]=0.75f;
            colors[i*4+2]=0.75f;
            colors[i*4+3]=0;
        }
    }
    
}