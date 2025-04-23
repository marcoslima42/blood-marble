#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <cassert>


using namespace std;

const int Width = 800;
const int Height = 600;

int main() {
	// imprimi se for false o retorno ao iniciar o glfw
	// inicializa a bilbioteca GLFW
	assert(glfwInit() == GLFW_TRUE);

	// Criar uma janela
	GLFWwindow* Window = glfwCreateWindow(Width, Height, "Blood Marble", nullptr, nullptr);
	assert(Window);
	// Ativa contexto criado na janela Window
	glfwMakeContextCurrent(Window);

	// Inicializa a lib GLEW
	assert(glewInit() == GLEW_OK);

	//verificar vers�o do OpenGL
	GLint GLMajorVersion = 0;
	GLint GLMinorVersion = 0;
	glGetIntegerv(GL_MAJOR_VERSION, &GLMajorVersion);
	glGetIntegerv(GL_MINOR_VERSION, &GLMinorVersion);
	//Entra no loop de eventos da aplicacao
	cout << "OpenGL Version  : " << GLMajorVersion << "." << GLMinorVersion << endl;
	
	// Usar o glGetString() para obter informacoes do driver que estamos usando
	cout << "OpenGL Vendor   : " << glGetString(GL_VENDOR) << endl;
	cout << "OpenGL Renderer : " << glGetString(GL_RENDERER) << endl;
	cout << "OpenGL Version  : " << glGetString(GL_VERSION) << endl;
	cout << "GLSL VERSION    : " << glGetString(GL_SHADING_LANGUAGE_VERSION) << endl;
	

	// Definir a cor de fundo 
	glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
	
	while (!glfwWindowShouldClose(Window))
	{
		// limap o framebuffer.
		glClear(GL_COLOR_BUFFER_BIT);
		
		// Processa todos os eventos da fila de eventos do GLFW
		// Eventos podem ser eventos do teclado, mouse, gamepad
		glfwPollEvents();

		// Envia o conteudo do framebuffer da janela para ser desenhado na tela
		glfwSwapBuffers(Window);
	}



	// Encerrar a biblioteca GLFW
	glfwTerminate();
	return 0;
}