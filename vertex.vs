#version 330 core

attribute vec4 VertexCoordinates;
attribute vec2 TexCoordinates;

uniform mat4 View;
uniform mat4 Transform;
uniform mat4 Projection;

varying vec2 texCoordinates;

void main()
{
    gl_Position = Transform * VertexCoordinates;
    texCoordinates = TexCoordinates;
}
