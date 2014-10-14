//
//  SixPointedStar.h
//  openglearning
//
//  Created by agile on 14-10-13.
//
//

#ifndef __openglearning__SixPointedStar__
#define __openglearning__SixPointedStar__

#include "cocos2d.h"

USING_NS_CC;

class SixPointedStar : public Node
{
public:
    virtual bool init();
    virtual void draw(Renderer *renderer, const Mat4 &transform, uint32_t flags) override;
    void onDraw(const Mat4 &transform, uint32_t flags);
    SixPointedStar();
    SixPointedStar(float r,float R,float z);
    void initVertexData(float r,float R,float z);
    
public:
    CustomCommand _customCommand;
    float xAngle={0};
    float yAngle={0};
    float vertices[36*3];
    float colors[36*3*4];
    float r,R,z;
    
    
    
};
#endif /* defined(__openglearning__SixPointedStar__) */
