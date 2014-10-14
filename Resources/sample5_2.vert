attribute vec3 a_position;//顶点位置
attribute vec4 a_color;//顶点颜色
varying vec4 vColor;//传递给片元着色器的变量

void main()
{
    gl_Position=CC_MVPMatrix * vec4(a_position,1);
    vColor=a_color;
}