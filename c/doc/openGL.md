# Open GL

## Install

- `sudo apt update`

```bash
sudo apt install -y \
  libglu1-mesa-dev  \
  freeglut3-dev \
  mesa-common-dev
```

## Installation check

### C source

```c
#include <GL/glut.h>

// http://www.codebind.com/linux-tutorials/install-opengl-ubuntu-linux/
// gcc -o test-gl gl.c -lglut -lGLU -lGL
// ./test-gl

void display_me(void) {
  glClear(GL_COLOR_BUFFER_BIT);
  glBegin(GL_POLYGON);
  glVertex3f(0.5, 0.0, 0.5);
  glVertex3f(0.5, 0.0, 0.0);
  glVertex3f(0.0, 0.5, 0.0);
  glVertex3f(0.0, 0.0, 0.5);
  glEnd();
  glFlush();
}

int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE);
  glutInitWindowSize(400, 300);
  glutInitWindowPosition(100, 100);
  glutCreateWindow("Hello world!");
  glutDisplayFunc(display_me);
  glutMainLoop();

  return 0;
}
```

### Compilation

- `gcc -o test-gl gl.c -lglut -lGLU -lGL`

### Running

- `./test-gl`

## Biblio

- [codebind installation](http://www.codebind.com/linux-tutorials/install-opengl-ubuntu-linux/)
- [medium plimsky](https://medium.com/@Plimsky/how-to-install-a-opengl-environment-on-ubuntu-e3918cf5ab6c)
