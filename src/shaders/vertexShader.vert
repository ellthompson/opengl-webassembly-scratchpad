attribute vec3 position;
uniform mat4 MVP;

void main()
{
  gl_Position = MVP * vec4(position.x, position.y, position.z, 1.0);
  gl_Position[2] = 1.0;
}
