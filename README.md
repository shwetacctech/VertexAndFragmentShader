# GLSL Vertex Shader Example

This repository contains an example of a GLSL vertex shader written in the OpenGL Shading Language (GLSL).

## Description

The provided GLSL code represents a basic vertex shader. It includes attributes, varying variables, a uniform matrix, and the main function responsible for transforming vertices.

### Code Explanation

The vertex shader code performs the following tasks:
- Takes input attributes `posAttr` and `colAttr`.
- Assigns the color attribute `col` to be used as a varying variable.
- Uses a uniform matrix `matrix` to transform the vertex position.
- Translates the input position (`posAttr`) by adding a vector (`vec4(10.0, 10.0, 0.0, 0.0)`) to it.

### Code Snippet

```glsl
attribute highp vec4 posAttr;
attribute lowp vec4 colAttr;
varying lowp vec4 col;
uniform highp mat4 matrix;

void main() {
    col = colAttr;
    vec4 translatedPosition = posAttr + vec4(10.0, 10.0, 0.0, 0.0);
    gl_Position = matrix * translatedPosition;
}
```
![image](https://github.com/shwetacctech/VertexAndFragmentShader/assets/149310316/7da91091-273b-4ebe-b078-0563737ae199)
