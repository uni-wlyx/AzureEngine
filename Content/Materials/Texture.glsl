#type vertex

#version 450 core

layout(location=0)in vec3 aPos;
layout(location=1)in vec2 a_TexCoord;

uniform mat4 u_Transform;;
uniform mat4 u_ViewProjection;

out vec2 vTexCoord;

void main()
{
    vTexCoord=a_TexCoord;
    gl_Position=u_ViewProjection*u_Transform*vec4(aPos.x,aPos.y,aPos.z,1.);
};

#type fragment
#version 450 core

out vec4 FragColor;

in vec2 vTexCoord;

uniform sampler2D uTexture;

void main()
{
    FragColor=texture(uTexture,vTexCoord);
};