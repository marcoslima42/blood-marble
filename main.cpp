#include <iostream>
#include <GLFW/glfw3.h>
#include <cassert>
using namespace std;

const int Width = 800;
const int Height = 600;

int main() {
	// imprimi se for false o retorno ao iniciar o glfw
	// inicializa a bilbioteca GLFW
	assert(glfwInit());

	// Criar uma janela
	GLFWwindow* Window = glfwCreateWindow(Width, Height, "Blood Marble", nullptr, nullptr);
	assert(Window);

	//Entra no loop de eventos da aplicacao
	while (!glfwWindowShouldClose(Window))
	{
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