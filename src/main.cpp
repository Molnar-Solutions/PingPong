#include "main.h"
#include "string" 
#include "window/window.h"
#include "glad.h"

#define GLCheck(x) GLClearAllErrors(); x; GLCheckErrorStatus(#x, __LINE__);

/* Error handling routines */
static void GLClearAllErrors() {
	while (glGetError() != GL_NO_ERROR) {}
}

static bool GLCheckErrorStatus(const char* function, int line) {
	while (GLenum error = glGetError()) {
		std::cout << "OpenGL Error: " << error
			<< "\tLine: " << line
			<< "\tFunction: " << function << std::endl;
		return true;
	}

	return false;
}

using namespace std;

int main()
{
	WindowManager wm("PingPong");
	wm.init();
	wm.game();

	return 0;
}
