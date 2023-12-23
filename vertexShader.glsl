attribute highp vec4 posAttr;
attribute lowp vec4 colAttr;
varying lowp vec4 col;
uniform highp mat4 matrix;
void main() {
	col = colAttr;
	    vec4 translatedPosition = posAttr + vec4(10.0, 10.0, 0.0, 0.0);
 
	gl_Position = matrix * translatedPosition;
}